// CDlg_library.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_library.h"


// CDlg_library 대화 상자

IMPLEMENT_DYNAMIC(CDlg_library, CDialogEx)

CDlg_library::CDlg_library(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_LIBRARY, pParent)
{

}

CDlg_library::~CDlg_library()
{
}

void CDlg_library::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_library, CDialogEx)
END_MESSAGE_MAP()


// CDlg_library 메시지 처리기
