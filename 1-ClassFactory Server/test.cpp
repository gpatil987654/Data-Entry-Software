//Headers Files
#include<windows.h> //<> is used when it is in path of sdk
//#include"Window.h"   //" " used when it is our directory path
#include"ClassFactoryReadFile.h"
//Global Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global Variable Declaration

//Entry-Point Function

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{

	//Local Variable Declaration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("WINDEV");
	HRESULT hr;

	//Code
	// COM Library Initialisation
	hr = CoInitialize(NULL);

	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM Initialisation failed"), TEXT("ERROR"), MB_OK);
		exit(0);
	}


	//wndclass Structure Initialisation
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//Registration of WNDCLASSEX
	RegisterClassEx(&wndclass);

	//Creating the Window
	hwnd = CreateWindow(
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

	//Show the Window
	ShowWindow(hwnd, iCmdShow);

	//Update the Window
	UpdateWindow(hwnd);


	//Message Loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//COM Uninitialisation
	CoUninitialize();



	return (int)msg.wParam;

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Local Variable Declaration
	TCHAR str[255];
	IReadFile* pIReadFile = NULL;
	HRESULT hr;
	int n1, n2, sum, sub;


	//Code
	switch (iMsg)
	{
	case WM_CREATE:
		hr = CoCreateInstance(CLSID_CReadWriteFile, NULL, CLSCTX_INPROC_SERVER, IID_IReadFile, (void**)&pIReadFile);

		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("ISUM Can not be obtained"), TEXT("ERROR"), MB_OK);
			DestroyWindow(hwnd);
		}
		
		n1 = 55;
		n2 = 45;

		//pIReadFile->WriteDatatoFile(hwnd,n1);

		//wsprintf(str, TEXT("Sum of %d and %d is %d"), n1, n2, sum);
		MessageBox(hwnd, TEXT("Hi"), TEXT("Summation"), MB_OK);
		/*
		pISum->QueryInterface(IID_ISubstract, (void**)&pISubstract);

		pISubstract->SubstractionOfTwoIntegers(n1, n2, &sub);

		wsprintf(str, TEXT("Substraction of %d and %d is %d"), n1, n2, sub);
		MessageBox(hwnd, str, TEXT("Substraction"), MB_OK);


		//Safe Release
		if (pISubstract)
		{
			pISubstract->Release();
			pISubstract = NULL;

		}
		if (pISum)
		{
			pISum->Release();
			pISum = NULL;
		}

		DestroyWindow(hwnd);//send WM_Destroy
		*/
		pIReadFile->Release();
		pIReadFile = NULL;
		DestroyWindow(hwnd);
		break;

	case WM_KEYDOWN:
		wsprintf(str, TEXT("WM_KEYDOWN Message is recieved"));
		MessageBox(hwnd, str, TEXT("MESSAGE"), MB_OK);
		break;

	case WM_DESTROY:
		//PostQuitMessage(0);
		PostMessage(hwnd, WM_QUIT, 0, 0L);
		break;
	default:
		break;

	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);

}

