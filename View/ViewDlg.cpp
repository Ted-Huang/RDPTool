
// ViewDlg.cpp : ��@��
//

#include "stdafx.h"
#include "View.h"
#include "ViewDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CViewDlg ��ܤ��



CViewDlg::CViewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CViewDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CViewDlg::~CViewDlg()
{
	Finalize();
}

void CViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CViewDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(UI_POS_BTN_CONNECT, OnConnect)
END_MESSAGE_MAP()


// CViewDlg �T���B�z�`��

BOOL CViewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �]�w����ܤ�����ϥܡC�����ε{�����D�������O��ܤ���ɡA
	// �ج[�|�۰ʱq�Ʀ��@�~
	SetIcon(m_hIcon, TRUE);			// �]�w�j�ϥ�
	SetIcon(m_hIcon, FALSE);		// �]�w�p�ϥ�

	// TODO:  �b���[�J�B�~����l�]�w
	Init();
	InitUiRectPos();
	InitUi();
	return TRUE;  // �Ǧ^ TRUE�A���D�z�ﱱ��]�w�J�I
}

BOOL CViewDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wControlID = LOWORD(wParam);
	WORD wMessageID = HIWORD(wParam);

	if (wControlID != 0) {
		switch (wControlID) {
		case IDCANCEL:
			OnCancel();
			return TRUE;
			break;
		default:
			CDialogEx::OnCommand(wParam, lParam);
			break;
		}
	}
}

void CViewDlg::OnCancel()
{
	CDialogEx::OnCancel();
}

// �p�G�N�̤p�ƫ��s�[�J�z����ܤ���A�z�ݭn�U�C���{���X�A
// �H�Kø�s�ϥܡC���ϥΤ��/�˵��Ҧ��� MFC ���ε{���A
// �ج[�|�۰ʧ������@�~�C

void CViewDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ø�s���˸m���e

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N�ϥܸm����Τ�ݯx��
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �yø�ϥ�
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ��ϥΪ̩즲�̤p�Ƶ����ɡA
// �t�ΩI�s�o�ӥ\����o�����ܡC
HCURSOR CViewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CViewDlg::OnConnect()
{
	if (!m_xUi[UI_POS_RDPVIEW_RDPVIEW].pCtrl || !m_xUi[UI_POS_EDIT_CONNTIONSTRING].pCtrl){
		return;
	}

	int nSel = ((CComboBox*)m_xUi[UI_POS_CB_SLAVES].pCtrl)->GetCurSel();
	if (nSel == -1)
		return;
	pair<CString, CString>* pData = (pair<CString, CString>*)((CComboBox*)m_xUi[UI_POS_CB_SLAVES].pCtrl)->GetItemData(nSel);
	CString strSession = pData->second;
	CString strEdit;
	((CEdit*)m_xUi[UI_POS_EDIT_CONNTIONSTRING].pCtrl)->GetWindowText(strEdit);
	if (strEdit.GetLength() > 0)
		strSession = strEdit;
	try
	{
		((CRDPSRAPIViewer*)m_xUi[UI_POS_RDPVIEW_RDPVIEW].pCtrl)->Connect(strSession, L"groupName", L"");
	}
	catch (...)
	{
		AfxMessageBox(L"RDP error!");
	}
}

void CViewDlg::Init()
{
	CRect rcDesktop;
	// Get a handle to the desktop window
	HWND hDesktop = ::GetDesktopWindow();
	// Get the size of screen to the variable desktop
	::GetWindowRect(hDesktop, &rcDesktop);
	MoveWindow(0, 0, rcDesktop.Width(), rcDesktop.Height());
	memset(m_xUi, 0, sizeof(m_xUi));

	if (!StartListening(ServerListenPort))
		TRACE("socket sever start Fail! \n");
}

void CViewDlg::Finalize()
{
	DestroyUi();
}

#define CONTROL_HEIGHT 50
void CViewDlg::InitUiRectPos()
{
	POINT ptBase = { 0, 0 };
	POINT ptSize = { 0, 0 };
	CRect rcClient;
	GetClientRect(rcClient);
	for (int i = UI_POS_ITEM_BEGIN; i < UI_POS_ITEM_END; i++){
		UINT uImgId = 0;
		UINT uLanId = 0;
		switch (i){
			//BTN
		case UI_POS_BTN_CONNECT:
			ptBase = { 0, 0 };
			ptSize = { 50, CONTROL_HEIGHT };
			break;
			//CB
		case UI_POS_CB_SLAVES:
			ptBase = { 50, 0 };
			ptSize = { 150, CONTROL_HEIGHT };
			break;
			//edit
		case UI_POS_EDIT_CONNTIONSTRING: //for test
			ptBase = { 200, 0 };
			ptSize = { 1500, CONTROL_HEIGHT };
			break;
			//view
		case UI_POS_RDPVIEW_RDPVIEW:
			ptBase = { 0, CONTROL_HEIGHT };
			ptSize = { rcClient.Width(), rcClient.Height() - CONTROL_HEIGHT };
			break;
		}

		m_xUi[i].rcUi = { ptBase.x, ptBase.y, ptBase.x + ptSize.x, ptBase.y + ptSize.y };
	}
}

