#include "pch.h"

#import "ATLServer.tlb" named_guids no_namespace

namespace fs = std::filesystem;

const size_t maxConcurrentFunctions = 4; // Maximum files to parallel sorting

void worker(IBinaryFilePtr pBinFile, std::counting_semaphore<>& semaphore) {
    semaphore.acquire(); // Wait for access to the function
    pBinFile->SortFile();
    semaphore.release(); // Release access
}

int main()
{
    std::wstring toSortDirectoryPath, sortedDirectoryPath;

    wprintf(L"Print directory to sort (exapmle \"D:\\Downloads\\Files\\ToSort\": ");
    std::wcin >> toSortDirectoryPath;
    wprintf(L"Print directory to save sorted files: ");
    std::wcin >> sortedDirectoryPath;

    std::unordered_map<std::wstring, std::wstring> filePaths;

    if (fs::exists(toSortDirectoryPath) && fs::is_directory(toSortDirectoryPath)) {
        for (const auto& entry : fs::directory_iterator(toSortDirectoryPath)) {
            if (entry.is_regular_file()) {
                fs::path filePath = entry.path();
                std::wstring inFilePath = filePath.wstring();
                std::wstring outFilePath = sortedDirectoryPath + L"\\" + filePath.filename().wstring();
                filePaths[inFilePath] = outFilePath;
            }
        }
    }
    else {
        std::wcerr << toSortDirectoryPath << L" is not a directory." << std::endl;
        return 1;
    }

    HRESULT hr = CoInitialize(NULL);
    {
        try
        {
            std::vector<IBinaryFilePtr > files;
            for (auto pairPaths : filePaths) {
                IBinaryFilePtr pBinFile;
                pBinFile.CreateInstance(__uuidof(BinaryFile));
                BSTR targetFilePath = SysAllocString(pairPaths.first.c_str());
                BSTR sortedFilePath = SysAllocString(pairPaths.second.c_str());

                pBinFile->put_targetFilePath(targetFilePath);
                pBinFile->put_sortedFilePath(sortedFilePath);
                files.push_back(pBinFile);
            }
                                                                         
            wprintf(L"Sorting files in \"%s\"...\n", toSortDirectoryPath.c_str());
            
            std::vector<boost::thread> threads;
            std::counting_semaphore<> semaphore(maxConcurrentFunctions); // Initialize the counting semaphore
            
            auto startTime = std::chrono::high_resolution_clock::now();
            
            // Create and launch threads
            for (IBinaryFilePtr file : files) {
                threads.emplace_back(worker, file, std::ref(semaphore));
            }

            for (boost::thread& thread : threads) {
                thread.join();
            }
            
            auto endTime = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
            
            wprintf(L"Sorting time: %llu ms.\n", duration.count());
        }
        catch (_com_error e)
        {
            std::wcout << e.Description() << std::endl;
        }
    }
    CoUninitialize();
    return 0;
}