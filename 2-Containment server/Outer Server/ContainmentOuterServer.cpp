#include<Windows.h>
#include<string>
#include"ContainmentOuterServer.h"
#include"ContainmentInnerServer.h"

using namespace std;

class CReadWriteData :public IWriteDataToFile, IReadDataFromFile, IWriteTimestampToFile
{

private:
	long m_cRef;
	IWriteTimestampToFile* pIWriteTimestampToFile;


public:
	//Constructor and Destructor
	CReadWriteData(void);
	~CReadWriteData(void);

	//IUnknown Methods
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IWriteDataToFile
	HRESULT __stdcall WriteDataToFile(HWND, LPCSTR,char**);

	//IReadDataFromFile
	HRESULT __stdcall ReadDataFromFile(HWND, LPCSTR);

	//IWriteTimestampToFile
	HRESULT __stdcall WriteTimeStampToFile(HWND, LPCSTR);

	void __stdcall Initialise(void);
};

class CReadWriteDataClassFactory :public IClassFactory
{

private:
	long m_cRef;

public:
	CReadWriteDataClassFactory(void);
	~CReadWriteDataClassFactory(void);

	//IUnknown Methods
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IclassFaftory Methods

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


CReadWriteData::CReadWriteData(void)
{
	m_cRef = 1;
	pIWriteTimestampToFile = NULL;
	InterlockedIncrement(&glNumberOfActiveComponents);

}

CReadWriteData::~CReadWriteData(void)
{
	InterlockedDecrement(&glNumberOfActiveComponents);

	if (pIWriteTimestampToFile)
	{
		pIWriteTimestampToFile->Release();
		pIWriteTimestampToFile = NULL;
	}
}

//Iunknwon

HRESULT CReadWriteData::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IUnknown)
	{
		*ppv = static_cast <IWriteDataToFile*>(this);
	}
	else if (riid == IID_IWriteDataToFile)
	{
		*ppv = static_cast <IWriteDataToFile*>(this);
	}
	else if (riid == IID_IReadDataFromFile)
	{
		*ppv = static_cast <IReadDataFromFile*>(this);
	}
	else if (riid == IID_IWriteTimestampToFile)
	{
		*ppv = static_cast <IWriteTimestampToFile*>(this);
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	reinterpret_cast <IUnknown*>(*ppv)->AddRef();

	return S_OK;

}

ULONG CReadWriteData::AddRef()
{
	InterlockedIncrement(&m_cRef);

	return m_cRef;
}

ULONG CReadWriteData::Release()
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return 0;
	}

	return m_cRef;
}

HRESULT CReadWriteData::WriteDataToFile(HWND hwnd, LPCSTR lpFileName,char* EditText[10])
{
	HANDLE hFileWriteHandle;
	char Data[255];
	DWORD lengthOfDataBuffer, NumberOfBytesWritten;

	hFileWriteHandle = CreateFile(lpFileName, FILE_APPEND_DATA, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	// SetEndOfFile(hFileWriteHandle);
	//DataBuffer= Name+"\n"+date+"/"+month+"/"+year+"\n"+Address+"\n"+Education+"\n"+Company+"\n";
	wsprintf(Data, TEXT("%s\n%s/%s/%s\n%s\n%s\n%s\n"), EditText[0], EditText[1], EditText[2], EditText[3], EditText[4], EditText[5], EditText[6]);


	lengthOfDataBuffer = (DWORD)strlen(Data);
	NumberOfBytesWritten = 0;

	WriteFile(hFileWriteHandle, Data, lengthOfDataBuffer, &NumberOfBytesWritten, NULL);


	CloseHandle(hFileWriteHandle);



	return S_OK;
}

HRESULT CReadWriteData::ReadDataFromFile(HWND hwnd, LPCSTR lpFileName)
{

	return S_OK;
}

HRESULT CReadWriteData::WriteTimeStampToFile(HWND hwnd, LPCSTR lpFileName)
{
	 pIWriteTimestampToFile->WriteTimeStampToFile(hwnd,lpFileName);

	 return S_OK;
}


void CReadWriteData::Initialise(void)
{

	HRESULT hr;

	hr = CoCreateInstance(CLSID_CReadWriteTimestamp, NULL, CLSCTX_INPROC_SERVER, IID_IWriteTimestampToFile, (void**)&pIWriteTimestampToFile);


}

//ClassFactory Implementation

CReadWriteDataClassFactory::CReadWriteDataClassFactory()
{
	m_cRef = 1;
}

CReadWriteDataClassFactory::~CReadWriteDataClassFactory()
{

}

HRESULT CReadWriteDataClassFactory::QueryInterface(REFIID riid, void** ppv)
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

ULONG CReadWriteDataClassFactory::AddRef()
{
	InterlockedIncrement(&m_cRef);

	return m_cRef;
}


ULONG CReadWriteDataClassFactory::Release()
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return 0;
	}

	return m_cRef;
}


HRESULT CReadWriteDataClassFactory::CreateInstance(IUnknown* pUnkouter, REFIID riid, void** ppv)
{
	CReadWriteData* pCReadWriteData = NULL;
	HRESULT hr;
	if (pUnkouter != NULL)
		return CLASS_E_NOAGGREGATION;


	pCReadWriteData = new CReadWriteData;

	if (pCReadWriteData == NULL)
		return E_OUTOFMEMORY;

	
	pCReadWriteData->Initialise();

	hr=pCReadWriteData->QueryInterface(riid, ppv);

	pCReadWriteData->Release();


	return hr;

}

HRESULT CReadWriteDataClassFactory::LockServer(BOOL flock)
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


//Exportable Functions

extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	CReadWriteDataClassFactory* pCReadWriteDataClassFactory = NULL;
	HRESULT hr;

	if (rclsid != CLSID_CReadWriteData)
	{
		return CLASS_E_CLASSNOTAVAILABLE;
	}

	pCReadWriteDataClassFactory = new CReadWriteDataClassFactory;

	if (pCReadWriteDataClassFactory == NULL)
	{
		return E_OUTOFMEMORY;
	}

	hr=pCReadWriteDataClassFactory->QueryInterface(riid, ppv);

	pCReadWriteDataClassFactory->Release();


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

