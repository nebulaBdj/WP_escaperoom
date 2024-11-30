// CDlg_ending3.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_ending3.h"


// CDlg_ending3 대화 상자

IMPLEMENT_DYNAMIC(CDlg_ending3, CDialogEx)

CDlg_ending3::CDlg_ending3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ENDING3, pParent)
{

}

CDlg_ending3::~CDlg_ending3()
{
}

void CDlg_ending3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_ending3, CDialogEx)
END_MESSAGE_MAP()


// CDlg_ending3 메시지 처리기


BOOL CDlg_ending3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect rect(0, 0, 1600, 840);
	MoveWindow(&rect);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
