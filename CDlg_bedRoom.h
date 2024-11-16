#pragma once
#include "afxdialogex.h"


// CDlg_bedRoom 대화 상자

class CDlg_bedRoom : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_bedRoom)

public:
	CDlg_bedRoom(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_bedRoom();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIG_BEDROOM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
