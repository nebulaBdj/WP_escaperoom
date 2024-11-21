// CDlg_doorStep.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_doorStep.h"

//!!내가 추가한 부분
#include "CDlgLetter.h"
#include "CDlgMirror.h"

// CDlg_doorStep 대화 상자

IMPLEMENT_DYNAMIC(CDlg_doorStep, CDialogEx)

CDlg_doorStep::CDlg_doorStep(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_DOORSTEP, pParent)
{	

}

CDlg_doorStep::~CDlg_doorStep()
{
}

void CDlg_doorStep::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_MAINHALL, m_doorPictureControl);
}



BEGIN_MESSAGE_MAP(CDlg_doorStep, CDialogEx)
	ON_WM_LBUTTONDOWN() //!! 내가 추가한 부분
	//ON_WM_MOUSEMOVE() //!!내가 추가한부분
	//ON_STN_CLICKED(IDC_STATIC_DOORSTEP, &CDlg_doorStep::OnStnClickedStaticPicture1)
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CDlg_doorStep 메시지 처리기

BOOL CDlg_doorStep::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect parentRect;
	CWnd* pParent = GetParent();
	pParent->GetWindowRect(&parentRect); // 부모 다이얼로그의 전체 크기(스크린 좌표)
	ScreenToClient(&parentRect);
	m_doorPictureControl.MoveWindow(&parentRect); // 범인
	
	doorstep_is_hober = false;

	// 사각형 영역 초기화
	m_doorstep_guestBookRect.SetRect(718, 512, 884, 522); // 임의의 좌표 예시
	m_doorstep_letterRect.SetRect(420, 768, 986, 829);
	m_doorstep_curios.SetRect(919, 777, 1247, 832);
	m_doorstep_chandelier.SetRect(616, 13, 978, 207);
	m_doorstep_getMirror.SetRect(973, 564, 1167, 593);

	m_doorstep_clickableRect_guestBookRect.SetRect(718, 512, 884, 522);
	m_doorstep_clickableRect_letterRect.SetRect(420, 768, 986, 829);
	m_doorstep_clickableRect_curios.SetRect(919, 777, 1247, 832);
	m_doorstep_clickableRect_chandelier.SetRect(616, 13, 978, 207);
	m_doorstep_clickableRect_getMirror.SetRect(973, 564, 1167, 593);


	return TRUE; // 대화 상자 초기화 성공
}

void CDlg_doorStep::OnLButtonDown(UINT nFlags, CPoint point)
{
	//클릭 좌표 위치 보여주는 코드
	CString strCoordinates;
	strCoordinates.Format(_T("클릭한 좌표: (%d, %d)"), point.x, point.y);
	AfxMessageBox(strCoordinates);

	// 클릭 위치가 특정 사각형에 포함되는지 확인
	if (m_doorstep_guestBookRect.PtInRect(point))
	{
		AfxMessageBox(_T("파티에 초대된 사람이 적힌 방명록이다. 초대되지 않은 손님이 왔다는 것을, "
			"저택의 주인은 마지막 순간까지 몰랐을 것이다"), MB_ICONQUESTION);
	}
	else if (m_doorstep_letterRect.PtInRect(point))
	{
		int res = AfxMessageBox(_T("책상위에 편지가 놓여있다. 읽어볼까?"), MB_YESNO | MB_ICONQUESTION);
		if (res == IDYES) {
			// 편지의 내용을 보여주는 다이얼로그를 출력하는 코드
			CDlgLetter letterDlg;
			letterDlg.DoModal();
		}
		else {
			AfxMessageBox(_T("죽은 자의 편지를 읽는건 역시 꺼림직하다."), MB_ICONWARNING);
		}
	}
	else if (m_doorstep_curios.PtInRect(point))
	{
		AfxMessageBox(_T("고가의 골동품이다. 곳곳에 관리가 잘 된 골동품이 보인다"));
		int result3 = AfxMessageBox(_T("골동품을 구경을 위해 들어봤더니 그 아래 열쇠가 보인다."
			"남의 물건이지만.. 사건 해결을 위해 챙겨야겠지? "), MB_YESNO | MB_ICONQUESTION);

		if (result3 == IDYES)
		{
			// 인벤토리에 아이템 추가 로직
			AfxMessageBox(_T("열쇠를 챙겼다.."), MB_ICONINFORMATION);
			// 예시: 실제 인벤토리 배열 또는 리스트에 추가하는 코드 작성
		}
		else
		{
			AfxMessageBox(_T("조금 더 생각해보자."), MB_ICONINFORMATION);
		}
	}
	else if (m_doorstep_chandelier.PtInRect(point))
	{
		AfxMessageBox(_T("상당한 고가의 샹들리에다. 이 저택의 주인은 분명 대부호겠지."), MB_ICONINFORMATION);
	}
	else if (m_doorstep_getMirror.PtInRect(point))
	{
		int result4 = AfxMessageBox(_T("서랍을 열어보니 깨진 거울 조각이 보인다."
			"자세히 살펴볼까??"), MB_YESNO | MB_ICONQUESTION);
		if (result4 == IDYES) {
			// 거울 조각 다이얼로그를 띄움
			CDlgMirror MirrorDlg;
			MirrorDlg.DoModal();
		}

	}

	// 부모 클래스의 기본 동작 호출
	CDialogEx::OnLButtonDown(nFlags, point);
}

void CDlg_doorStep::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 마우스가 사각형 내부에 있는지 확인
	if (m_doorstep_clickableRect_guestBookRect.PtInRect(point) || m_doorstep_clickableRect_letterRect.PtInRect(point)
		|| m_doorstep_clickableRect_curios.PtInRect(point) || m_doorstep_chandelier.PtInRect(point)
		|| m_doorstep_clickableRect_getMirror.PtInRect(point))
	{
		if (!doorstep_is_hober) {
			doorstep_is_hober = true;
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HAND)); // 손 모양 커서
		}
	}
	else
	{
		if (doorstep_is_hober) {
			doorstep_is_hober = false;
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW)); // 기본 커서
		}
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


BOOL CDlg_doorStep::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return true;
}
