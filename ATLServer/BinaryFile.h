// BinaryFile.h : Declaration of the CBinaryFile

#pragma once
#include "resource.h"       // main symbols



#include "ATLServer_i.h"
#include "_IBinaryFileEvents_CP.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CBinaryFile

class ATL_NO_VTABLE CBinaryFile :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CBinaryFile, &CLSID_BinaryFile>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CBinaryFile>,
	public CProxy_IBinaryFileEvents<CBinaryFile>,
	public IDispatchImpl<IBinaryFile, &IID_IBinaryFile, &LIBID_ATLServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	BSTR targetFilePath;
	BSTR sortedFilePath;

public:
	CBinaryFile()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CBinaryFile)
	COM_INTERFACE_ENTRY(IBinaryFile)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CBinaryFile)
	CONNECTION_POINT_ENTRY(__uuidof(_IBinaryFileEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(get_targetFilePath)(BSTR* pVal);
	STDMETHOD(put_targetFilePath)(BSTR newVal);
	STDMETHOD(get_sortedFilePath)(BSTR* pVal);
	STDMETHOD(put_sortedFilePath)(BSTR newVal);
	STDMETHOD(SortFile)(VARIANT_BOOL sortGreater);
};

OBJECT_ENTRY_AUTO(__uuidof(BinaryFile), CBinaryFile)
