// Headers Files
#include <windows.h>
#include <shlwapi.h>
#include <iostream>
#include <fstream>
#include <string>
#include "dilog.h"
#include "ClassFactoryReadFile.h"
#include "ContainmentHeaderFile.h"
#include "AggregationInnerOuterServer.h"
#include "AutomationServerProject.h"
#import "DotNetServerReadWriteFile1.tlb" no_namespace named_guids raw_interfaces_only
#include <comutil.h>

// Global Function Declaration
using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK splashWndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK DilogWndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

// Global Variable Declaration
HINSTANCE hIns;
COLORREF dilogColor = RGB(255, 255, 255);

HWND hMainwnd;
HBITMAP hSplashBMP;
HDC hSplashDC;
HDC hMemoryDC;
LONG BitmapWidth, BitmapHeight;
// Entry-Point Function

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{

	// Local Variable Declaration
	WNDCLASSEX wndclass, splashwndclass;
	hIns = hInstance;
	MSG msg;
	HRESULT hr;

	TCHAR szAppName[] = TEXT("WINDEV");

	TCHAR SplashClass[125] = TEXT("Splash Window");

	hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM Initialisation failed"), TEXT("ERROR"), MB_OK);
		exit(0);
	}

	// Code
	// wndclass Structure Initialisation
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(My_Icon2));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// Registration of WNDCLASSEX Mainwindow
	RegisterClassEx(&wndclass);

	// Register splash window
	splashwndclass.hInstance = hInstance;
	splashwndclass.cbSize = sizeof(splashwndclass);
	splashwndclass.lpfnWndProc = splashWndProc;
	splashwndclass.cbClsExtra = NULL;
	splashwndclass.cbWndExtra = NULL;
	splashwndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	splashwndclass.hIcon = NULL;
	splashwndclass.hIconSm = NULL;
	splashwndclass.lpszClassName = SplashClass;
	splashwndclass.style = NULL;
	splashwndclass.lpszMenuName = NULL;
	splashwndclass.hbrBackground = NULL;

	RegisterClassEx(&splashwndclass);

	// Creating the Main Window
	hMainwnd = CreateWindow(
		szAppName,
		TEXT("GRP:Window"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	// Creating Splash Window
	RECT DesktopRect;
	GetWindowRect(GetDesktopWindow(), &DesktopRect);

	hSplashBMP = LoadBitmap(hInstance, MAKEINTRESOURCE(SPLASH_BITMAP));

	BITMAP Bitmap;
	GetObject(hSplashBMP, sizeof(BITMAP), &Bitmap);
	BitmapWidth = Bitmap.bmWidth;
	BitmapHeight = Bitmap.bmHeight;

	HWND hSplashWnd = CreateWindow(SplashClass, TEXT("Splash Screen"), WS_POPUP, (DesktopRect.right - BitmapWidth) / 2, (DesktopRect.bottom - BitmapHeight) / 2, Bitmap.bmWidth, Bitmap.bmHeight, NULL, NULL, hInstance, NULL);
	// HWND hSplashWnd = CreateWindow(SplashClass, TEXT("Splash Screen"), WS_POPUP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	hSplashDC = GetDC(hSplashWnd);
	hMemoryDC = CreateCompatibleDC(hSplashDC);
	SelectObject(hMemoryDC, (HGDIOBJ)hSplashBMP);

	ShowWindow(hSplashWnd, SW_SHOW);
	UpdateWindow(hSplashWnd);

	// Show the Window
	// ShowWindow(hMainwnd, iCmdShow);

	// Update the Window
	// UpdateWindow(hMainwnd);

	// Message Loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	CoUninitialize();

	return (int)msg.wParam;
}

LRESULT CALLBACK splashWndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{

	case WM_ERASEBKGND:
		BitBlt((HDC)wParam, 0, 0, BitmapWidth, BitmapHeight, hMemoryDC, 0, 0, SRCCOPY);
		break;

	case WM_CHAR:
	case WM_KILLFOCUS:
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_MBUTTONDOWN:

		DeleteObject(hSplashBMP);
		ReleaseDC(hwnd, hSplashDC);
		ReleaseDC(hwnd, hMemoryDC);

		DestroyWindow(hwnd);

		DestroyWindow(hMainwnd);
		ShowWindow(hMainwnd, SW_SHOW);
		UpdateWindow(hMainwnd);
		SetForegroundWindow(hMainwnd);

		break;
	default:
		return (DefWindowProc(hwnd, iMsg, wParam, lParam));
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// Local Variable Declaration
	TCHAR str[125];
	static HWND buttonhwnd;
	// Code
	switch (iMsg)
	{
	case WM_CREATE:

		// DialogBox(hIns, MAKEINTRESOURCE(NameQuery), hwnd, DilogWndProc);

		// DestroyWindow(hwnd);

		break;

	case WM_DESTROY:
		// PostQuitMessage(0);
		SetForegroundWindow(hMainwnd);
		DialogBox(hIns, MAKEINTRESOURCE(NameQuery), hwnd, DilogWndProc);

		PostMessage(hwnd, WM_QUIT, 0, 0L);
		break;
	default:
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

LRESULT CALLBACK DilogWndProc(HWND diloghwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	static TCHAR Name[125], Address[125], Education[125], Company[125], date[10], month[10], year[10];
	HWND childHwnd;
	static HBRUSH hbr;
	static int validation_flagName, validation_flagDOB_Date, validation_flagDOB_Month, validation_flagDOB_Year, validation_flagEducation, validation_flagAddress, validation_flagCompany, Enable_win32sdk, Enable_Containment, Enable_Automation;
	static ofstream fileWrite;
	static ifstream fileRead;
	static int WriteFlag;
	TCHAR line[125];
	HRESULT hr;
	IReadFile *pIReadFile = NULL; // ClassFactory

	IWriteDataToFile *pIWriteDataToFile = NULL;			  // Contaiment Inner
	IWriteTimestampToFile *pIWriteTimestampToFile = NULL; // containment outer

	IReadTimeStampAggregation *pIReadTimeStampAggregation = NULL;		// Aggregation Outer
	IReadDataFromFileAggregation *pIReadDataFromFileAggregation = NULL; // Aggregation Inner

	static int IDOfEditControl[10];
	int i, a, j, k;

	static char *strEditName[10] = {"\0"};

	HANDLE hFileWriteHandle, hFileReadHandle;
	char DataBuffer[225], ReadBuffer[556];
	static DWORD lengthOfDataBuffer;
	DWORD NumberOfBytesWritten;
	OVERLAPPED overlapped;
	static TCHAR ch[] = "\n";

	// Automation and DotNet variables
	IDispatch *pIDispatch = NULL;
	OLECHAR *szWriteFunction = L"WriteDataToFileAutomation";
	OLECHAR *szReadFunction = L"ReadFromFile";
	VARIANT vArg[6], vArgRead[2];
	VARIANT vResult, vResultRead;
	DISPID dispid;
	DISPPARAMS params;

	string s;

	char *datastream[5] = {"\0"};

	char datestream[125];
	static char *strFileName = "MyFile2.txt";

	static char *strFileName2 = "MyFileNew.txt";

	char *outputdata;
	long ab;

	TCHAR *pch;
	TCHAR *pch2;
	TCHAR *pch3;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		a = 206;
		for (int i = 0; i < 7; i++)
		{
			IDOfEditControl[i] = a;
			a++;
		}

		SetWindowPos(diloghwnd, HWND_TOP, 300, 100, 400, 400, SWP_NOSIZE);
		hbr = CreateSolidBrush(RGB(102, 102, 255));
		validation_flagName = 0;
		validation_flagDOB_Date = 0;
		validation_flagDOB_Month = 0;
		validation_flagDOB_Year = 0;
		validation_flagEducation = 0;
		validation_flagAddress = 0;
		validation_flagCompany = 0;
		Enable_win32sdk = 1;
		Enable_Containment = 0;
		Enable_Automation = 0;
		WriteFlag = 1;

		return TRUE;

	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case EID_DOB_Date:
			if (WriteFlag == 1)
			{

				GetDlgItemText(diloghwnd, EID_Name, Name, 125);

				strEditName[0] = Name;
				if (strlen(Name) <= 3)
				{
					SetDlgItemText(diloghwnd, SID_NameError, TEXT("Please Enter Valid Name"));
					validation_flagName = 0;
				}
				else
				{
					SetDlgItemText(diloghwnd, SID_NameError, TEXT(""));
					validation_flagName = 1;
				}

				if (validation_flagName == 1 && validation_flagDOB_Date == 1 && validation_flagDOB_Month == 1 && validation_flagDOB_Year == 1 && validation_flagEducation == 1 && validation_flagAddress == 1 && validation_flagCompany == 1)
				{
					if (Enable_win32sdk == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), TRUE);

					if (Enable_Containment == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Containment), TRUE);

					if (Enable_Automation == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Automation), TRUE);
				}
				else
				{

					EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), FALSE);

					EnableWindow(GetDlgItem(diloghwnd, BID_Containment), FALSE);

					EnableWindow(GetDlgItem(diloghwnd, BID_Automation), FALSE);
				}
			}
			break;

		case EID_DOB_Month:

			if (WriteFlag == 1)
			{

				GetDlgItemText(diloghwnd, EID_DOB_Date, date, 10);

				strEditName[1] = date;
				if (strlen(date) <= 0)
					wsprintf(date, TEXT("45"));

				if (!(stoi(date) > 0 && stoi(date) <= 31))
				{
					SetDlgItemText(diloghwnd, SID_DOBError, TEXT("Please Enter Valid Date"));
					validation_flagDOB_Date = 0;
				}
				else
				{
					SetDlgItemText(diloghwnd, SID_DOBError, TEXT(""));
					validation_flagDOB_Date = 1;
				}

				if (validation_flagName == 1 && validation_flagDOB_Date == 1 && validation_flagDOB_Month == 1 && validation_flagDOB_Year == 1 && validation_flagEducation == 1 && validation_flagAddress == 1 && validation_flagCompany == 1)
				{
					if (Enable_win32sdk == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), TRUE);

					if (Enable_Containment == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Containment), TRUE);

					if (Enable_Automation == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Automation), TRUE);
				}
				else
				{

					EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), FALSE);

					EnableWindow(GetDlgItem(diloghwnd, BID_Containment), FALSE);

					EnableWindow(GetDlgItem(diloghwnd, BID_Automation), FALSE);
				}
			}
			break;

		case EID_DOB_Year:

			if (WriteFlag == 1)
			{

				GetDlgItemText(diloghwnd, EID_DOB_Month, month, 10);

				GetDlgItemText(diloghwnd, EID_DOB_Date, date, 10);

				if (strlen(date) <= 0)
					wsprintf(date, TEXT("45"));

				if (strlen(month) <= 0)
					wsprintf(month, TEXT("45"));

				strEditName[1] = date;
				strEditName[2] = month;

				if (!(stoi(month) > 0 && stoi(month) <= 12) || !(stoi(date) > 0 && stoi(date) <= 31))
				{
					SetDlgItemText(diloghwnd, SID_DOBError, TEXT("Please Enter Valid Date"));

					if (!(stoi(month) > 0 && stoi(month) <= 12))
						validation_flagDOB_Month = 0;

					if (!(stoi(date) > 0 && stoi(date) <= 31))
						validation_flagDOB_Date = 0;
				}
				else if (stoi(month) == 2 || stoi(month) == 4 || stoi(month) == 6 || stoi(month) == 9 || stoi(month) == 11)
				{
					if (stoi(date) > 30 || (stoi(month) == 2 && stoi(date) > 29))
					{

						SetDlgItemText(diloghwnd, SID_DOBError, TEXT("Please Enter Valid Date"));

						if (stoi(date) > 30)
							validation_flagDOB_Date = 0;

						if ((stoi(month) == 2 && stoi(date) > 29))
							validation_flagDOB_Month = 0;
					}
					else
					{
						SetDlgItemText(diloghwnd, SID_DOBError, TEXT(""));
						validation_flagDOB_Date = 1;

						validation_flagDOB_Month = 1;
					}
				}
				else
				{
					SetDlgItemText(diloghwnd, SID_DOBError, TEXT(""));
					validation_flagDOB_Date = 1;
					validation_flagDOB_Month = 1;
				}

				if (validation_flagName == 1 && validation_flagDOB_Date == 1 && validation_flagDOB_Month == 1 && validation_flagDOB_Year == 1 && validation_flagEducation == 1 && validation_flagAddress == 1 && validation_flagCompany == 1)
				{
					if (Enable_win32sdk == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), TRUE);

					if (Enable_Containment == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Containment), TRUE);

					if (Enable_Automation == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Automation), TRUE);
				}
				else
				{

					EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), FALSE);

					EnableWindow(GetDlgItem(diloghwnd, BID_Containment), FALSE);

					EnableWindow(GetDlgItem(diloghwnd, BID_Automation), FALSE);
				}
			}
			break;

		case EID_Address:
			if (WriteFlag == 1)
			{

				GetDlgItemText(diloghwnd, EID_DOB_Year, year, 10);
				GetDlgItemText(diloghwnd, EID_DOB_Month, month, 10);
				GetDlgItemText(diloghwnd, EID_DOB_Date, date, 10);

				if (strlen(date) <= 0)
					wsprintf(date, TEXT("45"));

				if (strlen(month) <= 0)
					wsprintf(month, TEXT("45"));

				if (strlen(year) <= 0)
					wsprintf(year, TEXT("45"));

				strEditName[1] = date;
				strEditName[2] = month;
				strEditName[3] = year;
				if (!(stoi(year) >= 1985 && stoi(year) <= 2000) || !(stoi(month) > 0 && stoi(month) <= 12) || !(stoi(date) > 0 && stoi(date) <= 31))
				{

					SetDlgItemText(diloghwnd, SID_DOBError, TEXT("Please Enter Valid Date"));
					validation_flagDOB_Year = 0;
				}
				else if ((stoi(year) == 1988 || stoi(year) == 1992 || stoi(year) == 1996 || stoi(year) == 2000))
				{
					if (stoi(month) == 2 && stoi(date) > 29)
					{

						SetDlgItemText(diloghwnd, SID_DOBError, TEXT("Please Enter Valid Date"));
						validation_flagDOB_Date = 0;
						validation_flagDOB_Month = 0;
						validation_flagDOB_Year = 0;
					}
					else
					{

						SetDlgItemText(diloghwnd, SID_DOBError, TEXT(""));
						validation_flagDOB_Date = 1;

						validation_flagDOB_Month = 1;
						validation_flagDOB_Year = 1;
					}
				}
				else if (!(stoi(year) == 1988 || stoi(year) == 1992 || stoi(year) == 1996 || stoi(year) == 2000))
				{
					if (stoi(month) == 2 && stoi(date) > 28)
					{

						SetDlgItemText(diloghwnd, SID_DOBError, TEXT("Please Enter Valid Date"));
						validation_flagDOB_Date = 0;
						validation_flagDOB_Month = 0;
						validation_flagDOB_Year = 0;
					}
					else
					{

						SetDlgItemText(diloghwnd, SID_DOBError, TEXT(""));
						validation_flagDOB_Date = 1;

						validation_flagDOB_Month = 1;
						validation_flagDOB_Year = 1;
					}
				}
				else
				{

					SetDlgItemText(diloghwnd, SID_DOBError, TEXT(""));
					validation_flagDOB_Date = 1;

					validation_flagDOB_Month = 1;
					validation_flagDOB_Year = 1;
				}

				if (validation_flagName == 1 && validation_flagDOB_Date == 1 && validation_flagDOB_Month == 1 && validation_flagDOB_Year == 1 && validation_flagEducation == 1 && validation_flagAddress == 1 && validation_flagCompany == 1)
				{
					if (Enable_win32sdk == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), TRUE);

					if (Enable_Containment == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Containment), TRUE);

					if (Enable_Automation == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Automation), TRUE);
				}
				else
				{

					EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), FALSE);

					EnableWindow(GetDlgItem(diloghwnd, BID_Containment), FALSE);

					EnableWindow(GetDlgItem(diloghwnd, BID_Automation), FALSE);
				}
			}
			break;

		case EID_Education:

			if (WriteFlag == 1)
			{

				GetDlgItemText(diloghwnd, EID_Address, Address, 125);

				strEditName[4] = Address;

				if (strlen(Address) <= 3)
				{
					SetDlgItemText(diloghwnd, SID_AddressError, TEXT("Please Enter Valid Address"));
					validation_flagAddress = 0;
				}
				else
				{
					SetDlgItemText(diloghwnd, SID_AddressError, TEXT(""));
					validation_flagAddress = 1;
				}

				if (validation_flagName == 1 && validation_flagDOB_Date == 1 && validation_flagDOB_Month == 1 && validation_flagDOB_Year == 1 && validation_flagEducation == 1 && validation_flagAddress == 1 && validation_flagCompany == 1)
				{
					if (Enable_win32sdk == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), TRUE);

					if (Enable_Containment == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Containment), TRUE);

					if (Enable_Automation == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Automation), TRUE);
				}
				else
				{

					EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), FALSE);

					EnableWindow(GetDlgItem(diloghwnd, BID_Containment), FALSE);

					EnableWindow(GetDlgItem(diloghwnd, BID_Automation), FALSE);
				}
			}
			break;

		case EID_Company:

			if (WriteFlag == 1)
			{

				GetDlgItemText(diloghwnd, EID_Education, Education, 125);

				strEditName[5] = Education;

				if (strlen(Education) < 2)
				{
					SetDlgItemText(diloghwnd, SID_EducationError, TEXT("Please Enter Valid Education"));
					validation_flagEducation = 0;
				}
				else
				{
					SetDlgItemText(diloghwnd, SID_EducationError, TEXT(""));
					validation_flagEducation = 1;
				}

				if (validation_flagName == 1 && validation_flagDOB_Date == 1 && validation_flagDOB_Month == 1 && validation_flagDOB_Year == 1 && validation_flagEducation == 1 && validation_flagAddress == 1 && validation_flagCompany == 1)
				{
					if (Enable_win32sdk == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), TRUE);
					if (Enable_Containment == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Containment), TRUE);

					if (Enable_Automation == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Automation), TRUE);
				}
				else
				{

					EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), FALSE);

					EnableWindow(GetDlgItem(diloghwnd, BID_Containment), FALSE);

					EnableWindow(GetDlgItem(diloghwnd, BID_Automation), FALSE);
				}
			}
			break;

		case EID_Validation:

			if (WriteFlag == 1)
			{

				GetDlgItemText(diloghwnd, EID_Company, Company, 125);

				strEditName[6] = Company;

				if (strlen(Company) < 2)
				{
					SetDlgItemText(diloghwnd, SID_CompanyError, TEXT("Please Enter Valid Company"));
					validation_flagCompany = 0;
				}
				else
				{
					SetDlgItemText(diloghwnd, SID_CompanyError, TEXT(""));
					validation_flagCompany = 1;
				}

				if (validation_flagName == 1 && validation_flagDOB_Date == 1 && validation_flagDOB_Month == 1 && validation_flagDOB_Year == 1 && validation_flagEducation == 1 && validation_flagAddress == 1 && validation_flagCompany == 1)
				{
					if (Enable_win32sdk == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), TRUE);

					if (Enable_Containment == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Containment), TRUE);

					if (Enable_Automation == 1)
						EnableWindow(GetDlgItem(diloghwnd, BID_Automation), TRUE);
				}
				else
				{

					EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), FALSE);

					EnableWindow(GetDlgItem(diloghwnd, BID_Containment), FALSE);

					EnableWindow(GetDlgItem(diloghwnd, BID_Automation), FALSE);
				}
			}
			break;

		case BID_Win32Sdk:

			// Win-32 SDK  CPP Write

			fileWrite.open("MyFile2.txt");
			fileWrite << Name << "\n"
					  << date << "/" << month << "/" << year << "\n"
					  << Address << "\n"
					  << Education << "\n"
					  << Company << "\n"
					  << endl;

			Enable_win32sdk = 0;

			EnableWindow(GetDlgItem(diloghwnd, BID_Win32Sdk), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, BID_Classfactory), TRUE);

			WriteFlag = 0;
			SetDlgItemText(diloghwnd, EID_Name, TEXT(""));
			SetDlgItemText(diloghwnd, EID_DOB_Date, TEXT(""));
			SetDlgItemText(diloghwnd, EID_DOB_Month, TEXT(""));
			SetDlgItemText(diloghwnd, EID_DOB_Year, TEXT(""));
			SetDlgItemText(diloghwnd, EID_Education, TEXT(""));
			SetDlgItemText(diloghwnd, EID_Address, TEXT(""));
			SetDlgItemText(diloghwnd, EID_Company, TEXT(""));

			fileWrite.close();

			Enable_Containment = 1;
			return TRUE;

		case BID_Classfactory:

			hr = CoCreateInstance(CLSID_CReadWriteFile, NULL, CLSCTX_INPROC_SERVER, IID_IReadFile, (void **)&pIReadFile);

			if (FAILED(hr))
			{
				MessageBox(NULL, TEXT("IReadFileData Can not be obtained"), TEXT("ERROR"), MB_OK);
			}

			pIReadFile->ReadDataFromFile(diloghwnd, TEXT("MyFile2.txt"), IDOfEditControl);

			if (pIReadFile)
			{
				pIReadFile->Release();
				pIReadFile = NULL;
			}

			EnableWindow(GetDlgItem(diloghwnd, BID_Classfactory), FALSE);

			EnableWindow(GetDlgItem(diloghwnd, EID_Name), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_DOB_Date), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_DOB_Month), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_DOB_Year), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_Address), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_Education), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_Company), FALSE);

			WriteFlag = 1;

			break;

		case BID_Containment:

			overlapped.Offset = 0xFFFFFFFF;
			overlapped.OffsetHigh = 0xFFFFFFFF;
			overlapped.hEvent = 0;
			overlapped.Internal = 0;
			overlapped.InternalHigh = 0;
			overlapped.Pointer = 0;

			Enable_Containment = 0;
			hr = CoCreateInstance(CLSID_CReadWriteData, NULL, CLSCTX_INPROC_SERVER, IID_IWriteDataToFile, (void **)&pIWriteDataToFile);

			if (FAILED(hr))
			{
				MessageBox(NULL, TEXT("IWriteDataToFile Can not be obtained"), TEXT("ERROR"), MB_OK);
			}

			pIWriteDataToFile->WriteDataToFile(diloghwnd, TEXT("MyFile2.txt"), strEditName);

			pIWriteDataToFile->QueryInterface(IID_IWriteTimestampToFile, (void **)&pIWriteTimestampToFile);

			pIWriteTimestampToFile->WriteTimeStampToFile(diloghwnd, TEXT("MyFile2.txt"));

			if (pIWriteTimestampToFile)
			{
				pIWriteTimestampToFile->Release();
				pIWriteTimestampToFile = NULL;
			}

			if (pIWriteDataToFile)
			{
				pIWriteDataToFile->Release();
				pIWriteDataToFile = NULL;
			}

			fileWrite.open("MyFile2.txt", std::ios::out | std::ios::app);
			fileWrite << "\n"
					  << endl;

			fileWrite.close();

			WriteFlag = 0;
			SetDlgItemText(diloghwnd, EID_Name, TEXT(""));
			SetDlgItemText(diloghwnd, EID_DOB_Date, TEXT(""));
			SetDlgItemText(diloghwnd, EID_DOB_Month, TEXT(""));
			SetDlgItemText(diloghwnd, EID_DOB_Year, TEXT(""));
			SetDlgItemText(diloghwnd, EID_Education, TEXT(""));
			SetDlgItemText(diloghwnd, EID_Address, TEXT(""));
			SetDlgItemText(diloghwnd, EID_Company, TEXT(""));

			EnableWindow(GetDlgItem(diloghwnd, BID_Containment), FALSE);

			EnableWindow(GetDlgItem(diloghwnd, BID_Aggregation), TRUE);

			Enable_Automation = 1;
			break;

		case BID_Aggregation:

			hr = CoCreateInstance(CLSID_CReadTimeStampAggregation, NULL, CLSCTX_INPROC_SERVER, IID_IReadTimeStampAggregation, (void **)&pIReadTimeStampAggregation);

			if (FAILED(hr))
			{
				MessageBox(NULL, TEXT("IReadTimeStampAggregation Can not be obtained"), TEXT("ERROR"), MB_OK);
			}

			hr = pIReadTimeStampAggregation->ReadTimeStampAggregation(diloghwnd, TEXT("MyFile2.txt"));

			if (FAILED(hr))
			{
				MessageBox(NULL, TEXT("ReadTimeStampAggregation Failed"), TEXT("ERROR"), MB_OK);
			}

			hr = pIReadTimeStampAggregation->QueryInterface(IID_IReadDataFromFileAggregation, (void **)&pIReadDataFromFileAggregation);

			if (FAILED(hr))
			{
				MessageBox(NULL, TEXT("IReadDataFromFileAggregation Can not be obtained"), TEXT("ERROR"), MB_OK);
			}

			hr = pIReadDataFromFileAggregation->ReadDataFromFileAggregation(diloghwnd, TEXT("MyFile2.txt"), IDOfEditControl);

			if (FAILED(hr))
			{
				MessageBox(NULL, TEXT("ReadDataFromFileAggregation Failed"), TEXT("ERROR"), MB_OK);
			}

			if (pIReadDataFromFileAggregation)
			{
				pIReadDataFromFileAggregation->Release();
				pIReadDataFromFileAggregation = NULL;
			}

			if (pIReadTimeStampAggregation)
			{
				pIReadTimeStampAggregation->Release();
				pIReadTimeStampAggregation = NULL;
			}

			WriteFlag = 1;
			EnableWindow(GetDlgItem(diloghwnd, BID_Aggregation), FALSE);

			EnableWindow(GetDlgItem(diloghwnd, EID_Name), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_DOB_Date), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_DOB_Month), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_DOB_Year), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_Address), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_Education), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_Company), FALSE);

			break;

		case BID_Automation:

			Enable_Automation = 0;
			datastream[0] = strEditName[0];
			datastream[2] = strEditName[4];

			datastream[3] = strEditName[5];

			datastream[4] = strEditName[6];

			wsprintf(datestream, TEXT("%s/%s/%s"), strEditName[1], strEditName[2], strEditName[3]);

			hr = CoCreateInstance(CLSID_CWriteToFileAutomation, NULL, CLSCTX_INPROC_SERVER, IID_IDispatch, (void **)&pIDispatch);

			hr = pIDispatch->GetIDsOfNames(
				IID_NULL,
				&szWriteFunction,
				1,
				GetUserDefaultLCID(),
				&dispid);

			if (FAILED(hr))
			{
				MessageBox(NULL, TEXT("GetIDsOfNames failed to get ID of WriteToFile"), TEXT("Error"), MB_OK);
				pIDispatch->Release();
				pIDispatch = NULL;
			}

			VariantInit(vArg);
			vArg[0].vt = VT_BSTR;
			vArg[0].bstrVal = _com_util::ConvertStringToBSTR(strFileName);

			vArg[1].vt = VT_BSTR;
			vArg[1].bstrVal = _com_util::ConvertStringToBSTR(datastream[4]);

			vArg[2].vt = VT_BSTR;
			vArg[2].bstrVal = _com_util::ConvertStringToBSTR(datastream[3]);

			vArg[3].vt = VT_BSTR;
			vArg[3].bstrVal = _com_util::ConvertStringToBSTR(datastream[2]);

			vArg[4].vt = VT_BSTR;
			vArg[4].bstrVal = _com_util::ConvertStringToBSTR(datestream);

			vArg[5].vt = VT_BSTR;
			vArg[5].bstrVal = _com_util::ConvertStringToBSTR(datastream[0]);

			VariantInit(&vResult); // Initialise vResult by default values

			params.rgvarg = vArg;			 // register variant arguments
			params.cArgs = 6;				 // count of arguments
			params.rgdispidNamedArgs = NULL; // No named arguments
			params.cNamedArgs = 0;			 // Count of named arguments

			hr = pIDispatch->Invoke(
				dispid,
				IID_NULL,
				GetUserDefaultLCID(),
				DISPATCH_METHOD,
				&params, // Input parameters to function
				NULL,	 // Out Prameter of function
				NULL,
				NULL);

			VariantClear(&vResult);
			VariantClear(vArg);

			pIDispatch->Release();
			pIDispatch = NULL;

			WriteFlag = 0;
			SetDlgItemText(diloghwnd, EID_Name, TEXT(""));
			SetDlgItemText(diloghwnd, EID_DOB_Date, TEXT(""));
			SetDlgItemText(diloghwnd, EID_DOB_Month, TEXT(""));
			SetDlgItemText(diloghwnd, EID_DOB_Year, TEXT(""));
			SetDlgItemText(diloghwnd, EID_Education, TEXT(""));
			SetDlgItemText(diloghwnd, EID_Address, TEXT(""));
			SetDlgItemText(diloghwnd, EID_Company, TEXT(""));

			EnableWindow(GetDlgItem(diloghwnd, BID_Automation), FALSE);

			EnableWindow(GetDlgItem(diloghwnd, BID_DotNet), TRUE);

			break;

		case BID_DotNet:

			hr = CoCreateInstance(CLSID_DotNetServerReadWriteFile, NULL, CLSCTX_INPROC_SERVER, IID_IDispatch, (void **)&pIDispatch);

			if (FAILED(hr))
			{
				MessageBox(NULL, TEXT("CO-createInstance Failed to get IDispatch Interface"), TEXT("Error"), MB_OK);
			}

			hr = pIDispatch->GetIDsOfNames(
				IID_NULL,
				&szReadFunction,
				1,
				GetUserDefaultLCID(),
				&dispid);

			if (FAILED(hr))
			{
				MessageBox(NULL, TEXT("GetIDsOfNames failed to get ID of WriteToFile"), TEXT("Error"), MB_OK);
				pIDispatch->Release();
				pIDispatch = NULL;
			}

			VariantInit(vArgRead);
			vArgRead[0].vt = VT_BSTR;
			vArgRead[0].bstrVal = _com_util::ConvertStringToBSTR(strFileName2);

			vArgRead[1].vt = VT_BSTR;
			vArgRead[1].bstrVal = _com_util::ConvertStringToBSTR(strFileName);

			VariantInit(&vResultRead); // Initialise vResult by default values

			params.rgvarg = vArgRead;		 // register variant arguments
			params.cArgs = 2;				 // count of arguments
			params.rgdispidNamedArgs = NULL; // No named arguments
			params.cNamedArgs = 0;			 // Count of named arguments

			hr = pIDispatch->Invoke(
				dispid,
				IID_NULL,
				GetUserDefaultLCID(),
				DISPATCH_METHOD,
				&params, // Input parameters to function
				NULL,	 // Out Prameter of function
				NULL,
				NULL);

			VariantClear(&vResultRead);
			VariantClear(vArgRead);

			pIDispatch->Release();
			pIDispatch = NULL;

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

			EnableWindow(GetDlgItem(diloghwnd, EID_Name), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_DOB_Date), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_DOB_Month), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_DOB_Year), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_Address), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_Education), FALSE);
			EnableWindow(GetDlgItem(diloghwnd, EID_Company), FALSE);

			EnableWindow(GetDlgItem(diloghwnd, BID_DotNet), FALSE);

			break;

		case BID_Reset:

			WriteFlag = 0;
			SetDlgItemText(diloghwnd, EID_Name, TEXT(""));
			SetDlgItemText(diloghwnd, EID_DOB_Date, TEXT(""));
			SetDlgItemText(diloghwnd, EID_DOB_Month, TEXT(""));
			SetDlgItemText(diloghwnd, EID_DOB_Year, TEXT(""));
			SetDlgItemText(diloghwnd, EID_Education, TEXT(""));
			SetDlgItemText(diloghwnd, EID_Address, TEXT(""));
			SetDlgItemText(diloghwnd, EID_Company, TEXT(""));

			EnableWindow(GetDlgItem(diloghwnd, EID_Name), TRUE);
			EnableWindow(GetDlgItem(diloghwnd, EID_DOB_Date), TRUE);
			EnableWindow(GetDlgItem(diloghwnd, EID_DOB_Month), TRUE);
			EnableWindow(GetDlgItem(diloghwnd, EID_DOB_Year), TRUE);
			EnableWindow(GetDlgItem(diloghwnd, EID_Address), TRUE);
			EnableWindow(GetDlgItem(diloghwnd, EID_Education), TRUE);
			EnableWindow(GetDlgItem(diloghwnd, EID_Company), TRUE);
			WriteFlag = 1;

			validation_flagName = 0;
			validation_flagDOB_Date = 0;
			validation_flagDOB_Month = 0;
			validation_flagAddress = 0;
			validation_flagEducation = 0;
			validation_flagCompany = 0;

			break;
		}
		break;

	case WM_CTLCOLORDLG:

		return (INT_PTR)hbr;

	case WM_CTLCOLORSTATIC:

		if ((HWND)lParam == GetDlgItem(diloghwnd, SID_NameError) || (HWND)lParam == GetDlgItem(diloghwnd, SID_DOBError) || (HWND)lParam == GetDlgItem(diloghwnd, SID_AddressError) || (HWND)lParam == GetDlgItem(diloghwnd, SID_EducationError) || (HWND)lParam == GetDlgItem(diloghwnd, SID_CompanyError))
		{
			SetTextColor((HDC)wParam, RGB(255, 0, 0));
		}

		SetBkColor((HDC)wParam, RGB(102, 102, 255));

		if ((HWND)lParam == GetDlgItem(diloghwnd, EID_Name) || (HWND)lParam == GetDlgItem(diloghwnd, EID_DOB_Date) || (HWND)lParam == GetDlgItem(diloghwnd, EID_DOB_Month) || (HWND)lParam == GetDlgItem(diloghwnd, EID_DOB_Year) || (HWND)lParam == GetDlgItem(diloghwnd, EID_Address) || (HWND)lParam == GetDlgItem(diloghwnd, EID_Education) || (HWND)lParam == GetDlgItem(diloghwnd, EID_Company))
		{
			SetBkColor((HDC)wParam, RGB(255, 255, 255));
		}
		else
		{

			SetBkColor((HDC)wParam, RGB(102, 102, 255));
		}

		if ((HWND)lParam == GetDlgItem(diloghwnd, EID_Name) || (HWND)lParam == GetDlgItem(diloghwnd, EID_DOB_Date) || (HWND)lParam == GetDlgItem(diloghwnd, EID_DOB_Month) || (HWND)lParam == GetDlgItem(diloghwnd, EID_DOB_Year) || (HWND)lParam == GetDlgItem(diloghwnd, EID_Address) || (HWND)lParam == GetDlgItem(diloghwnd, EID_Education) || (HWND)lParam == GetDlgItem(diloghwnd, EID_Company))
		{
			return ((INT_PTR)GetStockObject(WHITE_BRUSH));
		}

		return (INT_PTR)hbr;

	case WM_DESTROY:
		DeleteObject(hbr);
		EndDialog(diloghwnd, 0);
		return TRUE;
	}
	return DefWindowProc(diloghwnd, iMsg, wParam, lParam);
}
