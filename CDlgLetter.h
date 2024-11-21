#pragma once
#include "afxdialogex.h"


// CDlgLetter 대화 상자

class CDlgLetter : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgLetter)

public:
	CDlgLetter(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgLetter();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_DOORSTEP_LETTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnStnClickedStaticLetter();
	afx_msg void OnClose(); // WM_CLOSE 메시지 핸들러 선언
};
