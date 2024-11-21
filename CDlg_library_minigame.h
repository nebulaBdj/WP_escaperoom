#pragma once
#include "afxdialogex.h"


// CDlg_library_minigame 대화 상자

class CDlg_library_minigame : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_library_minigame)

public:
	CDlg_library_minigame(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_library_minigame();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MINIGAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	bool m_bLibrarySafeOpened;
	virtual BOOL OnInitDialog();
	CRect m_rectLibrarySafe;
};
