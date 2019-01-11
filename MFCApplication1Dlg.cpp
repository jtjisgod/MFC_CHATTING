
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "DlgChattingRoom.h"
#include "afxdialogex.h"

#define MAX_NICK_LENGTH 20

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, mNickname);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication1Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_WM_CTLCOLOR()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnEnChangeEdit1()
{
	CString str;
	int len = 0;
	len = mNickname.GetWindowTextLength();
	str.Format(_T("%d/%d"), len, MAX_NICK_LENGTH);
	SetDlgItemText(IDC_EDIT2, str);
}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	CString nickname;
	mNickname.GetWindowTextW(nickname);
	if (nickname.GetLength() > MAX_NICK_LENGTH) {
		MessageBox(_T("닉네임은 20자를 넘길 수 없습니다."));
		return;
	}
	CString question;
	question.Format(TEXT("닉네임을 '%s'로 설정하시겠습니까?"), nickname);
	if (AfxMessageBox(question, MB_YESNO) == IDNO) {
		MessageBox(_T("취소되었습니다."));
		return;
	}

	DlgChattingRoom* dlgChattingRoom = new DlgChattingRoom(this);
	dlgChattingRoom->nickname = nickname;
	dlgChattingRoom->Create(IDD_CHATROOM);
	dlgChattingRoom->ShowWindow(SW_SHOW);
	ShowWindow(SW_HIDE);
}



void CMFCApplication1Dlg::OnStaticNickLength()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


HBRUSH CMFCApplication1Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd -> GetDlgCtrlID() == IDC_EDIT2) {
		if (mNickname.GetWindowTextLengthW() > MAX_NICK_LENGTH) {
			pDC->SetTextColor(RGB(0xff, 0, 0));
		}
	}

	return hbr;
}

BOOL CMFCApplication1Dlg::PreTranslateMessage(MSG* pMsg) {
	if (pMsg->message == WM_KEYDOWN) {
		if (pMsg->wParam == VK_RETURN) { // 0x0d = 13 = Enter Keycode
			OnBnClickedButton1();
			return true;
		}
	}
	//if(pMsg -> wParam)
	return CDialog::PreTranslateMessage(pMsg);
}