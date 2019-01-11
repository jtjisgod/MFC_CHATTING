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
END_MESSAGE_MAP()




void DlgChattingRoom::OnBnClickedOk()
{
	CString nickname = this->nickname;
	CString content;
	this->content.GetWindowTextW(content);
	mList.AddString(content);
	this->content.SetWindowTextW(L"");
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
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}