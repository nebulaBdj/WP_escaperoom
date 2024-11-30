#pragma once
#include "afxdialogex.h"


// CDlg_bedroom_safety 대화 상자

class CDlg_bedroom_safety : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_bedroom_safety)

public:
	CDlg_bedroom_safety(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_bedroom_safety();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_BEDROOM_SAFETY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	bool safety_is_hover;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};
