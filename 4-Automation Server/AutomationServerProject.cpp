#include<Windows.h>
#include<stdio.h>
#include"AutomationServerProject.h"
#include<iostream>

#include<fstream>
#include<string>
#include<comutil.h>
#import"DotNetServerReadWriteFile1.tlb" no_namespace named_guids raw_interfaces_only

using namespace std;


class CWriteToFileAutomation :public IWriteToFileAutomation
{

private:
	long m_cRef;
	ITypeInfo* m_pITypeInfo;

public:

	//Constructor and Destructor
	CWriteToFileAutomation();
	~CWriteToFileAutomation();

	//Iunknown Methods
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IDispatch Methods
	HRESULT __stdcall GetTypeInfoCount(UINT*);
	HRESULT __stdcall GetTypeInfo(UINT, LCID, ITypeInfo**);
	HRESULT __stdcall GetIDsOfNames(REFIID, LPOLESTR*, UINT, LCID, DISPID*);
	HRESULT __stdcall Invoke(DISPID, REFIID, LCID, WORD, DISPPARAMS*, VARIANT*, EXCEPINFO*, UINT*);


	//write Method

	HRESULT __stdcall WriteDataToFileAutomation(BSTR, BSTR, BSTR, BSTR, BSTR, BSTR);

	HRESULT __stdcall ReadDataFromFileAutomation(HWND,char*,int*);

	HRESULT  InitInstance(void);
};

class CWriteToFileAutomationClassFactory :public IClassFactory
{

private:

	long m_cRef;

public:
	//Constructor and destructor
	CWriteToFileAutomationClassFactory();
	~CWriteToFileAutomationClassFactory();

	//IUnknown Methods
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);


	//IClassfactory Methods

	HRESULT __stdcall CreateInstance(IUnknown*, REFIID, void**);
	HRESULT __stdcall LockServer(BOOL);

};

long glNumberOfActiveComponents;
long glNumberOfServerLocks;


// {96C63C46-7165-4B8E-BFFD-4B71BEC31CB5}
const GUID LIBID_AUtomationServreProject = { 0x96c63c46, 0x7165, 0x4b8e, 0xbf, 0xfd, 0x4b, 0x71, 0xbe, 0xc3, 0x1c, 0xb5 };


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


CWriteToFileAutomation::CWriteToFileAutomation()
{
	m_cRef = 1;
	m_pITypeInfo = NULL;

	InterlockedIncrement(&glNumberOfActiveComponents);
}

CWriteToFileAutomation::~CWriteToFileAutomation()
{
	InterlockedDecrement(&glNumberOfActiveComponents);

}



HRESULT CWriteToFileAutomation::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IUnknown)
	{
		*ppv = static_cast <IWriteToFileAutomation*>(this);
	}
	else if (riid == IID_IDispatch)
	{
		*ppv = static_cast <IWriteToFileAutomation*>(this);
	}
	else if (riid == IID_IWriteToFileAutomation)
	{
		*ppv = static_cast <IWriteToFileAutomation*>(this);
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	reinterpret_cast <IUnknown*>(*ppv)->AddRef();

	return S_OK;
}


ULONG CWriteToFileAutomation::AddRef()
{
	InterlockedIncrement(&m_cRef);

	return m_cRef;
}


ULONG CWriteToFileAutomation::Release()
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		m_pITypeInfo->Release();
		m_pITypeInfo = NULL;



		delete(this);
		return 0;
	}

	return m_cRef;
}


//IDispatch Methods

HRESULT CWriteToFileAutomation::GetTypeInfoCount(UINT* pCountITypeInfo)
{

	*pCountITypeInfo = 1;

	return S_OK;
}

HRESULT CWriteToFileAutomation::GetTypeInfo(UINT iTypeInfo, LCID lcid, ITypeInfo** pITypeInfo)
{
	*pITypeInfo = NULL;

	if (iTypeInfo != 0)
	{
		return DISP_E_BADINDEX;
	}

	m_pITypeInfo->AddRef();

	*pITypeInfo = m_pITypeInfo;

	return S_OK;
}


