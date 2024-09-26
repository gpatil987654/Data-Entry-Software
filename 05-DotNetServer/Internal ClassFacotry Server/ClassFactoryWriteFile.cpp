#include<Windows.h>
#include<string>
#include<iostream>
#include<fstream>
#include"ClassFactoryWriteFile.h"

using namespace std;
class CReadWriteFile :public IReadFile, IWriteFile
{

private:
	long m_cRef;


public:

	//Constructors
	CReadWriteFile(void);

	//Destructor
	~CReadWriteFile(void);

	//Iunknown Methods
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IReadFile Methods
	HRESULT __stdcall ReadDataFromFile(HWND,LPCSTR, int*);

	//IWriteFile Methods
	HRESULT __stdcall WriteDataToFile(HWND, int);

};


class CReadWriteFileClassFactory :public IClassFactory
{
private:
	long m_cRef;

public:

	//Constructor
	CReadWriteFileClassFactory(void);

	//Destructor
	~CReadWriteFileClassFactory(void);

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


CReadWriteFile::CReadWriteFile(void)
{
	m_cRef = 1;
	InterlockedIncrement(&glNumberOfActiveComponents);
}

CReadWriteFile::~CReadWriteFile(void)
{
	InterlockedDecrement(&glNumberOfActiveComponents);
}

//Iunknwon Methods Implementation

HRESULT CReadWriteFile::QueryInterface(REFIID riid, void** ppv)
{

	if (riid == IID_IUnknown)
	{
		*ppv = static_cast <IReadFile*>(this);
	}
	else if (riid == IID_IReadFile)
	{
		*ppv = static_cast <IReadFile*>(this);
	}
	else if (riid == IID_IWriteFile)
	{
		*ppv = static_cast <IWriteFile*>(this);
	}
	else
	{
		*ppv = NULL;

		return E_NOINTERFACE;
	}

	reinterpret_cast <IUnknown*>(*ppv)->AddRef();

	return S_OK;
}

ULONG CReadWriteFile::AddRef()
{
	InterlockedIncrement(&m_cRef);

	return m_cRef;
}

ULONG CReadWriteFile::Release()
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return 0;
	}

	return m_cRef;
}

HRESULT CReadWriteFile::ReadDataFromFile(HWND diloghwnd,LPCSTR lpFileName, int* iIdOfEditBoxes)
{
	ifstream fileRead;
	fileRead.open(lpFileName);

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

HRESULT CReadWriteFile::WriteDataToFile(HWND hwnd, int a)
{
	fileRead.open(strFileName2);


	i = 1;

	while (!fileRead.eof())
	{
		if (i != 1)
			fileRead >> line;


		if (i == 1)
		{
			getline(fileRead, s);
			SetDlgItemText(diloghwnd, EID_Name, (LPCSTR)s.c_str());
		}

		if (i == 2)
		{

			pch = strtok(line, "/");
			j = 1;
			while (pch != NULL)
			{
				if (j == 1)
					SetDlgItemText(diloghwnd, EID_DOB_Date, (LPCSTR)pch);

				if (j == 2)
					SetDlgItemText(diloghwnd, EID_DOB_Month, (LPCSTR)pch);

				if (j == 3)
					SetDlgItemText(diloghwnd, EID_DOB_Year, (LPCSTR)pch);

				j++;
				pch = strtok(NULL, "/");
			}
		}

		if (i == 3)
		{

			SetDlgItemText(diloghwnd, EID_Address, (LPCSTR)line);

		}
		if (i == 4)
		{

			SetDlgItemText(diloghwnd, EID_Education, (LPCSTR)line);
		}
		if (i == 5)
		{

			SetDlgItemText(diloghwnd, EID_Company, (LPCSTR)line);
		}

		i++;

	}


	fileRead.close();


	return S_OK;
}



//ClassFactory Implementation

CReadWriteFileClassFactory::CReadWriteFileClassFactory()
{
	m_cRef = 1;
}

CReadWriteFileClassFactory::~CReadWriteFileClassFactory()
{

}

HRESULT CReadWriteFileClassFactory::QueryInterface(REFIID riid, void** ppv)
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

ULONG CReadWriteFileClassFactory::AddRef()
{
	InterlockedIncrement(&m_cRef);
	return m_cRef;
}

ULONG CReadWriteFileClassFactory::Release()
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		delete(this);
		return 0;
	}

	return m_cRef;
}

//IclassFactory Methods Implementation

HRESULT CReadWriteFileClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{
	CReadWriteFile* pCReadWriteFile = NULL;
	HRESULT hr;

	if (pUnkOuter != NULL)
		return CLASS_E_NOAGGREGATION;

	pCReadWriteFile = new CReadWriteFile;


	if (pCReadWriteFile == NULL)
		return E_OUTOFMEMORY;


	hr=pCReadWriteFile->QueryInterface(riid, ppv);
	pCReadWriteFile->Release();

	return hr;
}

HRESULT CReadWriteFileClassFactory::LockServer(BOOL flock)
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
	CReadWriteFileClassFactory* pCReadWriteFileClassFactory = NULL;
	HRESULT hr;

	if (rclsid != CLSID_CReadWriteFile)
		return CLASS_E_CLASSNOTAVAILABLE;

	pCReadWriteFileClassFactory = new CReadWriteFileClassFactory;

	if (pCReadWriteFileClassFactory == NULL)
		return E_OUTOFMEMORY;


	hr = pCReadWriteFileClassFactory->QueryInterface(riid, ppv);

	pCReadWriteFileClassFactory->Release();

	return hr;
}

extern "C" HRESULT __stdcall DllCanUnloadNow()
{
	//code
	if (glNumberOfActiveComponents == 0 && glNumberOfServerLocks == 0)
	{
		return S_OK;

	}
	else
	{
		return S_FALSE;
	}

}

