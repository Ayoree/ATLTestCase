// BinaryFile.cpp : Implementation of CBinaryFile

#include "pch.h"
#include "BinaryFile.h"


// CBinaryFile

STDMETHODIMP CBinaryFile::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_IBinaryFile
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CBinaryFile::get_targetFilePath(BSTR* pVal)
{
	*pVal = targetFilePath;
	return S_OK;
}


STDMETHODIMP CBinaryFile::put_targetFilePath(BSTR newVal)
{
	targetFilePath = newVal;
	return S_OK;
}


STDMETHODIMP CBinaryFile::get_sortedFilePath(BSTR* pVal)
{
	*pVal = sortedFilePath;
	return S_OK;
}


STDMETHODIMP CBinaryFile::put_sortedFilePath(BSTR newVal)
{
	sortedFilePath = newVal;
	return S_OK;
}


STDMETHODIMP CBinaryFile::SortFile(VARIANT_BOOL sortGreater)
{

    if (sortedFilePath == nullptr || SysStringLen(sortedFilePath) == 0) sortedFilePath = L"sorted.bin";

    wprintf(L"Sorting file \"%s\"...\n", this->targetFilePath);
    std::ifstream inputFile(targetFilePath, std::ios::binary);
    if (!inputFile.is_open()) {
        Error(L"Failed to open input file.");
        return E_FAIL;
    }

    std::ofstream copyFile(sortedFilePath, std::ios::binary);
    if (!copyFile.is_open()) {
        Error(L"Failed to create output file.");
        inputFile.close();
        return E_FAIL;
    }

    copyFile << inputFile.rdbuf();  // Copy the content

    inputFile.close();
    copyFile.close();

    std::fstream sortedCopyFile(sortedFilePath, std::ios::binary | std::ios::in | std::ios::out);
    if (!sortedCopyFile.is_open()) {
        Error(L"Failed to open output file.");
        return E_FAIL;
    }

    // Determine the size of the sorted copy file
    sortedCopyFile.seekg(0, std::ios::end);
    std::streamsize fileSize = sortedCopyFile.tellg();
    sortedCopyFile.seekg(0, std::ios::beg);
    sortedCopyFile.close();

    bip::file_mapping mapping(sortedFilePath, bip::read_write);
    bip::mapped_region region(mapping, bip::read_write);

    uint32_t* sortedCopyData = static_cast<uint32_t*>(region.get_address());
    size_t numElements = static_cast<size_t>(fileSize) / sizeof(uint32_t);
        
    // Sort the data right in the file
    if (sortGreater) std::sort(std::execution::par_unseq, sortedCopyData, sortedCopyData + numElements, std::greater()); // execution::par_unseq for parallel sorting
    else std::sort(std::execution::par_unseq, sortedCopyData, sortedCopyData + numElements); // execution::par_unseq for parallel sorting
        
    wprintf(L"File sorted successfully. Saved as \"%s\".\n", sortedFilePath);

    return S_OK;
}
