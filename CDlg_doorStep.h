#pragma once
#include "afxdialogex.h"


// CDlg_doorStep 대화 상자

class CDlg_doorStep : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_doorStep)

public:
	CDlg_doorStep(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_doorStep();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_DOORSTEP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
