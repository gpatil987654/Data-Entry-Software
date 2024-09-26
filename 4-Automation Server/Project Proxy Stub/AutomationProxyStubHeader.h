

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 08:44:07 2038
 */
/* Compiler settings for AutomationServerProjectTypeLib.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
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

#ifndef __AutomationProxyStubHeader_h__
#define __AutomationProxyStubHeader_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IWriteToFileAutomation_FWD_DEFINED__
#define __IWriteToFileAutomation_FWD_DEFINED__
typedef interface IWriteToFileAutomation IWriteToFileAutomation;

#endif 	/* __IWriteToFileAutomation_FWD_DEFINED__ */


#ifndef __CWriteToFileAutomation_FWD_DEFINED__
#define __CWriteToFileAutomation_FWD_DEFINED__

#ifdef __cplusplus
typedef class CWriteToFileAutomation CWriteToFileAutomation;
#else
typedef struct CWriteToFileAutomation CWriteToFileAutomation;
#endif /* __cplusplus */

#endif 	/* __CWriteToFileAutomation_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IWriteToFileAutomation_INTERFACE_DEFINED__
#define __IWriteToFileAutomation_INTERFACE_DEFINED__

/* interface IWriteToFileAutomation */
/* [oleautomation][dual][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWriteToFileAutomation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E79B1EF0-03F6-4490-AC60-6EBC286D9754")
    IWriteToFileAutomation : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE WriteDataToFileAutomation( 
            /* [in] */ BSTR __MIDL__IWriteToFileAutomation0000,
            /* [in] */ BSTR __MIDL__IWriteToFileAutomation0001,
            /* [in] */ BSTR __MIDL__IWriteToFileAutomation0002,
            /* [in] */ BSTR __MIDL__IWriteToFileAutomation0003,
            /* [in] */ BSTR __MIDL__IWriteToFileAutomation0004,
            /* [in] */ BSTR __MIDL__IWriteToFileAutomation0005) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadDataFromFileAutomation( 
            /* [in] */ HWND __MIDL__IWriteToFileAutomation0006,
            /* [in] */ unsigned char *__MIDL__IWriteToFileAutomation0007,
            /* [in] */ int *__MIDL__IWriteToFileAutomation0008) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWriteToFileAutomationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWriteToFileAutomation * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWriteToFileAutomation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWriteToFileAutomation * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWriteToFileAutomation * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWriteToFileAutomation * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWriteToFileAutomation * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWriteToFileAutomation * This,
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
        
        HRESULT ( STDMETHODCALLTYPE *WriteDataToFileAutomation )( 
            IWriteToFileAutomation * This,
            /* [in] */ BSTR __MIDL__IWriteToFileAutomation0000,
            /* [in] */ BSTR __MIDL__IWriteToFileAutomation0001,
            /* [in] */ BSTR __MIDL__IWriteToFileAutomation0002,
            /* [in] */ BSTR __MIDL__IWriteToFileAutomation0003,
            /* [in] */ BSTR __MIDL__IWriteToFileAutomation0004,
            /* [in] */ BSTR __MIDL__IWriteToFileAutomation0005);
        
        HRESULT ( STDMETHODCALLTYPE *ReadDataFromFileAutomation )( 
            IWriteToFileAutomation * This,
            /* [in] */ HWND __MIDL__IWriteToFileAutomation0006,
            /* [in] */ unsigned char *__MIDL__IWriteToFileAutomation0007,
            /* [in] */ int *__MIDL__IWriteToFileAutomation0008);
        
        END_INTERFACE
    } IWriteToFileAutomationVtbl;

    interface IWriteToFileAutomation
    {
        CONST_VTBL struct IWriteToFileAutomationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWriteToFileAutomation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWriteToFileAutomation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWriteToFileAutomation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWriteToFileAutomation_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWriteToFileAutomation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWriteToFileAutomation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWriteToFileAutomation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWriteToFileAutomation_WriteDataToFileAutomation(This,__MIDL__IWriteToFileAutomation0000,__MIDL__IWriteToFileAutomation0001,__MIDL__IWriteToFileAutomation0002,__MIDL__IWriteToFileAutomation0003,__MIDL__IWriteToFileAutomation0004,__MIDL__IWriteToFileAutomation0005)	\
    ( (This)->lpVtbl -> WriteDataToFileAutomation(This,__MIDL__IWriteToFileAutomation0000,__MIDL__IWriteToFileAutomation0001,__MIDL__IWriteToFileAutomation0002,__MIDL__IWriteToFileAutomation0003,__MIDL__IWriteToFileAutomation0004,__MIDL__IWriteToFileAutomation0005) ) 

#define IWriteToFileAutomation_ReadDataFromFileAutomation(This,__MIDL__IWriteToFileAutomation0006,__MIDL__IWriteToFileAutomation0007,__MIDL__IWriteToFileAutomation0008)	\
    ( (This)->lpVtbl -> ReadDataFromFileAutomation(This,__MIDL__IWriteToFileAutomation0006,__MIDL__IWriteToFileAutomation0007,__MIDL__IWriteToFileAutomation0008) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWriteToFileAutomation_INTERFACE_DEFINED__ */



#ifndef __AutomationServerProjectTypeLib_LIBRARY_DEFINED__
#define __AutomationServerProjectTypeLib_LIBRARY_DEFINED__

/* library AutomationServerProjectTypeLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AutomationServerProjectTypeLib;

EXTERN_C const CLSID CLSID_CWriteToFileAutomation;

#ifdef __cplusplus

class DECLSPEC_UUID("B1BA2D99-9FB4-4724-B274-8BE0136E656F")
CWriteToFileAutomation;
#endif
#endif /* __AutomationServerProjectTypeLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


