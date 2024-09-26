#include<Windows.h>
#include"AggregationInnerServer.h"


class IUnknownNoAggregation
{

public:
	virtual HRESULT __stdcall QueryInterface_NoAggregation(REFIID, void**)=0;
	virtual ULONG __stdcall AddRef_NoAggregation(void)=0;
	virtual ULONG __stdcall Release_NoAggregation(void)=0;
};


class CReadDataAggregation :public IUnknownNoAggregation, IReadDataFromFileAggregation
{
private:
	long m_cRef;
	IUnknown* m_pIUnknownOuter;


public:

	//Constructor destructor
	CReadDataAggregation(IUnknown*);
	~CReadDataAggregation(void);

	//IUnknown Methods
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);


	//INoAggregation Methods

	HRESULT __stdcall QueryInterface_NoAggregation(REFIID, void**);
    ULONG __stdcall AddRef_NoAggregation(void);
    ULONG __stdcall Release_NoAggregation(void);


	//IReadDataFromFileAggregation

	HRESULT __stdcall ReadDataFromFileAggregation(HWND, LPCSTR,int*);

};



class CReadDataAggregationClassFactory :IClassFactory
{
private:
	long m_cRef;

public:

	//Constructor and Destructor
	CReadDataAggregationClassFactory();
	~CReadDataAggregationClassFactory();

	//IUnknown Methods
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IClassFactory Methods
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


	}


	return TRUE;
}



CReadDataAggregation::CReadDataAggregation(IUnknown* pIUnknwonOuter)
{
	m_cRef = 1;
	if (pIUnknwonOuter != NULL)
	{
		m_pIUnknownOuter = pIUnknwonOuter;
	}
	else
	{
		m_pIUnknownOuter = reinterpret_cast<IUnknown*>(static_cast<IUnknownNoAggregation*>(this));

	}

	InterlockedIncrement(&glNumberOfActiveComponents);
}

CReadDataAggregation::~CReadDataAggregation()
{

	InterlockedDecrement(&glNumberOfActiveComponents);

}

//IUnknwon Methods Implementation

HRESULT CReadDataAggregation::QueryInterface(REFIID riid, void** ppv)
{

	return(m_pIUnknownOuter->QueryInterface(riid, ppv));
}

ULONG CReadDataAggregation::AddRef()
{
	return(m_pIUnknownOuter->AddRef());
}

ULONG CReadDataAggregation::Release()
{
	return(m_pIUnknownOuter->Release());
}

//IunknownNoAggregation Methos Implementation


HRESULT CReadDataAggregation::QueryInterface_NoAggregation(REFIID riid, void** ppv)
{

	if (riid == IID_IUnknown)
	{
		*ppv = static_cast <IUnknownNoAggregation*>(this);
	}
	else if (riid == IID_IReadDataFromFileAggregation)
	{
		*ppv = static_cast <IReadDataFromFileAggregation*>(this);
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	reinterpret_cast <IUnknown*>(this)->AddRef();

	return S_OK;
}

ULONG CReadDataAggregation::AddRef_NoAggregation()
{
	InterlockedIncrement(&m_cRef);

	return(m_cRef);
}

ULONG CReadDataAggregation::Release_NoAggregation()
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return 0;
	}
	return m_cRef;
}

