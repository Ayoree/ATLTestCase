// dllmain.h : Declaration of module class.

class CATLServerModule : public ATL::CAtlDllModuleT< CATLServerModule >
{
public :
	DECLARE_LIBID(LIBID_ATLServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLSERVER, "{ee850f0f-d8c4-4f9c-b773-0a2beaafcde8}")
};

extern class CATLServerModule _AtlModule;
