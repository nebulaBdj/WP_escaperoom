// CDlg_tabControls.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_tabControls.h"


// CDlg_tabControls 대화 상자

IMPLEMENT_DYNAMIC(CDlg_tabControls, CDialogEx)

CDlg_tabControls::CDlg_tabControls(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_TAPCONTROL, pParent)
{

}

CDlg_tabControls::~CDlg_tabControls()
{
}

void CDlg_tabControls::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TABCONTROL, m_tabControl);
}


BEGIN_MESSAGE_MAP(CDlg_tabControls, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TABCONTROL, &CDlg_tabControls::OnSelchangeTabcontrol)
	ON_WM_TIMER()
END_MESSAGE_MAP()

BOOL CDlg_tabControls::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetTimer(1, 128, NULL); //옵저버용 타이머
	SetWindowPos(NULL, 0, 0, 1600, 900, SWP_NOMOVE | SWP_NOZORDER);
	//m_tabControl.GetWindowRect(&rect);
	m_tabControl.SetItemSize(CSize(100, 40));
	// 고정 너비 스타일 추가
	DWORD style = m_tabControl.GetStyle();
	m_tabControl.ModifyStyle(0, TCS_FIXEDWIDTH); // 고정 너비 스타일 설정

	// 탭 크기 설정
	m_tabControl.SetItemSize(CSize(150, 40)); // 너비 150, 높이 40

	m_tabControl.InsertItem(0, _T("현관"));
	m_tabControl.InsertItem(1, _T("침실"));
	m_tabControl.InsertItem(2, _T("서재"));

	m_tabControl.SetCurSel(0);
	m_previousIndex = 0;

	CRect rect(0, 0, 1600, 850);
	m_tabControl.MoveWindow(&rect);
	m_tabControl.GetClientRect(&rect);

	int top_offset = 40;
	dlg_doorStep = new CDlg_doorStep;
	dlg_doorStep->Create(IDD_DLG_DOORSTEP, &m_tabControl);
	dlg_doorStep->MoveWindow(0, top_offset, rect.Width() + 10, rect.Height());
	dlg_doorStep->ShowWindow(SW_SHOW);

	dlg_bedRoom = new CDlg_bedRoom;
	dlg_bedRoom->Create(IDD_DIG_BEDROOM, &m_tabControl);
	dlg_bedRoom->MoveWindow(0, top_offset, rect.Width() + 10, rect.Height());
	dlg_bedRoom->ShowWindow(SW_HIDE); // 첫번째 Tab을 SHOW로 하고 나머지는 HIDE

	dlg_library = new CDlg_library;
	dlg_library->Create(IDD_DLG_LIBRARY, &m_tabControl);
	dlg_library->MoveWindow(0, top_offset, rect.Width() + 10, rect.Height());
	dlg_library->ShowWindow(SW_HIDE); // 첫번째 Tab을 SHOW로 하고 나머지는 HIDE

	dlg_secretRoom = new CDlg_secretRoom;
	dlg_secretRoom->Create(IDD_DLG_SECRETROOM, &m_tabControl);
	dlg_secretRoom->MoveWindow(0, top_offset, rect.Width() + 10, rect.Height());
	dlg_secretRoom->ShowWindow(SW_HIDE); // 첫번째 Tab을 SHOW로 하고 나머지는 HIDE
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_tabControls::OnSelchangeTabcontrol(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (IDC_TABCONTROL == pNMHDR->idFrom) {  // Tab Control ID 확인
		int select = m_tabControl.GetCurSel();

		switch (select) {
		case 0: //현관, 탭컨트롤 값이 0이면 현관을 보여줌
			dlg_doorStep->ShowWindow(SW_SHOW);
			dlg_bedRoom->ShowWindow(SW_HIDE);
			dlg_library->ShowWindow(SW_HIDE);
			dlg_secretRoom->ShowWindow(SW_HIDE);
			m_previousIndex = 0;
			break;
		case 1: //침실
			if (bedRoom_key) {
				dlg_doorStep->ShowWindow(SW_HIDE);
				dlg_bedRoom->ShowWindow(SW_SHOW);
				dlg_library->ShowWindow(SW_HIDE);
				dlg_secretRoom->ShowWindow(SW_HIDE);
				m_previousIndex = 1;
			}
			else {
				AfxMessageBox(_T("문이 잠겨있다.. 열쇠가 필요하겠는데.."));
				m_tabControl.SetCurSel(m_previousIndex);
			}
			break;
		case 2: //서재
			dlg_doorStep->ShowWindow(SW_HIDE);
			dlg_bedRoom->ShowWindow(SW_HIDE);
			dlg_library->ShowWindow(SW_SHOW);
			dlg_secretRoom->ShowWindow(SW_HIDE);
			m_previousIndex = 2;
			break;
		case 3: //비밀방
			if (secret_room_per) {
				dlg_doorStep->ShowWindow(SW_HIDE);
				dlg_bedRoom->ShowWindow(SW_HIDE);
				dlg_library->ShowWindow(SW_HIDE);
				dlg_secretRoom->ShowWindow(SW_SHOW);
				m_previousIndex = 3;
			}
			else {
				AfxMessageBox(_T("???"));
				m_tabControl.SetCurSel(m_previousIndex);
			}

			break;
		}
	}
	*pResult = 0;
}

void CDlg_tabControls::insertSecretRoom() {
	m_tabControl.InsertItem(4, _T("비밀방"));
}


void CDlg_tabControls::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (secret_room_per && !secret_room_observer_once) {
		secret_room_observer_once = !secret_room_observer_once;
		insertSecretRoom();
		KillTimer(1);
		Invalidate();
	}
	CDialogEx::OnTimer(nIDEvent);
}
