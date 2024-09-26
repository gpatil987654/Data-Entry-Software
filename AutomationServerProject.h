#pragma once


class IWriteToFileAutomation :public IDispatch
{
public:
	
	virtual HRESULT __stdcall WriteDataToFileAutomation(BSTR, BSTR, BSTR, BSTR, BSTR, BSTR) = 0;

};


// {B1BA2D99-9FB4-4724-B274-8BE0136E656F}
const CLSID CLSID_CWriteToFileAutomation = { 0xb1ba2d99, 0x9fb4, 0x4724, 0xb2, 0x74, 0x8b, 0xe0, 0x13, 0x6e, 0x65, 0x6f };



// {E79B1EF0-03F6-4490-AC60-6EBC286D9754}
const IID IID_IWriteToFileAutomation = { 0xe79b1ef0, 0x3f6, 0x4490, 0xac, 0x60, 0x6e, 0xbc, 0x28, 0x6d, 0x97, 0x54 };