void CViewDlg::InitUi()
{
	//testing 
	m_vConnectionString.push_back(make_pair(L"123", L"123"));
	CString strCaption;
	//BTN
	for (int i = UI_POS_BTN_BEGIN; i < UI_POS_BTN_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CButton();
			strCaption = (i == UI_POS_BTN_CONNECT) ? L"�s�u" : L"";
			((CButton*)m_xUi[i].pCtrl)->Create(strCaption, WS_VISIBLE | WS_CHILD | WS_TABSTOP, m_xUi[i].rcUi, this, i);
		}
	}
	//CB
	for (int i = UI_POS_CB_BEGIN; i < UI_POS_CB_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CComboBox();
			((CComboBox*)m_xUi[i].pCtrl)->Create(WS_CHILD | WS_TABSTOP | WS_VISIBLE | CBS_DROPDOWNLIST, m_xUi[i].rcUi, this, i);
		}
		if (m_vConnectionString.size()>0 && m_xUi[UI_POS_CB_SLAVES].pCtrl){
			for (int i = 0; i < m_vConnectionString.size(); i++){
				CString str;
				str.Format(_T("Slave: %s"), m_vConnectionString.at(i).first);
				((CComboBox*)m_xUi[UI_POS_CB_SLAVES].pCtrl)->AddString(str);
				((CComboBox*)m_xUi[UI_POS_CB_SLAVES].pCtrl)->SetItemData(i, (DWORD)&m_vConnectionString.at(i));
			}

		}
	}
	//EDIT
	for (int i = UI_POS_EDIT_BEGIN; i < UI_POS_EDIT_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CEdit();
			((CEdit*)m_xUi[i].pCtrl)->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_LEFT | WS_BORDER, m_xUi[i].rcUi, this, i);
		}
	}
	//RDPVIEW
	for (int i = UI_POS_RDPVIEW_BEGIN; i < UI_POS_RDPVIEW_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CRDPSRAPIViewer();
			((CRDPSRAPIViewer*)m_xUi[i].pCtrl)->Create(L"", WS_CHILD | WS_VISIBLE, m_xUi[i].rcUi, this, i);
		}
	}

}

void CViewDlg::DestroyUi()
{
	//BTN
	for (int i = UI_POS_BTN_BEGIN; i < UI_POS_BTN_END; i++){
		if (m_xUi[i].pCtrl){
			CButton* pBtn = ((CButton*)m_xUi[i].pCtrl);
			pBtn->DestroyWindow();
			delete pBtn;
			pBtn = NULL;
		}
	}
	//CB
	for (int i = UI_POS_CB_BEGIN; i < UI_POS_CB_END; i++){
		if (m_xUi[i].pCtrl){
			CComboBox* pCB = ((CComboBox*)m_xUi[i].pCtrl);
			pCB->DestroyWindow();
			delete pCB;
			pCB = NULL;
		}
	}
	//EDIT
	for (int i = UI_POS_EDIT_BEGIN; i < UI_POS_EDIT_END; i++){
		if (m_xUi[i].pCtrl){
			CEdit* pEdit = ((CEdit*)m_xUi[i].pCtrl);
			pEdit->DestroyWindow();
			delete pEdit;
			pEdit = NULL;
		}
	}

	//RDPVIEW
	for (int i = UI_POS_RDPVIEW_BEGIN; i < UI_POS_RDPVIEW_END; i++){
		if (m_xUi[i].pCtrl){
			CRDPSRAPIViewer* pView = ((CRDPSRAPIViewer*)m_xUi[i].pCtrl);
			pView->DestroyWindow();
			delete pView;
			pView = NULL;
		}
	}

}

////////////////////////////////////////////////////////////////////////////////
// NDK Server Functions

// Called when a user tries to connect to the server. Return TRUE to accept
// the connection or FALSE otherwise. The derived class must override this
// method.
BOOL CViewDlg::OnIsConnectionAccepted()
{
	return (GetNbUsers() <= MAXCLIENT);
}

// Called when a user is connected to the server. The derived class must 
// override this method.
void CViewDlg::OnConnect(long lUserId)
{
}
// Called whenever a message is received from a user. The derived class must 
// override this method.
void CViewDlg::OnMessage(long lUserId, CNDKMessage& message)
{
	switch (message.GetId())
	{
	case DM_RDPSESSION_CONNECTIONSTRING:
		{
			pair<CString, CString> data;
			message.GetNext(data.first);
			message.GetNext(data.second);
			pair<CString, CString> * pOrign = NULL;
			for (int x = 0; x < m_vConnectionString.size(); x++){
				if (lstrcmp(m_vConnectionString.at(x).first, data.first) == 0){
					pOrign = &m_vConnectionString.at(x);
					break;
				}
			}

			if (pOrign){ // update
				pOrign->second = data.second;
			}
			else{
				m_vConnectionString.push_back(data);
				if (m_xUi[UI_POS_CB_SLAVES].pCtrl){
					CString str;
					str.Format(_T("Slave: %s"), data.first);
					int nItem = ((CComboBox*)m_xUi[UI_POS_CB_SLAVES].pCtrl)->AddString(str);
					((CComboBox*)m_xUi[UI_POS_CB_SLAVES].pCtrl)->SetItemData(nItem, (DWORD)&m_vConnectionString.at(m_vConnectionString.size() - 1));
				}
			}

			TRACE(L"ya! %s \n", data.second);
		}
		break;
	default:
		break;
	}
	
}

// Called whenever a user is disconnected (the the user might have closed 
// the connection or an error occurs when sending a message, for example). 
// OnDisconnect callback isn't called when DisconnectUser or 
// DisconnectAllUsers is used. DisconnectUser don't
// need to be called when OnDisconnect callback is called. The derived class
// must override this method.
void CViewDlg::OnDisconnect(long lUserId, NDKServerDisconnection disconnectionType)
{
	UINT unResId = 0;
	switch (disconnectionType)
	{
	case NDKServer_NormalDisconnection:
		break;
	case NDKServer_ClientCloseConnection:
		break;
	case NDKServer_ErrorSendingMessage:
		break;
	case NDKServer_ErrorReceivingMessage:
		break;
	default:
		break;
	}
}