HRESULT CWriteToFileAutomation::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId)
{

	return(DispGetIDsOfNames(m_pITypeInfo, rgszNames, cNames, rgDispId));
}

HRESULT CWriteToFileAutomation::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr)
{
	HRESULT hr;

	hr = DispInvoke(this, m_pITypeInfo, dispIdMember, wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr);

	return(hr);
}



HRESULT CWriteToFileAutomation::WriteDataToFileAutomation(BSTR Name, BSTR DOB, BSTR Address, BSTR Education, BSTR Company, BSTR lpfilename)
{
	//HRESULT hr;

	//IWriteToFileUsingDotNetServer* pIWriteToFileUsingDotNetServer;

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
	vArg[0].bstrVal = lpfilename;

	vArg[1].vt = VT_BSTR;
	vArg[1].bstrVal = Company;

	vArg[2].vt = VT_BSTR;
	vArg[2].bstrVal = Education;


	vArg[3].vt = VT_BSTR;
	vArg[3].bstrVal = Address;


	vArg[4].vt = VT_BSTR;
	vArg[4].bstrVal = DOB;


	vArg[5].vt = VT_BSTR;
	vArg[5].bstrVal = Name;

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

	/*
	hr = CoCreateInstance(CLSID_CWriteToFileUsingDotNetServer, NULL, CLSCTX_INPROC_SERVER, IID_IWriteToFileUsingDotNetServer,(void**)&pIWriteToFileUsingDotNetServer);

	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("CO-createInstance Failed to get IDispatch Interface"), TEXT("Error"), MB_OK);

	}
	
	pIWriteToFileUsingDotNetServer->WriteDataToFileUsingDotNetServer(Name, DOB, Address, Education, Company, lpfilename);

	pIWriteToFileUsingDotNetServer->Release();


	pIWriteToFileUsingDotNetServer = NULL;
	*/
	return S_OK;
}

HRESULT CWriteToFileAutomation::ReadDataFromFileAutomation(HWND diloghwnd,char* lpfilename,int* iIdOfEditBoxes)
{

	ifstream fileRead;
	fileRead.open(lpfilename);

	TCHAR line[128];
	int i = 1;

	while (!fileRead.eof())
	{
		if (i != 1)
			fileRead >> line;


		if (i == 1)
		{
			string s;
			getline(fileRead, s);
			SetDlgItemText(diloghwnd, iIdOfEditBoxes[0], (LPCSTR)s.c_str());
		}

		if (i == 2)
		{

			TCHAR* pch;
			pch = strtok(line, "/");
			int j = 1;
			while (pch != NULL)
			{
				if (j == 1)
					SetDlgItemText(diloghwnd, iIdOfEditBoxes[1], (LPCSTR)pch);

				if (j == 2)
					SetDlgItemText(diloghwnd, iIdOfEditBoxes[2], (LPCSTR)pch);

				if (j == 3)
					SetDlgItemText(diloghwnd, iIdOfEditBoxes[3], (LPCSTR)pch);

				j++;
				pch = strtok(NULL, "/");
			}
		}

		if (i == 3)
		{

			SetDlgItemText(diloghwnd, iIdOfEditBoxes[4], (LPCSTR)line);
		}

		if (i == 4)
		{

			SetDlgItemText(diloghwnd, iIdOfEditBoxes[5], (LPCSTR)line);
		}

		if (i == 5)
		{

			SetDlgItemText(diloghwnd, iIdOfEditBoxes[6], (LPCSTR)line);
		}

		i++;

	}


	fileRead.close();


	return S_OK;
}


