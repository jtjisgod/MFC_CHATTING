// DlgChattingRoom.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "DlgChattingRoom.h"
#include "afxdialogex.h"


// DlgChattingRoom 대화 상자

IMPLEMENT_DYNAMIC(DlgChattingRoom, CDialogEx)



DlgChattingRoom::DlgChattingRoom(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHATROOM, pParent)
{
	this -> pParent = pParent;
}

DlgChattingRoom::~DlgChattingRoom()
{
	this->pParent->ShowWindow(SW_SHOW);
}

void DlgChattingRoom::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, content);
	DDX_Control(pDX, IDC_LIST4, mList);
}


BEGIN_MESSAGE_MAP(DlgChattingRoom, CDialogEx)
	ON_BN_CLICKED(IDOK, &DlgChattingRoom::OnBnClickedOk)
	ON_WM_CLOSE()
	ON_WM_KEYDOWN()
	ON_EN_CHANGE(IDC_EDIT1, &DlgChattingRoom::OnEnChangeEdit1)
END_MESSAGE_MAP()




void DlgChattingRoom::OnBnClickedOk()
{
	CString nickname = this->nickname;
	CString content;

	this->content.GetWindowTextW(content);
	this->content.SetWindowTextW(L"");

	content.Format(_T("%s: %s"), nickname, content);
	int height = mList.InsertString(-1, content);
	
	mList.SetCurSel(height);
}


void DlgChattingRoom::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	MessageBox(_T("종료됩니다."));
	this->pParent->ShowWindow(SW_SHOW);
	CDialogEx::OnClose();
}


void DlgChattingRoom::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL DlgChattingRoom::PreTranslateMessage(MSG* pMsg) {
	if (pMsg->message == WM_KEYDOWN) {
		if (pMsg->wParam == VK_RETURN) {
			OnBnClickedOk();
			return true;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void DlgChattingRoom::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
