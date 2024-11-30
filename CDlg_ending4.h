#pragma once
#include "afxdialogex.h"


// CDlg_ending4 대화 상자

class CDlg_ending4 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_ending4)

public:
	CDlg_ending4(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_ending4();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ENDING4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
