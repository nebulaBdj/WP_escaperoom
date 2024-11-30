// CDlg_bedRoom.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_bedRoom.h"
#include "CDlg_bedroom_quiz.h"
#include "CDlg_bedroomHint.h"


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
    ON_WM_MOUSEMOVE()
    ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CDlg_bedRoom 메시지 처리기


void CDlg_bedRoom::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    CRect rectPaint(81, 268, 150, 424);  //그림 영역
    CRect rectMirror(1273, 202, 1455, 395); // 거울 영역
    CRect rectBox(733, 539, 790, 575); // 서랍장 영역
    CRect rectTelephone(800, 469, 950, 530); // 전화기 

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
    else if (rectBox.PtInRect(point)) {
        AfxMessageBox(_T("서랍 속에서 낡은 메모 한 장을 발견했다. \n 메모에는 [전화기], [사랑], [숫자] 라는 단어가 적혀있다."), MB_OK | MB_ICONQUESTION);
    }
    else if (rectTelephone.PtInRect(point)) {
        if (AfxMessageBox(_T("책상 위에 전화기와 낡은 종이가 놓여있다. 확인해볼까?"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK){
            CDlg_bedroomHint hintDlg;
            hintDlg.DoModal();
        } 
    }
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CDlg_bedRoom::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    CRect rectPaint(81, 268, 150, 424);  // 그림 영역
    CRect rectMirror(1273, 202, 1455, 395); // 거울 영역
    CRect rectBox(733, 539, 790, 575); // 서랍장 
    CRect rectTelephone(800, 469, 950, 530); // 전화기 
    
    // 영역 위에 있으면 커서를 손 모양으로 변경
    if (rectPaint.PtInRect(point) || rectMirror.PtInRect(point) || rectBox.PtInRect(point) || rectTelephone.PtInRect(point)) {
        if (!is_hover) {
            is_hover = true;
            ::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND)); // 손 모양 커서
        }
    }
    else {
        if (is_hover) {
            is_hover = false;
            ::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW)); // 기본 커서
        }
    }
    CDialogEx::OnMouseMove(nFlags, point);
}


BOOL CDlg_bedRoom::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  여기에 추가 초기화 작업을 추가합니다.
    is_hover = false;
    return TRUE;  // return TRUE unless you set the focus to a control
    // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CDlg_bedRoom::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

    return true;
}
