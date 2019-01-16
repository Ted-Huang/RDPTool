
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
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(UI_POS_BTN_SEND, OnSendString)
	ON_WM_WINDOWPOSCHANGING()
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
	message.Add(m_localIP);
	message.Add(m_xSession.GetConnectionString());
	SendMessageToServer(message);
}

void CSessionDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case IDT_RETRY_TIMER:
		if (OpenConnection(m_serverIP, ServerListenPort)){
			KillTimer(IDT_RETRY_TIMER);
			TRACE(L"Connect to server ok! \n");
			OnSendString();
		}
		else
			TRACE(L"Connect to server fail \n");

		break;
	default:
		CDialogEx::OnTimer(nIDEvent);
		break;
	}
}

void CSessionDlg::OnWindowPosChanging(WINDOWPOS FAR* lpwndpos)
{
	if (!m_bVisible)
		lpwndpos->flags &= ~SWP_SHOWWINDOW;

	CDialog::OnWindowPosChanging(lpwndpos);
}

void CSessionDlg::Init()
{
	m_bVisible = FALSE;
	CString strCmd = theApp.m_lpCmdLine;
	if (!strCmd.IsEmpty()){
		int nPos = strCmd.MakeUpper().Find(_T("/SHOW"));
		if (nPos != -1){
			m_bVisible = TRUE;
		}
	}

	memset(m_xUi, 0, sizeof(m_xUi));
	m_serverIP = ServerIPAddress;
	m_localIP = ServerIPAddress;

	if (!lstrcmp(m_serverIP, L"0.0.0.0")){
		DetectNetApapter();
	}

	Connect();
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
			//LABEL
		case UI_POS_LABEL_CONNECTIONINFO:
			ptBase = { 0, 0 };
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
	//EDIT
	for (int i = UI_POS_LABEL_BEGIN; i < UI_POS_LABEL_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CStatic();
			((CStatic*)m_xUi[i].pCtrl)->Create(L"", WS_CHILD | WS_VISIBLE | WS_TABSTOP, m_xUi[i].rcUi, this, i);
		}
	}
	((CEdit*)m_xUi[UI_POS_EDIT_CONNTIONSTRING].pCtrl)->SetWindowText(m_xSession.GetConnectionString());
	CString str;
	str.Format(L"server: %s, local:%s", m_serverIP, m_localIP);
	((CStatic*)m_xUi[UI_POS_LABEL_BEGIN].pCtrl)->SetWindowText(str);
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
	//LABEL
	for (int i = UI_POS_LABEL_BEGIN; i < UI_POS_LABEL_END; i++){
		if (m_xUi[i].pCtrl){
			CStatic* pLabel = ((CStatic*)m_xUi[i].pCtrl);
			pLabel->DestroyWindow();
			delete pLabel;
			pLabel = NULL;
		}
	}
}

void CSessionDlg::DetectNetApapter()
{
	m_localIP = L"";
	DWORD dwErr = 0;
	ULONG ulNeeded = 0;
	CNetworkAdapter* pAdapter = NULL;
	int nNetCount = 0;
	dwErr = EnumNetworkAdapters(pAdapter, 0, &ulNeeded);
	if (dwErr == ERROR_INSUFFICIENT_BUFFER) {
		nNetCount = ulNeeded / sizeof(CNetworkAdapter);
		pAdapter = new CNetworkAdapter[nNetCount];
		dwErr = EnumNetworkAdapters(pAdapter, ulNeeded, &ulNeeded);
	}
	//Get IpAddress
	for (int c = 0; c<nNetCount; c++) {
		//Support IP aliasing.
		for (unsigned int d = 0; d<pAdapter[c].GetNumIpAddrs(); d++) {
			int ip[4];
			CString msg = pAdapter[c].GetIpAddr(d).c_str();
			if (m_localIP.GetLength() == 0) m_localIP = msg; //get first ip as local ip
			swscanf(msg, L"%d.%d.%d.%d", ip, ip + 1, ip + 2, ip + 3);
			if (ip[0] == 192 && ip[1] == 168 && ip[2]<10 && ip[3]>10 && ip[3]<100) {
				int ip_tail = (ip[3] / 10) * 10 + 1;
				m_serverIP.Format(_T("%d.%d.%d.%d"), ip[0], ip[1], ip[2], ip_tail);
				break;
			}
		}
	}

	if (pAdapter){
		delete[]pAdapter;
		pAdapter = NULL;
	}

}

void CSessionDlg::Connect()
{
	SetTimer(IDT_RETRY_TIMER, 3000, NULL);
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

	// stop first
	if (IsConnected())
		CloseConnection();

	Connect();
}