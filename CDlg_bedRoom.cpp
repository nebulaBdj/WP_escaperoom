// CDlg_bedRoom.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_bedRoom.h"
#include "CDlg_bedroom_quiz.h"


// CDlg_bedRoom 대화 상자

IMPLEMENT_DYNAMIC(CDlg_bedRoom, CDialogEx)

CDlg_bedRoom::CDlg_bedRoom(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIG_BEDROOM, pParent)
{

}

CDlg_bedRoom::~CDlg_bedRoom()
{
}

void CDlg_bedRoom::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_bedRoom, CDialogEx)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CDlg_bedRoom 메시지 처리기


void CDlg_bedRoom::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    CRect rectPaint(81, 268, 150, 424);  //그림 영역
    CRect rectMirror(1273, 202, 1455, 395); // 거울 영역

    if (rectPaint.PtInRect(point)) {
        if (m_nBedroomItemGet) {
            AfxMessageBox(_T("여기서 얻을 수 있는 건 다 얻은 것 같다."), MB_OK);
        }
        else {
            CDlg_bedroom_quiz quizDlg;
            quizDlg.DoModal();
        }
    }
    else if (rectMirror.PtInRect(point)) {
        AfxMessageBox(_T("진실은 거울 속에 있을 것이다. 그것을 마주하라"), MB_OK);
    }

	CDialogEx::OnLButtonDown(nFlags, point);
}
