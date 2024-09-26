#include<Windows.h>
#include"testing.h"
#include<iostream>
#include<string>
#import"DotNetServerReadWriteFile2.tlb" no_namespace named_guids raw_interfaces_only
#include<comutil.h>

using namespace std;


class CWriteToFileUsingDotNetServer :public IWriteToFileUsingDotNetServer
{

private:
	long m_cref;

public:

	CWriteToFileUsingDotNetServer(void);
	~CWriteToFileUsingDotNetServer(void);

	//IUnknown Functions
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);



	HRESULT __stdcall WriteDataToFileUsingDotNetServer(char*, char*, char*, char*, char*, char*);


	//Initialise Interfaces

};

class CWriteToFileUsingDotNetServerClassFactory :public IClassFactory
{
private:
	long m_cref;

public:

	CWriteToFileUsingDotNetServerClassFactory(void);
	~CWriteToFileUsingDotNetServerClassFactory(void);


	//IUnknown Functions

	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IClassFactory Functions

	HRESULT __stdcall CreateInstance(IUnknown*, REFIID, void**);
	HRESULT __stdcall LockServer(BOOL);

};

long glNumberOfActiveComponents;
long glNumberOfServerLocks;

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReaserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	default:
		break;

	}

	return TRUE;
}


//CSumSubstract Implementaion

CWriteToFileUsingDotNetServer::CWriteToFileUsingDotNetServer(void)
{
	m_cref = 1;
	InterlockedIncrement(&glNumberOfActiveComponents);
}

CWriteToFileUsingDotNetServer::~CWriteToFileUsingDotNetServer(void)
{
	InterlockedDecrement(&glNumberOfActiveComponents);

}

//Iunknown Function Implementation

HRESULT CWriteToFileUsingDotNetServer::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IUnknown)
	{
		*ppv = static_cast <IWriteToFileUsingDotNetServer*>(this);
	}
	else if (riid == IID_IDispatch)
	{
		*ppv = static_cast <IWriteToFileUsingDotNetServer*>(this);
	}
	else if (riid == IID_IWriteToFileUsingDotNetServer)
	{
		*ppv = static_cast <IWriteToFileUsingDotNetServer*>(this);
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	reinterpret_cast <IUnknown*>(*ppv)->AddRef();

	return S_OK;
}


ULONG CWriteToFileUsingDotNetServer::AddRef(void)
{
	InterlockedIncrement(&m_cref);

	return m_cref;
}

ULONG CWriteToFileUsingDotNetServer::Release(void)
{
	InterlockedDecrement(&m_cref);

	if (m_cref == 0)
	{
		delete(this);
		return 0;
	}

	return m_cref;
}


HRESULT CWriteToFileUsingDotNetServer::WriteDataToFileUsingDotNetServer(char Name[], char DOB[], char Address[], char Education[], char Company[], char lpfilename[])
{



	IDispatch* pIDispatch = NULL;
	OLECHAR* szWriteFunction = L"WriteToFile";
	VARIANT vArg[6];
	VARIANT vResult;
	DISPID dispid;
	DISPPARAMS params;
	HRESULT hr;

	hr = CoInitialize(NULL);
	hr = CoCreateInstance(CLSID_DotNetServerReadWriteFile, NULL, CLSCTX_INPROC_SERVER, IID_IDispatch, (void**)&pIDispatch);


	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("CO-createInstance Failed to get IDispatch Interface"), TEXT("Error"), MB_OK);

	}
	
	hr = pIDispatch->GetIDsOfNames(
		IID_NULL,
		&szWriteFunction,
		1,
		GetUserDefaultLCID(),
		&dispid
	);

	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("GetIDsOfNames failed to get ID of WriteToFile"), TEXT("Error"), MB_OK);
		pIDispatch->Release();
		pIDispatch = NULL;

	}

	VariantInit(vArg);
	vArg[0].vt = VT_BSTR;
	vArg[0].bstrVal = _com_util::ConvertStringToBSTR(lpfilename);

	vArg[1].vt = VT_BSTR;
	vArg[1].bstrVal = _com_util::ConvertStringToBSTR(Company);

	vArg[2].vt = VT_BSTR;
	vArg[2].bstrVal = _com_util::ConvertStringToBSTR(Education);


	vArg[3].vt = VT_BSTR;
	vArg[3].bstrVal = _com_util::ConvertStringToBSTR(Address);


	vArg[4].vt = VT_BSTR;
	vArg[4].bstrVal = _com_util::ConvertStringToBSTR(DOB);


	vArg[5].vt = VT_BSTR;
	vArg[5].bstrVal = _com_util::ConvertStringToBSTR(Name);

	VariantInit(&vResult); //Initialise vResult by default values

	params.rgvarg = vArg; //register variant arguments
	params.cArgs = 6;// count of arguments
	params.rgdispidNamedArgs = NULL; //No named arguments
	params.cNamedArgs = 0;//Count of named arguments


	hr = pIDispatch->Invoke(
		dispid,
		IID_NULL,
		GetUserDefaultLCID(),
		DISPATCH_METHOD,
		&params,//Input parameters to function
		NULL,//Out Prameter of function
		NULL,
		NULL
	);


	VariantClear(&vResult);
	VariantClear(vArg);

	pIDispatch->Release();
	pIDispatch = NULL;


   CoUninitialize();
	return S_OK;
}