HRESULT CReadDataAggregation::ReadDataFromFileAggregation(HWND diloghwnd, LPCSTR lpFileName,int IDOfEditControl[10])
{
	char ReadBuffer[500];
	DWORD NumberOfBytesRead;

	HANDLE hFileReadHandle = CreateFile(lpFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	SetFilePointer(hFileReadHandle, 0, NULL, 0);

	ReadFile(hFileReadHandle, ReadBuffer, 500, &NumberOfBytesRead, NULL);

	
	TCHAR* pch;
	TCHAR* pch2;
	TCHAR* pch3;
	pch = strtok(ReadBuffer, "\n");

	int j = 1;
	while (pch != NULL)
	{
		if (j > 6)
		{

			if (j == 7)
			{
				SetDlgItemText(diloghwnd, IDOfEditControl[0], (LPCSTR)pch);
			}
			else if (j == 8)
			{

				pch3 = pch;

			}
			else  if (j == 9)
			{
				SetDlgItemText(diloghwnd, IDOfEditControl[4], (LPCSTR)pch);
			}
			else if (j == 10)
			{
				SetDlgItemText(diloghwnd, IDOfEditControl[5], (LPCSTR)pch);
			}
			else if (j == 11)
			{
				SetDlgItemText(diloghwnd, IDOfEditControl[6], (LPCSTR)pch);

			}
		}
		j++;
		pch = strtok(NULL, "\n");
	}

	pch2 = strtok(pch3, "/");
	int k = 1;
	while (pch2 != NULL)
	{
		if (k == 1)
			SetDlgItemText(diloghwnd, IDOfEditControl[1], (LPCSTR)pch2);

		if (k == 2)
			SetDlgItemText(diloghwnd, IDOfEditControl[2], (LPCSTR)pch2);

		if (k == 3)
			SetDlgItemText(diloghwnd, IDOfEditControl[3], (LPCSTR)pch2);

		k++;
		pch2 = strtok(NULL, "/");
	}


	CloseHandle(hFileReadHandle);
	return S_OK;
}



//ClassFactory Implementation

CReadDataAggregationClassFactory::CReadDataAggregationClassFactory()
{

	m_cRef = 1;

}

CReadDataAggregationClassFactory::~CReadDataAggregationClassFactory()
{

}

HRESULT CReadDataAggregationClassFactory::QueryInterface(REFIID riid, void** ppv)
{

	if (riid == IID_IUnknown)
	{
		*ppv = static_cast <IUnknown*>(this);
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


ULONG CReadDataAggregationClassFactory::AddRef()
{
	InterlockedIncrement(&m_cRef);

	return m_cRef;
}

ULONG CReadDataAggregationClassFactory::Release()
{

	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{

		delete(this);
		return 0;
	}

	return m_cRef;
}


HRESULT CReadDataAggregationClassFactory::CreateInstance(IUnknown* pUnkouter, REFIID riid, void** ppv)
{
	CReadDataAggregation* pCReadDataAggregation = NULL;
	HRESULT hr;

	if ((pUnkouter != NULL) && (riid != IID_IUnknown))
	{
		return CLASS_E_NOAGGREGATION;

	}

	pCReadDataAggregation = new CReadDataAggregation(pUnkouter);

	if (pCReadDataAggregation == NULL)
		return E_OUTOFMEMORY;


	hr=pCReadDataAggregation->QueryInterface_NoAggregation(riid, ppv);//Increments IUnknownNoAggregation->AddRef_Noaggregation() m_cRef

	pCReadDataAggregation->Release_NoAggregation();


	return hr;
}


HRESULT CReadDataAggregationClassFactory::LockServer(BOOL flock)
{
        if (flock)
			InterlockedIncrement(&glNumberOfServerLocks);
		else
			InterlockedDecrement(&glNumberOfServerLocks);

		return S_OK;

}



extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	CReadDataAggregationClassFactory* pCReadDataAggregationClassFactory = NULL;
	HRESULT hr;

	if (rclsid != CLSID_CReadDataAggregation)
	{
		return CLASS_E_CLASSNOTAVAILABLE;
	}


	pCReadDataAggregationClassFactory = new CReadDataAggregationClassFactory;

	if (pCReadDataAggregationClassFactory == NULL)
	{
		return E_OUTOFMEMORY;
	}

	
	hr=pCReadDataAggregationClassFactory->QueryInterface(riid, ppv);

	pCReadDataAggregationClassFactory->Release();



   return hr;
}




extern "C" HRESULT __stdcall DllCanUnloadNow()
{
	if ((glNumberOfActiveComponents == 0) && (glNumberOfServerLocks == 0))
		return S_OK;
	else
		return S_FALSE;

}

