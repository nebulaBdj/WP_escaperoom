﻿#pragma once
#include "afxdialogex.h"


// CDlg_ending3 대화 상자

class CDlg_ending3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_ending3)

public:
	CDlg_ending3(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_ending3();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ENDING3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
