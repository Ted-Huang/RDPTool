
// SessionDlg.h : ���Y��
//

#pragma once
#include "RDPSession.h"

// CSessionDlg ��ܤ��
class CSessionDlg : public CDialogEx
{
// �غc
public:
	CSessionDlg(CWnd* pParent = NULL);	// �зǫغc�禡
	~CSessionDlg();
// ��ܤ�����
	enum { IDD = IDD_SESSION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSendString();
	DECLARE_MESSAGE_MAP()

private:
	void Init();
	void Finalize();
	void InitUiRectPos();
	void InitUi();
	void DestroyUi();

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

		UI_POS_ITEM_END,
	};
	UI_ITEM m_xUi[UI_POS_ITEM_END];
	CRDPSession m_xSession;
};
