// CDlg_library.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_library.h"
#include "CDlg_library_journey.h"
#include "CDlg_library_minigame.h"
#include "afxwin.h"


// CDlg_library 대화 상자

IMPLEMENT_DYNAMIC(CDlg_library, CDialogEx)

CDlg_library::CDlg_library(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DLG_LIBRARY, pParent)
{

}

CDlg_library::~CDlg_library()
{
}

void CDlg_library::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_library, CDialogEx)
    //	ON_WM_LBUTTONUP()
//    ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONDOWN()
ON_WM_MOUSEMOVE()
ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CDlg_library 메시지 처리기





BOOL CDlg_library::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  여기에 추가 초기화 작업을 추가합니다.
    //m_rectLibraryMirror.SetRect(445,571,816,661);
    m_rectLibraryJourney.SetRect(879, 568, 1243, 690);
    m_rectLibraryMiniGame.SetRect(1291, 69, 1492, 282);
   
    m_mirrorPoints[0] = { 266,694 };
    m_mirrorPoints[1] = { 682,732 };
    m_mirrorPoints[2] = { 853,670 };
    m_mirrorPoints[3] = { 670,645 };
    m_mirrorPoints[4] = { 499,660 };

    m_journeyPoints[0] = { 830,608 };
    m_journeyPoints[1] = { 834,649 };
    m_journeyPoints[2] = { 1143,722 };
    m_journeyPoints[3] = { 1347,668 };
    m_journeyPoints[4] = { 1345,629 };
    m_journeyPoints[5] = { 1033,574 };

    // 클릭 가능한 영역을 초기화
    CWnd* pWnd = GetDlgItem(IDC_STATIC_LIBRARY); // 컨트롤 ID를 사용하여 객체 가져오기
    if (pWnd)
    {
        CRect rect;
        pWnd->GetWindowRect(&rect); // 화면 좌표 기준으로 영역 가져오기
        ScreenToClient(&rect);     // 대화 상자 기준 좌표로 변환
        m_rectLibraryClickable = rect; // 클릭 가능한 영역 설정
    }

    // m_bLibrary_Is_Hover 초기화
    m_bLibrary_Is_Hover = false;

    CStatic* pPictureControl = (CStatic*)GetDlgItem(IDC_STATIC_LIBRARY);
    if (pPictureControl)
    {
        // 크기를 1600x800으로 설정 (화면 좌표에서 조정 가능)
        pPictureControl->SetWindowPos(NULL, 0, 0, 1600, 900, SWP_NOZORDER);
    }
    return TRUE;  // return TRUE unless you set the focus to a control
    // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BOOL CDlg_library::PtInPolygon(CPoint point, POINT* pPolygon, int nPoints)
{
    // TODO: 여기에 구현 코드 추가.
    BOOL bInside = FALSE;
    int i, j = nPoints - 1;

    for (i = 0; i < nPoints; j = i++)
    {
        if (((pPolygon[i].y > point.y) != (pPolygon[j].y > point.y)) &&
            (point.x < (pPolygon[j].x - pPolygon[i].x) * (point.y - pPolygon[i].y) / (pPolygon[j].y - pPolygon[i].y) + pPolygon[i].x))
        {
            bInside = !bInside;
        }
    }
    return bInside;
};

void CDlg_library::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다

    if (m_pDlgLibraryMirror && m_pDlgLibraryMirror->m_bLibraryMirrorPieceObtained)
    {
        if (PtInPolygon(point, m_mirrorPoints, 5)) {
            AfxMessageBox(_T("이미 얻은 거울조각이다."));
            return; // 다이얼로그를 열지 않고 반환
        }
    }

    if (m_pDlgLibraryMiniGame && m_pDlgLibraryMiniGame->m_bLibrarySafeOpened)
    {
        if (m_rectLibraryMiniGame.PtInRect(point)) {
            AfxMessageBox(_T("금고는 이미 열었다."));
            return; // 다이얼로그를 열지 않고 반환
        }
    }

    // 거울 영역을 클릭했을 때
    if (PtInPolygon(point, m_mirrorPoints, 5)) {
        AfxMessageBox(_T("거울을 클릭했습니다."));

        // 거울 조각을 얻었는지 확인
        if (m_pDlgLibraryMirror == nullptr)
        {
            m_pDlgLibraryMirror = new CDlg_library_mirror();  // 동적으로 다이얼로그 인스턴스 생성
        }

        // 다이얼로그 열기
        if (m_pDlgLibraryMirror != nullptr)
        {
            m_pDlgLibraryMirror->DoModal(); // 모달 다이얼로그 실행

            // 다이얼로그가 닫힌 후 거울 조각 획득 상태 확인

        }
    }

    if (PtInPolygon(point, m_journeyPoints, 6)) {
        AfxMessageBox(_T("일지를 클릭했습니다."));
        CDlg_library_journey jour;
        jour.DoModal();
    }

    if (m_rectLibraryMiniGame.PtInRect(point)) {
        AfxMessageBox(_T("금고를 클릭했습니다."));

        // 거울 조각을 얻었는지 확인
        if (m_pDlgLibraryMiniGame == nullptr)
        {
            m_pDlgLibraryMiniGame = new CDlg_library_minigame();  // 동적으로 다이얼로그 인스턴스 생성
        }

        // 다이얼로그 열기
        if (m_pDlgLibraryMiniGame != nullptr)
        {
            m_pDlgLibraryMiniGame->DoModal(); // 모달 다이얼로그 실행

            // 다이얼로그가 닫힌 후 거울 조각 획득 상태 확인

        }
    }
    CString strPos;
    strPos.Format(_T("클릭한 좌표: (%d, %d)"), point.x, point.y);

    // 좌표를 메시지 박스로 띄우기
    AfxMessageBox(strPos);

    CDialogEx::OnLButtonDown(nFlags, point);
}


void CDlg_library::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    // 마우스가 클릭 가능한 영역 안에 있는 경우
    if (PtInPolygon(point, m_mirrorPoints, 5)|| PtInPolygon(point, m_journeyPoints, 6)|| m_rectLibraryMiniGame.PtInRect(point))
    {
        if (!m_bLibrary_Is_Hover) // 상태가 변경될 때만 처리
        {
            m_bLibrary_Is_Hover = true;
            ::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND)); // 손 모양 커서
        }
    }
    // 마우스가 클릭 가능한 영역 밖으로 나간 경우
    else
    {
        if (m_bLibrary_Is_Hover) // 상태가 변경될 때만 처리
        {
            m_bLibrary_Is_Hover = false;
            ::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW)); // 기본 커서
        }
    }
    CDialogEx::OnMouseMove(nFlags, point);
}



BOOL CDlg_library::OnSetCursor(CWnd * pWnd, UINT nHitTest, UINT message)
    {
        if (m_bLibrary_Is_Hover) {
            // 이미 손 모양 커서가 설정되었으면 추가 처리를 하지 않음
            return true;  // 커서 설정 완료
        }
        return CDialogEx::OnSetCursor(pWnd, nHitTest, message);  // 기본 처리
    }
