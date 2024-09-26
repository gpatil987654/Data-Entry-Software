#pragma once

class IWriteTimestampToFile :public IUnknown
{

public:
	virtual HRESULT __stdcall WriteTimeStampToFile(HWND, LPCSTR)=0;
};

class IReadTimestampFromFile :public IUnknown
{

public:
	virtual HRESULT __stdcall ReadTimeStampFromFile(HWND, LPCSTR)=0;
};

// {CBF07BEF-9191-4C47-9332-C4CF10D3478D}
const CLSID CLSID_CReadWriteTimestamp = { 0xcbf07bef, 0x9191, 0x4c47, 0x93, 0x32, 0xc4, 0xcf, 0x10, 0xd3, 0x47, 0x8d };


// {CAB3F6C7-9219-4F1D-BAF4-32B10E888504}
const IID IID_IWriteTimestampToFile = { 0xcab3f6c7, 0x9219, 0x4f1d, 0xba, 0xf4, 0x32, 0xb1, 0xe, 0x88, 0x85, 0x4 };


// {96431D4A-1B4D-402A-8B95-CBA8DFBE06E9}
const IID IID_IReadTimestampFromFile = { 0x96431d4a, 0x1b4d, 0x402a, 0x8b, 0x95, 0xcb, 0xa8, 0xdf, 0xbe, 0x6, 0xe9 };



