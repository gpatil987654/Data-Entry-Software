#pragma once
class IReadFile :public IUnknown
{

public:
	virtual HRESULT __stdcall ReadDataFromFile(HWND, LPCSTR,int*) = 0;

};

class IWriteFile :public IUnknown
{

public:
	virtual HRESULT __stdcall WriteDataToFile(HWND, int) = 0;

};


// {5BF9DE4F-FA19-4DC6-A314-52E56D64694B}
const CLSID CLSID_CReadWriteFile = { 0x5bf9de4f, 0xfa19, 0x4dc6, 0xa3, 0x14, 0x52, 0xe5, 0x6d, 0x64, 0x69, 0x4b };


// {4764287D-1F59-4E36-965A-01859C9A65FA}
const IID IID_IReadFile = { 0x4764287d, 0x1f59, 0x4e36, 0x96, 0x5a, 0x1, 0x85, 0x9c, 0x9a, 0x65, 0xfa };


// {D3159917-75F3-4391-A9A5-8B86B50C4821}
const IID IID_IWriteFile = { 0xd3159917, 0x75f3, 0x4391, 0xa9, 0xa5, 0x8b, 0x86, 0xb5, 0xc, 0x48, 0x21 };



