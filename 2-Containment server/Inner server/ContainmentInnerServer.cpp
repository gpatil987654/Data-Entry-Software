#include<Windows.h>
#include"ContainmentInnerServer.h"


class CReadWriteTimestamp :public IWriteTimestampToFile, IReadTimestampFromFile
{

private:
	long m_cRef;

public:
	//Constructor and Destructor
	CReadWriteTimestamp(void);
	
	~CReadWriteTimestamp(void);

	//IUnknown Methods
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IReadTimestampFromFile Methods
	HRESULT __stdcall ReadTimeStampFromFile(HWND, LPCSTR);

	//IWriteTimestampToFile Methods
	HRESULT __stdcall WriteTimeStampToFile(HWND, LPCSTR);

};


class CReadWriteTimestampClassFactory :public IClassFactory
{

private:
	long m_cRef;

public:

	//Constructor and Destructor
	CReadWriteTimestampClassFactory();
	~CReadWriteTimestampClassFactory();

	//IUnknwon Methods
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);


	//IclassFactory Methods
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


CReadWriteTimestamp::CReadWriteTimestamp(void)
{
	m_cRef = 1;
	InterlockedIncrement(&glNumberOfActiveComponents);
}

CReadWriteTimestamp::~CReadWriteTimestamp(void)
{

	InterlockedDecrement(&glNumberOfActiveComponents);
}

//Iunknown Method Implementation
HRESULT CReadWriteTimestamp::QueryInterface(REFIID riid, void** ppv)
{
	if (riid == IID_IUnknown)
	{
		*ppv = static_cast <IWriteTimestampToFile*>(this);
	}
	else if (riid == IID_IWriteTimestampToFile)
	{
		*ppv = static_cast <IWriteTimestampToFile*>(this);
	}
	else if (riid == IID_IReadTimestampFromFile)
	{
		*ppv = static_cast <IReadTimestampFromFile*>(this);
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	reinterpret_cast <IUnknown*>(*ppv)->AddRef();

	return S_OK;
}

ULONG CReadWriteTimestamp::AddRef(void)
{
	InterlockedIncrement(&m_cRef);

	return m_cRef;
}

ULONG CReadWriteTimestamp::Release(void)
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return 0;
	}

	return m_cRef;
}

HRESULT CReadWriteTimestamp::WriteTimeStampToFile(HWND hwnd, LPCSTR lpFileName)
{
	HANDLE hWriteHandle;
	SYSTEMTIME lst;
	char sysTime[125];
	DWORD lengthOfData, BytesWritten;
	GetLocalTime(&lst);

	wsprintf(sysTime, TEXT("%02d:%02d %d/%d/%d"),lst.wHour,lst.wMinute, lst.wDay,lst.wMonth,lst.wYear);

	//Win32-SDK for writing into file
	hWriteHandle = CreateFile(lpFileName, FILE_APPEND_DATA, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	// SetEndOfFile(hFileWriteHandle);
	//DataBuffer= Name+"\n"+date+"/"+month+"/"+year+"\n"+Address+"\n"+Education+"\n"+Company+"\n";
	//wsprintf(DataBuffer, TEXT("%s\n%s/%s/%s\n%s\n%s\n%s\n"), Name, date, month, year, Address, Education, Company);


	lengthOfData = (DWORD)strlen(sysTime);
	BytesWritten = 0;

	WriteFile(hWriteHandle, sysTime, lengthOfData, &BytesWritten, NULL);


	CloseHandle(hWriteHandle);
	return S_OK;
}

HRESULT CReadWriteTimestamp::ReadTimeStampFromFile(HWND hwnd, LPCSTR lpFileName)
{

	return S_OK;
}


//Co-ClassFactory Methods


CReadWriteTimestampClassFactory::CReadWriteTimestampClassFactory(void)
{
	m_cRef = 1;
}

CReadWriteTimestampClassFactory::~CReadWriteTimestampClassFactory(void)
{

}

HRESULT CReadWriteTimestampClassFactory::QueryInterface(REFIID riid, void** ppv)
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


ULONG CReadWriteTimestampClassFactory::AddRef()
{
	InterlockedIncrement(&m_cRef);

	return m_cRef;
}

ULONG CReadWriteTimestampClassFactory::Release()
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return m_cRef;
	}

	return m_cRef;
}


HRESULT CReadWriteTimestampClassFactory::CreateInstance(IUnknown* pUnkouter, REFIID riid, void** ppv)
{

	CReadWriteTimestamp* pCReadWriteTimestamp = NULL;
	HRESULT hr;

	if (pUnkouter != NULL)
		return CLASS_E_NOAGGREGATION;

	pCReadWriteTimestamp = new CReadWriteTimestamp;

	if (pCReadWriteTimestamp == NULL)
		return E_OUTOFMEMORY;

	hr=pCReadWriteTimestamp->QueryInterface(riid, ppv);
	pCReadWriteTimestamp->Release();


	return hr;
}

HRESULT CReadWriteTimestampClassFactory::LockServer(BOOL flock)
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
	HRESULT hr;
	CReadWriteTimestampClassFactory* pCReadWriteTimestampClassFactory = NULL;

	if (rclsid != CLSID_CReadWriteTimestamp)
		return CLASS_E_CLASSNOTAVAILABLE;

	pCReadWriteTimestampClassFactory = new CReadWriteTimestampClassFactory;

	if (pCReadWriteTimestampClassFactory == NULL)
		return E_OUTOFMEMORY;


	hr=pCReadWriteTimestampClassFactory->QueryInterface(riid, ppv);
	pCReadWriteTimestampClassFactory->Release();


	return hr;
}


extern "C" HRESULT __stdcall DllCanUnloadNow()
{

	if (glNumberOfActiveComponents == 0 && glNumberOfServerLocks == 0)
	{
		return S_OK;

	}
	else
	{
		return S_FALSE;
	}
}


