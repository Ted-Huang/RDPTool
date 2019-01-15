#pragma once

//電腦已經從 Typelib 精靈以加入類別方式產生 IDispatch 包裝函式類別
#pragma once

#include <vector>
using namespace std;
class CRDPSRAPIViewer : public CWnd
{
protected:
	DECLARE_DYNCREATE(CRDPSRAPIViewer)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x32BE5ED2, 0x5C86, 0x480F, { 0xA9, 0x14, 0xF, 0xF8, 0x88, 0x5A, 0x1B, 0x3F } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID);
	}

	BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
		UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
			pPersist, bStorage, bstrLicKey);
	}
	// 屬性
public:

	// 作業
public:


	// IRDPSRAPIViewer 方法
public:
	void Connect(LPCTSTR bstrConnectionString, LPCTSTR bstrName, LPCTSTR bstrPassword)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bstrConnectionString, bstrName, bstrPassword);
	}
	void Disconnect()
	{
		InvokeHelper(0x69, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	LPDISPATCH get_Attendees()
	{
		LPDISPATCH result;
		InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Invitations()
	{
		LPDISPATCH result;
		InvokeHelper(0xcc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_ApplicationFilter()
	{
		LPDISPATCH result;
		InvokeHelper(0xd7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_VirtualChannelManager()
	{
		LPDISPATCH result;
		InvokeHelper(0xce, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void put_SmartSizing(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0xee, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_SmartSizing()
	{
		BOOL result;
		InvokeHelper(0xee, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void RequestControl(long CtrlLevel)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, CtrlLevel);
	}
	void put_DisconnectedText(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xed, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_DisconnectedText()
	{
		CString result;
		InvokeHelper(0xed, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void RequestColorDepthChange(long Bpp)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x73, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Bpp);
	}
	LPDISPATCH get_Properties()
	{
		LPDISPATCH result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString StartReverseConnectListener(LPCTSTR bstrConnectionString, LPCTSTR bstrUserName, LPCTSTR bstrPassword)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0x74, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, bstrConnectionString, bstrUserName, bstrPassword);
		return result;
	}

	// IRDPSRAPIViewer 屬性
public:

};