HRESULT CWriteToFileAutomation::InitInstance()
{
	void ComErrorDescriptionString(HWND ,HRESULT);

	HRESULT hr;
	ITypeLib* pITypeLib = NULL;



	if (m_pITypeInfo == NULL)
	{
		hr = LoadRegTypeLib(LIBID_AUtomationServreProject,
			1, 0,
			0X00,
			&pITypeLib);

		if (FAILED(hr))
		{
			ComErrorDescriptionString(NULL, hr);

			return hr;
		}

		hr = pITypeLib->GetTypeInfoOfGuid(IID_IWriteToFileAutomation, &m_pITypeInfo);


		if (FAILED(hr))
		{
			ComErrorDescriptionString(NULL, hr);
			pITypeLib->Release();
			return(hr);
		}

		pITypeLib->Release();
	}


	return S_OK;
}

//Class Factory Class Implementation


CWriteToFileAutomationClassFactory::CWriteToFileAutomationClassFactory()
{
	m_cRef = 1;
}

CWriteToFileAutomationClassFactory::~CWriteToFileAutomationClassFactory()
{

}


HRESULT CWriteToFileAutomationClassFactory::QueryInterface(REFIID riid, void** ppv)
{

	if (riid == IID_IUnknown)
		*ppv = static_cast<IClassFactory*>(this);
	else if (riid == IID_IClassFactory)
		*ppv = static_cast<IClassFactory*>(this);
	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}

	reinterpret_cast<IUnknown*>(*ppv)->AddRef();

	return(S_OK);
}

ULONG CWriteToFileAutomationClassFactory::AddRef()
{
	InterlockedIncrement(&m_cRef);

	return m_cRef;
}

ULONG CWriteToFileAutomationClassFactory::Release()
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return 0;
	}

	return m_cRef;
}

//IClassFactory Member function Implementation


HRESULT CWriteToFileAutomationClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{

	CWriteToFileAutomation* pCWriteToFileAutomation = NULL;
	HRESULT hr;

	if (pUnkOuter != NULL)
		return(CLASS_E_NOAGGREGATION);

	pCWriteToFileAutomation = new CWriteToFileAutomation;

	if (pCWriteToFileAutomation == NULL)
		return(E_OUTOFMEMORY);

	pCWriteToFileAutomation->InitInstance();

	hr = pCWriteToFileAutomation->QueryInterface(riid, ppv);

	pCWriteToFileAutomation->Release();

	return(hr);

}

HRESULT CWriteToFileAutomationClassFactory::LockServer(BOOL fLock)
{
	if (fLock)
		InterlockedIncrement(&glNumberOfServerLocks);
	else
		InterlockedDecrement(&glNumberOfServerLocks);

	return S_OK;
}

//Exported Functions

extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	HRESULT hr;
	CWriteToFileAutomationClassFactory* pCWriteToFileAutomationClassFactory = NULL;

	if (rclsid != CLSID_CWriteToFileAutomation)
		return(E_NOINTERFACE);

	pCWriteToFileAutomationClassFactory = new CWriteToFileAutomationClassFactory;

	if (pCWriteToFileAutomationClassFactory == NULL)
		return(E_OUTOFMEMORY);

	hr = pCWriteToFileAutomationClassFactory->QueryInterface(riid, ppv);

	pCWriteToFileAutomationClassFactory->Release();

	return hr;
}

extern "C" HRESULT __stdcall DllCanUnloadNow()
{
	if (glNumberOfActiveComponents == 0 && glNumberOfServerLocks == 0)
		return S_OK;
	else
		return S_FALSE;
}


//Com Error Description Function

void ComErrorDescriptionString(HWND hwnd, HRESULT hr)
{
	TCHAR* szErrorMessage = NULL;
	TCHAR str[255];

	if (FACILITY_WINDOWS == HRESULT_FACILITY(hr))
		hr = HRESULT_CODE(hr);

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, hr, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&szErrorMessage, 0, NULL) != 0)
	{
		wsprintf(str, TEXT("%#x : %s"), hr, szErrorMessage);
		//swprintf_s(str, TEXT("%#x : %s"), hr, szErrorMessage);
		LocalFree(szErrorMessage);
	}
	else
	{
		wsprintf(str, TEXT("[Could not find a Description for error # %#x.]\n"), hr);

	}

	MessageBox(hwnd, str, TEXT("COM Error"), MB_OK);
}


