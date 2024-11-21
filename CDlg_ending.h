#pragma once
#include "afxdialogex.h"
#include "CDlg_ending2.h"


// CDlg_ending 대화 상자

class CDlg_ending : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_ending)

public:
	CDlg_ending(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_ending();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ENDING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButtonEndingNext();
	afx_msg void OnClickedButtonEndingPrev();
	int ending_page_index;
	afx_msg void OnPaint();
	CDlg_ending2* dlg_ending2;
	afx_msg void OnClickedButtonEndingAction1();
	afx_msg void OnClickedButtonEndingAction2();
};
