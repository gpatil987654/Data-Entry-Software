

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "AutomationProxyStubHeader.h"

#define TYPE_FORMAT_STRING_SIZE   81                                
#define PROC_FORMAT_STRING_SIZE   119                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _AutomationServerProjectTypeLib_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } AutomationServerProjectTypeLib_MIDL_TYPE_FORMAT_STRING;

typedef struct _AutomationServerProjectTypeLib_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } AutomationServerProjectTypeLib_MIDL_PROC_FORMAT_STRING;

typedef struct _AutomationServerProjectTypeLib_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } AutomationServerProjectTypeLib_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const AutomationServerProjectTypeLib_MIDL_TYPE_FORMAT_STRING AutomationServerProjectTypeLib__MIDL_TypeFormatString;
extern const AutomationServerProjectTypeLib_MIDL_PROC_FORMAT_STRING AutomationServerProjectTypeLib__MIDL_ProcFormatString;
extern const AutomationServerProjectTypeLib_MIDL_EXPR_FORMAT_STRING AutomationServerProjectTypeLib__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWriteToFileAutomation_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWriteToFileAutomation_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const AutomationServerProjectTypeLib_MIDL_PROC_FORMAT_STRING AutomationServerProjectTypeLib__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure WriteDataToFileAutomation */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x40 ),	/* x86 Stack size/offset = 64 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 16 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x1 ),	/* 1 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter __MIDL__IWriteToFileAutomation0000 */

/* 26 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 28 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 30 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter __MIDL__IWriteToFileAutomation0001 */

/* 32 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 34 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 36 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter __MIDL__IWriteToFileAutomation0002 */

/* 38 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 40 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 42 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter __MIDL__IWriteToFileAutomation0003 */

/* 44 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 46 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 48 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter __MIDL__IWriteToFileAutomation0004 */

/* 50 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 52 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 54 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter __MIDL__IWriteToFileAutomation0005 */

/* 56 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 58 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 60 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Return value */

/* 62 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 64 */	NdrFcShort( 0x38 ),	/* x86 Stack size/offset = 56 */
/* 66 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadDataFromFileAutomation */

/* 68 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 70 */	NdrFcLong( 0x0 ),	/* 0 */
/* 74 */	NdrFcShort( 0x8 ),	/* 8 */
/* 76 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 78 */	NdrFcShort( 0x35 ),	/* 53 */
/* 80 */	NdrFcShort( 0x8 ),	/* 8 */
/* 82 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 84 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x1 ),	/* 1 */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter __MIDL__IWriteToFileAutomation0006 */

/* 94 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 96 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 98 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Parameter __MIDL__IWriteToFileAutomation0007 */

/* 100 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 102 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 104 */	0x2,		/* FC_CHAR */
			0x0,		/* 0 */

	/* Parameter __MIDL__IWriteToFileAutomation0008 */

/* 106 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 108 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 114 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const AutomationServerProjectTypeLib_MIDL_TYPE_FORMAT_STRING AutomationServerProjectTypeLib__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x12, 0x0,	/* FC_UP */
/*  4 */	NdrFcShort( 0xe ),	/* Offset= 14 (18) */
/*  6 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/*  8 */	NdrFcShort( 0x2 ),	/* 2 */
/* 10 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 12 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 14 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 16 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 18 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 20 */	NdrFcShort( 0x8 ),	/* 8 */
/* 22 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (6) */
/* 24 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 26 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 28 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 30 */	NdrFcShort( 0x0 ),	/* 0 */
/* 32 */	NdrFcShort( 0x8 ),	/* 8 */
/* 34 */	NdrFcShort( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0xffde ),	/* Offset= -34 (2) */
/* 38 */	
			0x12, 0x0,	/* FC_UP */
/* 40 */	NdrFcShort( 0x2 ),	/* Offset= 2 (42) */
/* 42 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x48,		/* 72 */
/* 44 */	NdrFcShort( 0x4 ),	/* 4 */
/* 46 */	NdrFcShort( 0x2 ),	/* 2 */
/* 48 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 52 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 54 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 58 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 60 */	NdrFcShort( 0xffff ),	/* Offset= -1 (59) */
/* 62 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 64 */	NdrFcShort( 0x1 ),	/* 1 */
/* 66 */	NdrFcShort( 0x8 ),	/* 8 */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */
/* 70 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (38) */
/* 72 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 74 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 76 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 78 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            HWND_UserSize
            ,HWND_UserMarshal
            ,HWND_UserUnmarshal
            ,HWND_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IWriteToFileAutomation, ver. 0.0,
   GUID={0xE79B1EF0,0x03F6,0x4490,{0xAC,0x60,0x6E,0xBC,0x28,0x6D,0x97,0x54}} */

#pragma code_seg(".orpc")
static const unsigned short IWriteToFileAutomation_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    68
    };

static const MIDL_STUBLESS_PROXY_INFO IWriteToFileAutomation_ProxyInfo =
    {
    &Object_StubDesc,
    AutomationServerProjectTypeLib__MIDL_ProcFormatString.Format,
    &IWriteToFileAutomation_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWriteToFileAutomation_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AutomationServerProjectTypeLib__MIDL_ProcFormatString.Format,
    &IWriteToFileAutomation_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IWriteToFileAutomationProxyVtbl = 
{
    &IWriteToFileAutomation_ProxyInfo,
    &IID_IWriteToFileAutomation,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IWriteToFileAutomation::WriteDataToFileAutomation */ ,
    (void *) (INT_PTR) -1 /* IWriteToFileAutomation::ReadDataFromFileAutomation */
};


static const PRPC_STUB_FUNCTION IWriteToFileAutomation_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IWriteToFileAutomationStubVtbl =
{
    &IID_IWriteToFileAutomation,
    &IWriteToFileAutomation_ServerInfo,
    9,
    &IWriteToFileAutomation_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    AutomationServerProjectTypeLib__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x801026e, /* MIDL Version 8.1.622 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _AutomationServerProjectTypeLib_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IWriteToFileAutomationProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _AutomationServerProjectTypeLib_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IWriteToFileAutomationStubVtbl,
    0
};

PCInterfaceName const _AutomationServerProjectTypeLib_InterfaceNamesList[] = 
{
    "IWriteToFileAutomation",
    0
};

const IID *  const _AutomationServerProjectTypeLib_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _AutomationServerProjectTypeLib_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _AutomationServerProjectTypeLib, pIID, n)

int __stdcall _AutomationServerProjectTypeLib_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_AutomationServerProjectTypeLib_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo AutomationServerProjectTypeLib_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _AutomationServerProjectTypeLib_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _AutomationServerProjectTypeLib_StubVtblList,
    (const PCInterfaceName * ) & _AutomationServerProjectTypeLib_InterfaceNamesList,
    (const IID ** ) & _AutomationServerProjectTypeLib_BaseIIDList,
    & _AutomationServerProjectTypeLib_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

