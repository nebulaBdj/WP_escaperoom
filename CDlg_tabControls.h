#pragma once
#include "afxdialogex.h"
#include "CDlg_doorStep.h"
#include "CDlg_bedRoom.h"
#include "CDlg_library.h"
#include "CDlg_secretRoom.h"

// CDlg_tabControls 대화 상자

class CDlg_tabControls : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_tabControls)

public:
	CDlg_tabControls(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_tabControls();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_TAPCONTROL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabControl;
	afx_msg void OnSelchangeTabcontrol(NMHDR* pNMHDR, LRESULT* pResult);
	CDlg_doorStep* dlg_doorStep;
	CDlg_bedRoom* dlg_bedRoom;
	CDlg_library* dlg_library;
	CDlg_secretRoom* dlg_secretRoom;
	int m_previousIndex;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButton1();
};
