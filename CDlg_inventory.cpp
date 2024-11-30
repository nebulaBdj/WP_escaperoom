// CDlg_inventory.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_inventory.h"


// CDlg_inventory 대화 상자

IMPLEMENT_DYNAMIC(CDlg_inventory, CDialogEx)

CDlg_inventory::CDlg_inventory(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_INVENTORY, pParent)
{

}

CDlg_inventory::~CDlg_inventory()
{
}

void CDlg_inventory::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_inventory, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDlg_inventory 메시지 처리기


BOOL CDlg_inventory::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetTimer(1, 128, NULL); //옵저버용 타이머

	CRect rect(0,0,260,900);
	MoveWindow(&rect);
	GetDlgItem(IDC_STATIC_MIRRORFRAC1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_MIRRORFRAC2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_MIRRORFRAC3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_BEDROOMKEY2)->ShowWindow(SW_HIDE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}





void CDlg_inventory::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (door_step_isMirror && !mirror1_observer_once) {
		GetDlgItem(IDC_STATIC_MIRRORFRAC1)->ShowWindow(SW_SHOW);
		mirror1_observer_once = !mirror1_observer_once;
	}
	else if (!door_step_isMirror && mirror1_observer_once){
		GetDlgItem(IDC_STATIC_MIRRORFRAC1)->ShowWindow(SW_HIDE);
		mirror1_observer_once = !mirror1_observer_once;
	}
	if (bedroom_isMirror && !mirror2_observer_once) {
		GetDlgItem(IDC_STATIC_MIRRORFRAC2)->ShowWindow(SW_SHOW);
		mirror2_observer_once = !mirror2_observer_once;
	}
	else if (!bedroom_isMirror && mirror2_observer_once) {
		GetDlgItem(IDC_STATIC_MIRRORFRAC2)->ShowWindow(SW_HIDE);
		mirror2_observer_once = !mirror2_observer_once;
	}
	if (library_isMirror && !mirror3_observer_once) {
		GetDlgItem(IDC_STATIC_MIRRORFRAC3)->ShowWindow(SW_SHOW);
		mirror3_observer_once = !mirror3_observer_once;
	}
	else if (!library_isMirror && mirror3_observer_once) {
		GetDlgItem(IDC_STATIC_MIRRORFRAC3)->ShowWindow(SW_HIDE);
		mirror3_observer_once = !mirror3_observer_once;
	}
	if (bedRoom_key && !bedroom_observer_once) {
		GetDlgItem(IDC_STATIC_BEDROOMKEY2)->ShowWindow(SW_SHOW);
		bedroom_observer_once = !bedroom_observer_once;
	}
	CDialogEx::OnTimer(nIDEvent);
}
