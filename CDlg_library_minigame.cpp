// CDlg_library_minigame.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_library_minigame.h"
#include "CDlg_library_answer.h"

// CDlg_library_minigame 대화 상자

IMPLEMENT_DYNAMIC(CDlg_library_minigame, CDialogEx)

CDlg_library_minigame::CDlg_library_minigame(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DLG_LIBRARY_MINIGAME, pParent)
{

}

CDlg_library_minigame::~CDlg_library_minigame()
{
}

void CDlg_library_minigame::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BOOL CDlg_library_minigame::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  여기에 추가 초기화 작업을 추가합니다.
    m_rectLibrarySafe.SetRect(20, 20, 600, 600);
    m_bLibrarySafeOpened = FALSE;

    return TRUE;  // return TRUE unless you set the focus to a control
    // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BEGIN_MESSAGE_MAP(CDlg_library_minigame, CDialogEx)
    ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CDlg_library_minigame 메시지 처리기


void CDlg_library_minigame::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    CDlg_library_answer ans;

    AfxMessageBox(_T("영어 6자를 입력할 수 있는 금고가 있다."));
    if (ans.DoModal() == IDOK)  // 다이얼로그 표시
    {
        CString strCorrectAnswer = _T("REGRET");  // 정답 설정
        if (m_rectLibrarySafe.PtInRect(point)) {
            // 사용자가 입력한 정답 확인
            if (m_bLibrarySafeOpened == FALSE) {
                if (ans.m_strLibraryAnswer.CompareNoCase(strCorrectAnswer) == 0) // 대소문자 구분 없이 비교
                {
                    AfxMessageBox(_T("(덜컹...) 어디선가 문이 열리는 소리가 났다."));
                    m_bLibrarySafeOpened = TRUE;
                    EndDialog(IDOK);
                }

                else if (ans.m_strLibraryAnswer.GetLength() > 6) {
                    AfxMessageBox(_T("영어 6자만 입력할 수 있다."));
                }

                else
                {
                    AfxMessageBox(_T("답이 아닌 듯 하다..."));
                }
            }
        }
    }
    CDialogEx::OnLButtonDown(nFlags, point);
}




