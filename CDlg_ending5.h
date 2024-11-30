#pragma once
#include "afxdialogex.h"


// CDlg_ending5 대화 상자

class CDlg_ending5 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_ending5)

public:
	CDlg_ending5(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_ending5();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ENDING5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
};
