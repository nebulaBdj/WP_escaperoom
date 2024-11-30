// CDlg_bedroomHint.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_bedroomHint.h"


// CDlg_bedroomHint 대화 상자

IMPLEMENT_DYNAMIC(CDlg_bedroomHint, CDialogEx)

CDlg_bedroomHint::CDlg_bedroomHint(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BEDROOMHINT, pParent)
{

}

CDlg_bedroomHint::~CDlg_bedroomHint()
{
}

void CDlg_bedroomHint::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_bedroomHint, CDialogEx)
END_MESSAGE_MAP()


// CDlg_bedroomHint 메시지 처리기


BOOL CDlg_bedroomHint::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect rect(500, 200, 1500, 700);
	MoveWindow(&rect);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
