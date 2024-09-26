#pragma once

class IReadDataFromFileAggregation :public IUnknown
{

public:
	virtual HRESULT __stdcall ReadDataFromFileAggregation(HWND, LPCSTR,int*) = 0;
};



// {DB4F1186-395F-4E27-A8C4-26D49AB1E395}
const CLSID CLSID_CReadDataAggregation = { 0xdb4f1186, 0x395f, 0x4e27, 0xa8, 0xc4, 0x26, 0xd4, 0x9a, 0xb1, 0xe3, 0x95 };



// {9EB03596-985E-4900-BAFA-906298A8CBAE}
const IID IID_IReadDataFromFileAggregation = { 0x9eb03596, 0x985e, 0x4900, 0xba, 0xfa, 0x90, 0x62, 0x98, 0xa8, 0xcb, 0xae };



