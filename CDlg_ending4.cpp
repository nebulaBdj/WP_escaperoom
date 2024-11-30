// CDlg_ending4.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_ending4.h"


// CDlg_ending4 대화 상자

IMPLEMENT_DYNAMIC(CDlg_ending4, CDialogEx)

CDlg_ending4::CDlg_ending4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ENDING4, pParent)
{

}

CDlg_ending4::~CDlg_ending4()
{
}

void CDlg_ending4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_ending4, CDialogEx)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CDlg_ending4 메시지 처리기


BOOL CDlg_ending4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect rect(0, 0, 1600, 800);
	MoveWindow(&rect);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_ending4::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	AfxMessageBox(_T("축하합니다. 게임을 클리어 하셨습니다."));
	PostMessage(WM_CLOSE);
	CDialogEx::OnLButtonDown(nFlags, point);
}
