// CDlg_ending2.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_ending2.h"


// CDlg_ending2 대화 상자

IMPLEMENT_DYNAMIC(CDlg_ending2, CDialogEx)

CDlg_ending2::CDlg_ending2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ENDING2, pParent)
{

}

CDlg_ending2::~CDlg_ending2()
{
}

void CDlg_ending2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_ending2, CDialogEx)
END_MESSAGE_MAP()


// CDlg_ending2 메시지 처리기


BOOL CDlg_ending2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect rect(0, 0, 1600, 900);
	MoveWindow(&rect);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
