#pragma once
#include "afxdialogex.h"


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
};
