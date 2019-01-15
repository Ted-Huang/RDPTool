
// SessionDlg.cpp : ��@��
//

#include "stdafx.h"
#include "Session.h"
#include "SessionDlg.h"
#include "afxdialogex.h"
#include "NDKMessage.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSessionDlg ��ܤ��



CSessionDlg::CSessionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSessionDlg::IDD, pParent)
{
	m_serverIP = "127.0.0.1"; //need get server ip dynamiclly
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CSessionDlg::~CSessionDlg()
{
	Finalize();
}

void CSessionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSessionDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(UI_POS_BTN_SEND, OnSendString)
END_MESSAGE_MAP()


// CSessionDlg �T���B�z�`��

BOOL CSessionDlg::OnInitDialog()
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

// �p�G�N�̤p�ƫ��s�[�J�z����ܤ���A�z�ݭn�U�C���{���X�A
// �H�Kø�s�ϥܡC���ϥΤ��/�˵��Ҧ��� MFC ���ε{���A
// �ج[�|�۰ʧ������@�~�C

void CSessionDlg::OnPaint()
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
HCURSOR CSessionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSessionDlg::OnSendString()
{
	CNDKMessage message(DM_RDPSESSION_CONNECTIONSTRING);
	message.Add(m_xSession.GetConnectionString());
	SendMessageToServer(message);
}

void CSessionDlg::Init()
{
	memset(m_xUi, 0, sizeof(m_xUi));
	DetectNetApapter();
	m_serverIP = ServerIPAddress;
	if (!lstrcmp(m_serverIP, L"0.0.0.0")){
		GetServerAddress(m_serverIP.GetBuffer());  
		if (!lstrcmp(m_serverIP, L"0.0.0.0")) {	// Default server IP.
			m_serverIP = L"192.168.1.11";
		}
	}
	GetServerAddress(m_serverIP.GetBuffer());
	if (!OpenConnection(m_serverIP, ServerListenPort))
		TRACE(L"Connect to server fail \n");
}

void CSessionDlg::Finalize()
{
	DestroyUi();
}

void CSessionDlg::InitUiRectPos()
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
		case UI_POS_BTN_SEND:
			ptBase = { 0, 30 };
			ptSize = { 50, 30 };
			break;
			//edit
		case UI_POS_EDIT_CONNTIONSTRING:  
			ptBase = { 50, 30 };
			ptSize = { 1400, 30 };
			break;
		}

		m_xUi[i].rcUi = { ptBase.x, ptBase.y, ptBase.x + ptSize.x, ptBase.y + ptSize.y };
	}
}

void CSessionDlg::InitUi()
{
	CString strCaption;
	//BTN
	for (int i = UI_POS_BTN_BEGIN; i < UI_POS_BTN_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CButton();
			strCaption = (i == UI_POS_BTN_SEND) ? L"Send" : L"";
			((CButton*)m_xUi[i].pCtrl)->Create(strCaption, WS_VISIBLE | WS_CHILD | WS_TABSTOP, m_xUi[i].rcUi, this, i);
		}
	}
	//EDIT
	for (int i = UI_POS_EDIT_BEGIN; i < UI_POS_EDIT_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CEdit();
			((CEdit*)m_xUi[i].pCtrl)->Create(WS_CHILD | WS_VISIBLE | ES_READONLY | WS_TABSTOP | ES_LEFT | WS_BORDER, m_xUi[i].rcUi, this, i);
		}
	}
	((CEdit*)m_xUi[UI_POS_EDIT_CONNTIONSTRING].pCtrl)->SetWindowText(m_xSession.GetConnectionString());

}

void CSessionDlg::DestroyUi()
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
	//EDIT
	for (int i = UI_POS_EDIT_BEGIN; i < UI_POS_EDIT_END; i++){
		if (m_xUi[i].pCtrl){
			CEdit* pEdit = ((CEdit*)m_xUi[i].pCtrl);
			pEdit->DestroyWindow();
			delete pEdit;
			pEdit = NULL;
		}
	}
}

void CSessionDlg::DetectNetApapter()
{
	DWORD dwErr = 0;
	ULONG ulNeeded = 0;
	if (m_pAdapters == NULL){
		dwErr = EnumNetworkAdapters(m_pAdapters, 0, &ulNeeded);
		if (dwErr == ERROR_INSUFFICIENT_BUFFER) {
			m_adapterCount = ulNeeded / sizeof(CNetworkAdapter);
			m_pAdapters = new CNetworkAdapter[m_adapterCount];
			dwErr = EnumNetworkAdapters(m_pAdapters, ulNeeded, &ulNeeded);
		}
	}
}

void CSessionDlg::GetServerAddress(wchar_t *pServerAddress)
{
	if (pServerAddress){
		for (int c = 0; c<(int)m_adapterCount; c++) {
			//Support IP aliasing.
			for (unsigned int d = 0; d<m_pAdapters[c].GetNumIpAddrs(); d++) {
				// 192.168.X.1X ~ 192.168.X.9X  //Beagle define
				int ip[4];
				CString msg = m_pAdapters[c].GetIpAddr(d).c_str();
				swscanf(msg, L"%d.%d.%d.%d", ip, ip + 1, ip + 2, ip + 3);
				if (ip[0] == 192 && ip[1] == 168 && ip[2]<10 && ip[3]>10 && ip[3]<100) {
					int ip_tail = (ip[3] / 10) * 10 + 1;
					swprintf(pServerAddress, 16, L"%d.%d.%d.%d", 192, 168, ip[2], ip_tail);
					break;
				}
			}
		}
	}
}

// Called when a message is received. The derived class must override this
// method.
void CSessionDlg::OnMessage(CNDKMessage& message)
{
	
}
// Called whenever an unexpected disconnection occurs. The only case when
// this method isn't call is when CloseConnection is used. CloseConnection
// don't need to be called when when OnDisconnect is called. The derived 
// class must override this method.
void CSessionDlg::OnDisconnect(NDKClientDisconnection disconnectionType)
{
	UINT unResId = 0;
	switch (disconnectionType)
	{
	case NDKClient_NormalDisconnection:
		return;
	case NDKClient_ServerCloseConnection:
		break;

	case NDKClient_ServerStop:
		break;
	case NDKClient_ErrorSendingMessage:
		break;
	case NDKClient_ErrorReceivingMessage:
		break;
	default:
		break;
	}
}