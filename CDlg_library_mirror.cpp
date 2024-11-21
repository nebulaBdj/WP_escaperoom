// CDlg_library_mirror.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_library_mirror.h"
#include "resource.h"


// CDlg_library_mirror 대화 상자

IMPLEMENT_DYNAMIC(CDlg_library_mirror, CDialogEx)

CDlg_library_mirror::CDlg_library_mirror(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_LIBRARY_MIRROR, pParent)
{

}

CDlg_library_mirror::~CDlg_library_mirror()
{
}

void CDlg_library_mirror::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_library_mirror, CDialogEx)
	//	ON_WM_LBUTTONDOWN()
	//	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CDlg_library_mirror 메시지 처리기


//void CDlg_library_mirror::OnLButtonDown(UINT nFlags, CPoint point)
//{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

//	if (m_rectLibraryMirrorPiece.PtInRect(point)) {
//		AfxMessageBox(_T("거울 조각을 획득했습니다."));
//	}
//	CDialogEx::OnLButtonDown(nFlags, point);
//}


BOOL CDlg_library_mirror::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_rectLibraryMirrorPiece.SetRect(20, 20, 1000, 1000);
	m_bLibraryMirrorPieceObtained = false;
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


//void CDlg_library_mirror::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	if (m_rectLibraryMirrorPiece.PtInRect(point)) {
//		AfxMessageBox(_T("거울 조각을 획득했습니다."));
//	}
//	CDialogEx::OnLButtonDblClk(nFlags, point);
//}


void CDlg_library_mirror::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_rectLibraryMirrorPiece.PtInRect(point)) {
		if (!m_bLibraryMirrorPieceObtained) {
			// 아직 조각을 획득하지 않은 경우
			AfxMessageBox(_T("거울 조각을 얻었다."));
			m_bLibraryMirrorPieceObtained = true; // 상태 업데이트: 조각 획득
			EndDialog(IDOK);
		}
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}
