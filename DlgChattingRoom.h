#pragma once


// DlgChattingRoom 대화 상자

class DlgChattingRoom : public CDialogEx
{
	DECLARE_DYNAMIC(DlgChattingRoom)
	
public:
	DlgChattingRoom(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	CWnd* pParent;
	CString nickname;
	virtual ~DlgChattingRoom();
	BOOL PreTranslateMessage(MSG* pMSG);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATROOM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CEdit content;
	CListBox mList;
};
