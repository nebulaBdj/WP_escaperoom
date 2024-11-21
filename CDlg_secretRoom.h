#pragma once
#include "afxdialogex.h"
#include "CDlg_ending.h"

// CDlg_secretRoom 대화 상자

class CDlg_secretRoom : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_secretRoom)

public:
	CDlg_secretRoom(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_secretRoom();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_SECRETROOM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CDlg_ending* dlg_ending;
	CStatic m_secret_pictureControl;
	CRect m_clickableRect;
	int is_hover = false;
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
