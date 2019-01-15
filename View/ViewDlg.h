
// ViewDlg.h : ���Y��
//

#pragma once
#include "RDPView.h"
#include <vector>
using namespace std;
// CViewDlg ��ܤ��
class CViewDlg : public CDialogEx
{
// �غc
public:
	CViewDlg(CWnd* pParent = NULL);	// �зǫغc�禡
	~CViewDlg();
// ��ܤ�����
	enum { IDD = IDD_VIEW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
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
