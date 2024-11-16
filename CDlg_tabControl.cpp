// CDlg_tabControl.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_tabControl.h"


// CDlg_tabControl 대화 상자

IMPLEMENT_DYNAMIC(CDlg_tabControl, CDialogEx)

CDlg_tabControl::CDlg_tabControl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_SECRETROOM, pParent)
{

}

CDlg_tabControl::~CDlg_tabControl()
{
}

void CDlg_tabControl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_tabControl, CDialogEx)
END_MESSAGE_MAP()


// CDlg_tabControl 메시지 처리기
