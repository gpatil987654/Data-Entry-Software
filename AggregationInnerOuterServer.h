#pragma once
class IReadTimeStampAggregation :public IUnknown
{
public:

	virtual HRESULT __stdcall ReadTimeStampAggregation(HWND, LPCSTR) = 0;
};


class IReadDataFromFileAggregation :public IUnknown
{

public:
	virtual HRESULT __stdcall ReadDataFromFileAggregation(HWND, LPCSTR, int*) = 0;
};


// {BB7608C3-99DC-4389-BB4A-9BE4C1EC6AD6}
const CLSID CLSID_CReadTimeStampAggregation = { 0xbb7608c3, 0x99dc, 0x4389, 0xbb, 0x4a, 0x9b, 0xe4, 0xc1, 0xec, 0x6a, 0xd6 };


// {DB4F1186-395F-4E27-A8C4-26D49AB1E395}
const CLSID CLSID_CReadDataAggregation = { 0xdb4f1186, 0x395f, 0x4e27, 0xa8, 0xc4, 0x26, 0xd4, 0x9a, 0xb1, 0xe3, 0x95 };


// {D3A0EBDC-A46A-410F-AC91-54A1E5452B0E}
const IID IID_IReadTimeStampAggregation = { 0xd3a0ebdc, 0xa46a, 0x410f, 0xac, 0x91, 0x54, 0xa1, 0xe5, 0x45, 0x2b, 0xe };

// {9EB03596-985E-4900-BAFA-906298A8CBAE}
const IID IID_IReadDataFromFileAggregation = { 0x9eb03596, 0x985e, 0x4900, 0xba, 0xfa, 0x90, 0x62, 0x98, 0xa8, 0xcb, 0xae };


