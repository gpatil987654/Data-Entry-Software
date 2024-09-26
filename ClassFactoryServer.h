#pragma once

#include<Windows.h>

class IReadFileData:public IUnknown
{
public:
	//virtual HRESULT __stdcall ReadData(HWND, LPSTR, int*) = 0;

	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0;
};


// {F54DE1DB-88BE-440E-B12B-4111CC2C6BF0}
const CLSID CLSID_CReadFileData = { 0xf54de1db, 0x88be, 0x440e, 0xb1, 0x2b, 0x41, 0x11, 0xcc, 0x2c, 0x6b, 0xf0 };


// {D1C7E4DA-B6D4-4BB3-A39F-BB68AD99B07E}
const IID IID_IReadFileDaata = { 0xd1c7e4da, 0xb6d4, 0x4bb3, 0xa3, 0x9f, 0xbb, 0x68, 0xad, 0x99, 0xb0, 0x7e };


