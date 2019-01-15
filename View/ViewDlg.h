
// ViewDlg.h : 標頭檔
//

#pragma once
#include "RDPView.h"
#include <vector>
using namespace std;
// CViewDlg 對話方塊
class CViewDlg : public CDialogEx
{
// 建構
public:
	CViewDlg(CWnd* pParent = NULL);	// 標準建構函式
	~CViewDlg();
// 對話方塊資料
	enum { IDD = IDD_VIEW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual void OnCancel();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	DECLARE_MESSAGE_MAP()
private:
	void Init();
	void Finalize();
	void InitUiRectPos();
	void InitUi();
	void DestroyUi();

private:
	vector<pair<int, CString>> m_vConnectionString;
	typedef struct UI_ITEM_{
		RECT rcUi;
		void *pCtrl;
	}UI_ITEM;
	enum{
		UI_POS_ITEM_BEGIN = 0,
		//BTN
		UI_POS_BTN_BEGIN,
		UI_POS_BTN_CONNECT = UI_POS_BTN_BEGIN,
		UI_POS_BTN_END,

		//CB
		UI_POS_CB_BEGIN,
		UI_POS_CB_SLAVES = UI_POS_CB_BEGIN,
		UI_POS_CB_END,

		//EDIT
		UI_POS_EDIT_BEGIN,
		UI_POS_EDIT_CONNTIONSTRING = UI_POS_EDIT_BEGIN,
		UI_POS_EDIT_END,

		//RDPVIEW
		UI_POS_RDPVIEW_BEGIN,
		UI_POS_RDPVIEW_RDPVIEW = UI_POS_RDPVIEW_BEGIN,
		UI_POS_RDPVIEW_END,
		UI_POS_ITEM_END,
	};
	UI_ITEM m_xUi[UI_POS_ITEM_END];
};
