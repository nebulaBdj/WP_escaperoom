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
END_MESSAGE_MAP()

BOOL CDlg_tabControls::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// SetWindowPos 함수로 다이얼로그를 화면 크기로 설정
	SetWindowPos(NULL, 0, 0, 1600, 800, SWP_NOZORDER);

	CRect rect(0, 0, 1600, 800);
	m_tabControl.MoveWindow(&rect);
	m_tabControl.GetClientRect(&rect);

	m_tabControl.InsertItem(0, _T("현관"));
	m_tabControl.InsertItem(1, _T("침실"));
	m_tabControl.InsertItem(2, _T("서재"));
	m_tabControl.InsertItem(3, _T("???"));
	m_tabControl.SetCurSel(0);
	m_previousIndex = 0;

	dlg_doorStep = new CDlg_doorStep;
	dlg_doorStep->Create(IDD_DLG_DOORSTEP, &m_tabControl);
	dlg_doorStep->MoveWindow(0, 20, rect.Width() + 10, rect.Height());
	dlg_doorStep->ShowWindow(SW_SHOW);

	dlg_bedRoom = new CDlg_bedRoom;
	dlg_bedRoom->Create(IDD_DIG_BEDROOM, &m_tabControl);
	dlg_bedRoom->MoveWindow(0, 20, rect.Width() + 10, rect.Height());
	dlg_bedRoom->ShowWindow(SW_HIDE); // 첫번째 Tab을 SHOW로 하고 나머지는 HIDE

	dlg_library = new CDlg_library;
	dlg_library->Create(IDD_DLG_LIBRARY, &m_tabControl);
	dlg_library->MoveWindow(0, 20, rect.Width() + 10, rect.Height());
	dlg_library->ShowWindow(SW_HIDE); // 첫번째 Tab을 SHOW로 하고 나머지는 HIDE

	dlg_secretRoom = new CDlg_secretRoom;
	dlg_secretRoom->Create(IDD_DLG_SECRETROOM, &m_tabControl);
	dlg_secretRoom->MoveWindow(0, 20, rect.Width() + 10, rect.Height());
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
		case 0: //현관
			dlg_doorStep->ShowWindow(SW_SHOW);
			dlg_bedRoom->ShowWindow(SW_HIDE);
			dlg_library->ShowWindow(SW_HIDE);
			dlg_secretRoom->ShowWindow(SW_HIDE);
			m_previousIndex = 0;
			break;
		case 1: //침실
			dlg_doorStep->ShowWindow(SW_HIDE);
			dlg_bedRoom->ShowWindow(SW_SHOW);
			dlg_library->ShowWindow(SW_HIDE);
			dlg_secretRoom->ShowWindow(SW_HIDE);
			m_previousIndex = 1;
			break;
		case 2: //서재
			dlg_doorStep->ShowWindow(SW_HIDE);
			dlg_bedRoom->ShowWindow(SW_HIDE);
			dlg_library->ShowWindow(SW_SHOW);
			dlg_secretRoom->ShowWindow(SW_HIDE);
			m_previousIndex = 2;
			break;
		case 3: //비밀방
			dlg_doorStep->ShowWindow(SW_HIDE);
			dlg_bedRoom->ShowWindow(SW_HIDE);
			dlg_library->ShowWindow(SW_HIDE);
			dlg_secretRoom->ShowWindow(SW_SHOW);
			m_previousIndex = 3;
			break;
		}
	}
	*pResult = 0;
}