//Imultiply and Idivision initialisation

/*
void CSumSubstract::Initialise(void)
{

	HRESULT hr;


	hr = CoCreateInstance(CLSID_CMultiplyDivide, NULL, CLSCTX_INPROC_SERVER, IID_IMultiply, (void**)&pIMultiply);


	pIMultiply->QueryInterface(IID_IDivision, (void**)&pIDivision);

}
*/

//CSumsubstract classFactory Implementation


CWriteToFileUsingDotNetServerClassFactory::CWriteToFileUsingDotNetServerClassFactory(void)
{
	m_cref = 1;
}

CWriteToFileUsingDotNetServerClassFactory::~CWriteToFileUsingDotNetServerClassFactory(void)
{

}



//Iunknown Implementation

HRESULT CWriteToFileUsingDotNetServerClassFactory::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IUnknown)
	{
		*ppv = static_cast <IClassFactory*>(this);
	}
	else if (riid == IID_IClassFactory)
	{
		*ppv = static_cast <IClassFactory*>(this);
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	reinterpret_cast <IUnknown*>(*ppv)->AddRef();

	return S_OK;
}



ULONG CWriteToFileUsingDotNetServerClassFactory::AddRef(void)
{
	InterlockedIncrement(&m_cref);
	return m_cref;
}

ULONG CWriteToFileUsingDotNetServerClassFactory::Release(void)
{
	InterlockedDecrement(&m_cref);

	if (m_cref == 0)
	{
		delete(this);
		return 0;
	}

	return m_cref;
}


//IClassFactory Implementation
HRESULT CWriteToFileUsingDotNetServerClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{
	HRESULT hr;
	CWriteToFileUsingDotNetServer* pCWriteToFileUsingDotNetServer = NULL;

	if (pUnkOuter != NULL)
	{
		*ppv = NULL;
		return CLASS_E_NOAGGREGATION;
	}

	pCWriteToFileUsingDotNetServer = new CWriteToFileUsingDotNetServer;



	if (pCWriteToFileUsingDotNetServer == NULL)
	{
		return E_OUTOFMEMORY;
	}
	//pCSumSubstract->Initialise();

	hr = pCWriteToFileUsingDotNetServer->QueryInterface(riid, ppv);
	pCWriteToFileUsingDotNetServer->Release();

	return hr;

}

HRESULT CWriteToFileUsingDotNetServerClassFactory::LockServer(BOOL flock)
{

	if (flock)
	{
		InterlockedIncrement(&glNumberOfServerLocks);
	}
	else
	{
		InterlockedDecrement(&glNumberOfServerLocks);
	}

	return S_OK;
}


//Export functions

extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	HRESULT hr;
	CWriteToFileUsingDotNetServerClassFactory* pCWriteToFileUsingDotNetServerClassFactory = NULL;

	if (rclsid != CLSID_CWriteToFileUsingDotNetServer)
	{
		*ppv = NULL;
		return CLASS_E_CLASSNOTAVAILABLE;
	}

	pCWriteToFileUsingDotNetServerClassFactory = new CWriteToFileUsingDotNetServerClassFactory;

	hr = pCWriteToFileUsingDotNetServerClassFactory->QueryInterface(riid, ppv);

	pCWriteToFileUsingDotNetServerClassFactory->Release();


	return hr;

}


extern "C" HRESULT __stdcall DllCanUnloadNow()
{
	if (glNumberOfActiveComponents == 0 && glNumberOfServerLocks == 0)
	{
		return S_OK;
	}
	else
		return S_FALSE;
}

