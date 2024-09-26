#pragma once

class IWriteDataToFile :public IUnknown
{

public:
	virtual HRESULT __stdcall WriteDataToFile(HWND, LPCSTR,char**) = 0;

};


class IReadDataFromFile :public IUnknown
{

public:
	virtual HRESULT __stdcall ReadDataFromFile(HWND, LPCSTR) = 0;

};

// {9731EF17-140F-4704-934E-681C3D5B7A11}
const CLSID CLSID_CReadWriteData = { 0x9731ef17, 0x140f, 0x4704, 0x93, 0x4e, 0x68, 0x1c, 0x3d, 0x5b, 0x7a, 0x11 };


// {B31A63A1-3A82-4A88-B578-A159FFEFDA00}
const IID IID_IWriteDataToFile = { 0xb31a63a1, 0x3a82, 0x4a88, 0xb5, 0x78, 0xa1, 0x59, 0xff, 0xef, 0xda, 0x0 };


// {8A140218-0C80-492D-8054-DC3E0AC2FAD1}
const IID IID_IReadDataFromFile = { 0x8a140218, 0xc80, 0x492d, 0x80, 0x54, 0xdc, 0x3e, 0xa, 0xc2, 0xfa, 0xd1 };

