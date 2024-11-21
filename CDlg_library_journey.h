#pragma once
#include "afxdialogex.h"

// CDlg_library_journey 대화 상자

class CDlg_library_journey : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_library_journey)

public:
	CDlg_library_journey(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_library_journey();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_JOURNEY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CRect m_rectLibraryJourney;
	virtual BOOL OnInitDialog();
};
