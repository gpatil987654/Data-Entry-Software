#include<Windows.h>
#include"AggregationOuterServer.h"
#include"AggregationInnerServer.h"


class CReadTimeStampAggregation :public IReadTimeStampAggregation
{
private:
	long m_cRef;
	IUnknown* m_pIUnknownInner;
	IReadDataFromFileAggregation* m_pIReadDataFromFileAggregation;

public:

	//Constructor and Destructor
	CReadTimeStampAggregation();
	~CReadTimeStampAggregation();


	//IUnknown Methods
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);


	HRESULT __stdcall ReadTimeStampAggregation(HWND, LPCSTR);

	HRESULT __stdcall InitialiseInnerComponent();
};


class CReadTimeStampAggregationClassFactory :public IClassFactory
{
private:
	long m_cRef;

public:

	//Constructor destructor
	CReadTimeStampAggregationClassFactory();

	~CReadTimeStampAggregationClassFactory();

	//IUnknown Methods
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IclassFactory Methods

	HRESULT __stdcall CreateInstance(IUnknown*, REFIID, void**);
	HRESULT __stdcall LockServer(BOOL);


};

long glNumberOfActiveComponents;
long glNumberOfServerLocks;

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID Reserved)
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


CReadTimeStampAggregation::CReadTimeStampAggregation(void)
{
	m_cRef = 1;
	m_pIUnknownInner = NULL;
	m_pIReadDataFromFileAggregation = NULL;
	InterlockedIncrement(&glNumberOfActiveComponents);
}

CReadTimeStampAggregation::~CReadTimeStampAggregation(void)
{
	InterlockedDecrement(&glNumberOfActiveComponents);
	if (m_pIUnknownInner)
	{
		m_pIUnknownInner->Release();
		m_pIUnknownInner = NULL;
	}

	if (m_pIReadDataFromFileAggregation)
	{
		m_pIReadDataFromFileAggregation->Release();
		m_pIReadDataFromFileAggregation = NULL;

	}
}



HRESULT CReadTimeStampAggregation::QueryInterface(REFIID riid, void** ppv)
{

	if (riid == IID_IUnknown)
	{
		*ppv = static_cast <IReadTimeStampAggregation*>(this);
	}
	else if (riid == IID_IReadTimeStampAggregation)
	{
		*ppv = static_cast <IReadTimeStampAggregation*>(this);
	}
	else if (riid == IID_IReadDataFromFileAggregation)
	{
		return(m_pIUnknownInner->QueryInterface(riid,ppv));
	}
	else
	{
		*ppv = NULL;

		return S_OK;
	}

	reinterpret_cast <IUnknown*>(*ppv)->AddRef();

	return S_OK;
}


ULONG CReadTimeStampAggregation::AddRef()
{
	InterlockedIncrement(&m_cRef);

	return m_cRef;
}

ULONG CReadTimeStampAggregation::Release()
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return 0;
	}

	return m_cRef;
}


HRESULT CReadTimeStampAggregation::ReadTimeStampAggregation(HWND hwnd,LPCSTR lpFileName)
{
	char ReadBuffer[500];
	TCHAR* TimeStamp;
	DWORD NumberOfBytesRead;

	HANDLE hFileReadHandle = CreateFile(lpFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	SetFilePointer(hFileReadHandle, 0, NULL, 0);

	ReadFile(hFileReadHandle, ReadBuffer, 500, &NumberOfBytesRead, NULL);


	TCHAR* pch;
	pch = strtok(ReadBuffer, "\n");

	int j = 1;
	while (pch != NULL)
	{

		if (j == 12)
		{
			TimeStamp = pch;
			break;
		}
		j++;
	}


	CloseHandle(hFileReadHandle);
	return S_OK;
}


HRESULT CReadTimeStampAggregation::InitialiseInnerComponent()
{

	HRESULT hr;

	hr = CoCreateInstance(CLSID_CReadDataAggregation, reinterpret_cast <IUnknown*>(this), CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&m_pIUnknownInner);


	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("IUnknown Interface can not be Obtaibned from Inner Component"), TEXT("Error"), MB_OK);
		return(E_FAIL);
	}

	hr = m_pIUnknownInner->QueryInterface(IID_IReadDataFromFileAggregation, (void**)&m_pIReadDataFromFileAggregation);



	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("IUnknown Interface can not be Obtaibned from Inner Component"), TEXT("Error"), MB_OK);
		m_pIUnknownInner->Release();
		m_pIUnknownInner = NULL;

		return(E_FAIL);
	}



	return S_OK;
}


//ClassFactory class implementation


CReadTimeStampAggregationClassFactory::CReadTimeStampAggregationClassFactory()
{
	m_cRef = 1;
}


CReadTimeStampAggregationClassFactory::~CReadTimeStampAggregationClassFactory()
{

}


HRESULT CReadTimeStampAggregationClassFactory::QueryInterface(REFIID riid, void** ppv)
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

		return(E_NOINTERFACE);
	}

	reinterpret_cast <IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

ULONG CReadTimeStampAggregationClassFactory::AddRef()
{
	InterlockedIncrement(&m_cRef);

	return m_cRef;
}

ULONG CReadTimeStampAggregationClassFactory::Release()
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return 0;
	}

	return m_cRef;
}


HRESULT CReadTimeStampAggregationClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{

	HRESULT hr;
	CReadTimeStampAggregation* pCReadTimeStampAggregation = NULL;

	if (pUnkOuter != NULL)
		return CLASS_E_NOAGGREGATION;

	pCReadTimeStampAggregation = new CReadTimeStampAggregation;

	if (pCReadTimeStampAggregation == NULL)
	{
		return E_OUTOFMEMORY;
	}

	hr = pCReadTimeStampAggregation->InitialiseInnerComponent();


	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("Failed to initialise Inner Component"), TEXT("Error"), MB_OK);

		pCReadTimeStampAggregation->Release();
		return(hr);
	}


	hr = pCReadTimeStampAggregation->QueryInterface(riid, ppv);

	pCReadTimeStampAggregation->Release();

	return hr;
}


HRESULT CReadTimeStampAggregationClassFactory::LockServer(BOOL flock)
{
	if (flock)
		InterlockedIncrement(&glNumberOfServerLocks);
	else
		InterlockedDecrement(&glNumberOfServerLocks);

	return S_OK;
}


//Exported function

extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	CReadTimeStampAggregationClassFactory* pCReadTimeStampAggregationClassFactory = NULL;
	HRESULT hr;

	if (rclsid != CLSID_CReadTimeStampAggregation)
	{
		return CLASS_E_CLASSNOTAVAILABLE;
	}

	pCReadTimeStampAggregationClassFactory = new CReadTimeStampAggregationClassFactory;

	if (pCReadTimeStampAggregationClassFactory == NULL)
	{
		return E_OUTOFMEMORY;
	}

	hr = pCReadTimeStampAggregationClassFactory->QueryInterface(riid, ppv);

	pCReadTimeStampAggregationClassFactory->Release();


	return hr;
}


extern "C" HRESULT __stdcall DllCanUnloadNow()
{
	if (glNumberOfActiveComponents == 0 && glNumberOfServerLocks == 0)
		return S_OK;
	else
		return S_FALSE;

}


