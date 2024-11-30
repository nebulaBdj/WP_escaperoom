// CDlg_bedroom_safety.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_bedroom_safety.h"


// CDlg_bedroom_safety 대화 상자

IMPLEMENT_DYNAMIC(CDlg_bedroom_safety, CDialogEx)

CDlg_bedroom_safety::CDlg_bedroom_safety(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_BEDROOM_SAFETY, pParent)
{

}

CDlg_bedroom_safety::~CDlg_bedroom_safety()
{
}

void CDlg_bedroom_safety::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_bedroom_safety, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CDlg_bedroom_safety 메시지 처리기


void CDlg_bedroom_safety::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rectPaint(389, 409, 499, 512);  // 그리기 영역
	if (rectPaint.PtInRect(point) && !bedroom_isMirror) {
		// 아이템 획득 메시지 박스
		m_nBedroomItemGet = TRUE;
		AfxMessageBox(_T("깨진 거울 조각이 하나 있다. 챙기자."), MB_OK);
		m_nBedroomItemGet = true;
		mirror_count++;
		bedroom_isMirror = !bedroom_isMirror;

		// 금고 다이얼로그 종료
		CDialogEx::OnOK();  // DoModal()에서 반환하고 다이얼로그를 닫음

	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


BOOL CDlg_bedroom_safety::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect rect(300, 300, 1200, 1200);
	MoveWindow(&rect);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



void CDlg_bedroom_safety::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rectPaint(389, 409, 499, 512);  // 그리기 영역

	if (rectPaint.PtInRect(point)) {
		if (!safety_is_hover) {
			safety_is_hover = true;
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND)); // 손 모양 커서
		}
	}
	else {
		if (safety_is_hover) {
			safety_is_hover = false;
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW)); // 기본 커서
		}
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


BOOL CDlg_bedroom_safety::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return true;
}
