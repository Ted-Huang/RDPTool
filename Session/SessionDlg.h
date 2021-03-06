
// SessionDlg.h : 標頭檔
//

#pragma once
#include "RDPSession.h"
#include "NDKClient.h"
#include "MasterSlave.h"
#include "netadapter.h"

#define IDT_RETRY_TIMER 1
// CSessionDlg 對話方塊
class CSessionDlg : public CDialogEx, public CNDKClient
{
	// 建構
public:
	CSessionDlg(CWnd* pParent = NULL);	// 標準建構函式
	~CSessionDlg();
	// 對話方塊資料
	enum { IDD = IDD_SESSION_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


	// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSendString();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnWindowPosChanging(WINDOWPOS FAR* lpwndpos);
	DECLARE_MESSAGE_MAP()

private:
	void Init();
	void Finalize();
	void InitUiRectPos();
	void InitUi();
	void DestroyUi();
	void DetectNetApapter();
	void Connect();
protected:
	virtual void OnMessage(CNDKMessage& message);
	virtual void OnDisconnect(NDKClientDisconnection disconnectionType);
private:
	typedef struct UI_ITEM_{
		RECT rcUi;
		void *pCtrl;
	}UI_ITEM;
	enum{
		UI_POS_ITEM_BEGIN = 10,
		//BTN
		UI_POS_BTN_BEGIN,
		UI_POS_BTN_SEND = UI_POS_BTN_BEGIN,
		UI_POS_BTN_END,

		//EDIT
		UI_POS_EDIT_BEGIN,
		UI_POS_EDIT_CONNTIONSTRING = UI_POS_EDIT_BEGIN,
		UI_POS_EDIT_END,

		//LABEL
		UI_POS_LABEL_BEGIN,
		UI_POS_LABEL_CONNECTIONINFO = UI_POS_LABEL_BEGIN,
		UI_POS_LABEL_END,

		UI_POS_ITEM_END,
	};
	UI_ITEM m_xUi[UI_POS_ITEM_END];
	CRDPSession m_xSession;
	CString	m_serverIP;
	CString m_localIP;
	BOOL m_bVisible;
};
