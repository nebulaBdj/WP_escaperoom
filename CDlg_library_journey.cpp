// CDlg_library_journey.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_library_journey.h"


// CDlg_library_journey 대화 상자

IMPLEMENT_DYNAMIC(CDlg_library_journey, CDialogEx)

CDlg_library_journey::CDlg_library_journey(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DLG_LIBRARY_JOURNEY, pParent)
{

}

CDlg_library_journey::~CDlg_library_journey()
{
}

void CDlg_library_journey::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_library_journey, CDialogEx)
    ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CDlg_library_journey 메시지 처리기


void CDlg_library_journey::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    if (m_rectLibraryJourney.PtInRect(point)) {
        CString strText = _T("마법 거울과 그 날의 진실\n"
            "\n"
            "오늘, 나는 진실을 알려주는 마법 거울에 대한 이야기를 들었다. "
            "이 거울은 단순한 물건이 아니다. 그것은 내면의 진실을 드러내고, "
            "내가 감추고 있던 비밀과 후회까지도 보여준다. 이 거울을 통해 나는 "
            "나의 과거를 직면해야 할 것임을 깨달았다.\n"
            "나는 동료를 배신했던 순간을 잊을 수 없다. 그때의 선택이 얼마나 "
            "잘못된 것이었는지, 그로 인해 그가 겪었을 고통을 생각하면 마음이 아프다. "
            "배신의 대가로 얻은 것은 아무것도 없었다. 오히려 잃은 것이 더 많았고, "
            "그로 인해 나의 양심은 무거워졌다.\n"
            "이제 나는 그에게 진심으로 사과하고 싶다. 내가 저지른 잘못을 인정하고, "
            "그가 겪었을 상처에 대한 책임을 지고 싶다. 용서받을 수 있을지는 모르겠지만, "
            "내 마음속의 짐을 덜고 싶다. 마법 거울이 나에게 보여준 진실이 나를 변화시키길 바란다.\n"
        );

        // 메시지 박스에서 경고문 아이콘 없이 텍스트만 표시
        // MessageBox(strText, _T("일지 항목"), MB_OK);
    }
    CDialogEx::OnLButtonDown(nFlags, point);
}


BOOL CDlg_library_journey::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  여기에 추가 초기화 작업을 추가합니다.
    m_rectLibraryJourney.SetRect(50, 50, 1000, 1000);
    return TRUE;  // return TRUE unless you set the focus to a control
    // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}