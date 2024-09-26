#pragma once


class IWriteToFileUsingDotNetServer :public IUnknown
{
public:
	
	virtual HRESULT __stdcall WriteDataToFileUsingDotNetServer(char*, char*, char*, char*, char*, char*) = 0;

};


// {30DF6F0A-1378-4C02-962A-8C59F870727B}
const CLSID CLSID_CWriteToFileUsingDotNetServer = { 0x30df6f0a, 0x1378, 0x4c02, 0x96, 0x2a, 0x8c, 0x59, 0xf8, 0x70, 0x72, 0x7b };

// {0ED74FE4-57EE-4F52-91CA-B5A7683E7B6C}
const IID IID_IWriteToFileUsingDotNetServer = { 0xed74fe4, 0x57ee, 0x4f52, 0x91, 0xca, 0xb5, 0xa7, 0x68, 0x3e, 0x7b, 0x6c };


