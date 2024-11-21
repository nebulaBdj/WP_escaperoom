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
END_MESSAGE_MAP()


// CDlg_bedroom_safety 메시지 처리기


void CDlg_bedroom_safety::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rectPaint(409, 429, 479, 492);  // 그리기 영역
	if (rectPaint.PtInRect(point)) {
		// 아이템 획득 메시지 박스
		m_nBedroomItemGet = TRUE;
		AfxMessageBox(_T("깨진 거울 조각이 하나 있다. 챙기자."), MB_OK);
		m_nBedroomItemGet = true;
		// 금고 다이얼로그 종료
		CDialogEx::OnOK();  // DoModal()에서 반환하고 다이얼로그를 닫음

	}
	CDialogEx::OnLButtonDown(nFlags, point);
}
