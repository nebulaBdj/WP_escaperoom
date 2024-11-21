// CDlg_secretRoom.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_secretRoom.h"

// CDlg_secretRoom 대화 상자

IMPLEMENT_DYNAMIC(CDlg_secretRoom, CDialogEx)

CDlg_secretRoom::CDlg_secretRoom(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_SECRETROOM, pParent)
{

}

CDlg_secretRoom::~CDlg_secretRoom()
{
}

void CDlg_secretRoom::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_SECRET_PICTURECONTROL, m_secret_pictureControl);
}


BEGIN_MESSAGE_MAP(CDlg_secretRoom, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CDlg_secretRoom 메시지 처리기


BOOL CDlg_secretRoom::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect parentRect;
	CWnd* pParent = GetParent();
	pParent->GetWindowRect(&parentRect); // 부모 다이얼로그의 전체 크기(스크린 좌표)
	ScreenToClient(&parentRect);
	m_secret_pictureControl.MoveWindow(&parentRect);
	//m_secret_pictureControl.ShowWindow(SW_HIDE);
	// 다이얼로그 크기 가져오기
	CRect clientRect;
	GetClientRect(&clientRect);
	// 화면 중앙에 500x500 크기의 Rect 설정
	int width = 200;
	int height = 300;
	int left = 720;
	int top = 240;
	m_clickableRect.SetRect(left, top, left + width, top + height);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_secretRoom::OnLButtonDown(UINT nFlags, CPoint point)
{
	// 클릭한 위치 확인
	if (m_clickableRect.PtInRect(point)) // 클릭한 위치가 Rect 내에 있는지 확인
	{
		CWnd* pTabControl = GetParent();
		CWnd* pDialog =  pTabControl->GetParent();
		pDialog-> PostMessage(WM_CLOSE);
		CRect rect(0, 0, 1600, 900);

		CDlg_ending dlg_ending;
		dlg_ending.DoModal();
	
		//EndDialog(IDCANCEL);
		//AfxMessageBox(_T("거울 클릭")); // 클릭되었을 때 실행할 동작
	}

	CDialogEx::OnLButtonDown(nFlags, point); // 기본 처리
}


void CDlg_secretRoom::OnPaint()
{
	CPaintDC dc(this); // 그리기 DC
	// 빨간색 브러시 생성
	CBrush redBrush(RGB(255, 0, 0)); // 빨간색
	CBrush* pOldBrush = dc.SelectObject(&redBrush); // 이전 브러시 저장
	dc.Rectangle(m_clickableRect);
	// 원래 브러시로 복원
	dc.SelectObject(pOldBrush);

	CDialogEx::OnPaint();
}


BOOL CDlg_secretRoom::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	return true;
}


void CDlg_secretRoom::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 마우스가 사각형 내부에 있는지 확인
	if (m_clickableRect.PtInRect(point))
	{
		if (!is_hover) {
			is_hover = true;
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND)); // 손 모양 커서
		}
	}
	else if (is_hover && !m_clickableRect.PtInRect(point))
	{
		if (is_hover) {
			is_hover = false;
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW)); // 기본 커서
		}
	}
	CDialogEx::OnMouseMove(nFlags, point);
}
