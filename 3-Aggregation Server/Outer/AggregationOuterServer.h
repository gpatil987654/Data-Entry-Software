#pragma once
class IReadTimeStampAggregation :public IUnknown
{
public:

	virtual HRESULT __stdcall ReadTimeStampAggregation(HWND, LPCSTR) = 0;
};


// {BB7608C3-99DC-4389-BB4A-9BE4C1EC6AD6}
const CLSID CLSID_CReadTimeStampAggregation = { 0xbb7608c3, 0x99dc, 0x4389, 0xbb, 0x4a, 0x9b, 0xe4, 0xc1, 0xec, 0x6a, 0xd6 };


// {D3A0EBDC-A46A-410F-AC91-54A1E5452B0E}
const IID IID_IReadTimeStampAggregation = { 0xd3a0ebdc, 0xa46a, 0x410f, 0xac, 0x91, 0x54, 0xa1, 0xe5, 0x45, 0x2b, 0xe };

