

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 10:14:07 2038
 */
/* Compiler settings for ATLServer.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ATLServer_i_h__
#define __ATLServer_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IBinaryFile_FWD_DEFINED__
#define __IBinaryFile_FWD_DEFINED__
typedef interface IBinaryFile IBinaryFile;

#endif 	/* __IBinaryFile_FWD_DEFINED__ */


#ifndef ___IBinaryFileEvents_FWD_DEFINED__
#define ___IBinaryFileEvents_FWD_DEFINED__
typedef interface _IBinaryFileEvents _IBinaryFileEvents;

#endif 	/* ___IBinaryFileEvents_FWD_DEFINED__ */


#ifndef __BinaryFile_FWD_DEFINED__
#define __BinaryFile_FWD_DEFINED__

#ifdef __cplusplus
typedef class BinaryFile BinaryFile;
#else
typedef struct BinaryFile BinaryFile;
#endif /* __cplusplus */

#endif 	/* __BinaryFile_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IBinaryFile_INTERFACE_DEFINED__
#define __IBinaryFile_INTERFACE_DEFINED__

/* interface IBinaryFile */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IBinaryFile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("708dc3e8-12ab-4fc3-ba12-b37e77d445af")
    IBinaryFile : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_targetFilePath( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_targetFilePath( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_sortedFilePath( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_sortedFilePath( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SortFile( 
            /* [in] */ VARIANT_BOOL sortGreater) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBinaryFileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBinaryFile * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBinaryFile * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBinaryFile * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBinaryFile * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBinaryFile * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBinaryFile * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBinaryFile * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_targetFilePath )( 
            IBinaryFile * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_targetFilePath )( 
            IBinaryFile * This,
            /* [in] */ BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_sortedFilePath )( 
            IBinaryFile * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_sortedFilePath )( 
            IBinaryFile * This,
            /* [in] */ BSTR newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SortFile )( 
            IBinaryFile * This,
            /* [in] */ VARIANT_BOOL sortGreater);
        
        END_INTERFACE
    } IBinaryFileVtbl;

    interface IBinaryFile
    {
        CONST_VTBL struct IBinaryFileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBinaryFile_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBinaryFile_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBinaryFile_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBinaryFile_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IBinaryFile_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IBinaryFile_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IBinaryFile_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IBinaryFile_get_targetFilePath(This,pVal)	\
    ( (This)->lpVtbl -> get_targetFilePath(This,pVal) ) 

#define IBinaryFile_put_targetFilePath(This,newVal)	\
    ( (This)->lpVtbl -> put_targetFilePath(This,newVal) ) 

#define IBinaryFile_get_sortedFilePath(This,pVal)	\
    ( (This)->lpVtbl -> get_sortedFilePath(This,pVal) ) 

#define IBinaryFile_put_sortedFilePath(This,newVal)	\
    ( (This)->lpVtbl -> put_sortedFilePath(This,newVal) ) 

#define IBinaryFile_SortFile(This,sortGreater)	\
    ( (This)->lpVtbl -> SortFile(This,sortGreater) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBinaryFile_INTERFACE_DEFINED__ */



#ifndef __ATLServerLib_LIBRARY_DEFINED__
#define __ATLServerLib_LIBRARY_DEFINED__

/* library ATLServerLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ATLServerLib;

#ifndef ___IBinaryFileEvents_DISPINTERFACE_DEFINED__
#define ___IBinaryFileEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IBinaryFileEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IBinaryFileEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("a94808cc-4181-4185-8dec-748734db5f48")
    _IBinaryFileEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IBinaryFileEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IBinaryFileEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IBinaryFileEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IBinaryFileEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IBinaryFileEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IBinaryFileEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IBinaryFileEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IBinaryFileEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IBinaryFileEventsVtbl;

    interface _IBinaryFileEvents
    {
        CONST_VTBL struct _IBinaryFileEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IBinaryFileEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IBinaryFileEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IBinaryFileEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IBinaryFileEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IBinaryFileEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IBinaryFileEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IBinaryFileEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IBinaryFileEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_BinaryFile;

#ifdef __cplusplus

class DECLSPEC_UUID("f2dbbe18-fe54-463e-be3c-d83a18df0096")
BinaryFile;
#endif
#endif /* __ATLServerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


