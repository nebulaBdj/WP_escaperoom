﻿#pragma once
#include "afxdialogex.h"


// CDlg_inventory 대화 상자

class CDlg_inventory : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_inventory)

public:
	CDlg_inventory(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_inventory();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INVENTORY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
