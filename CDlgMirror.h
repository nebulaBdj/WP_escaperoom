#pragma once
#include "afxdialogex.h"


// CDlgMirror 대화 상자

class CDlgMirror : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMirror)

public:
	CDlgMirror(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgMirror();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIG_DOORSTEP_MIRROR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	void OnClose();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStaticMirror();
};
