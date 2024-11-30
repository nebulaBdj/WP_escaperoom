
// ROOMESCAPEView.cpp: CROOMESCAPEView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ROOMESCAPE.h"
#endif

#include "ROOMESCAPEDoc.h"
#include "ROOMESCAPEView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CROOMESCAPEView

IMPLEMENT_DYNCREATE(CROOMESCAPEView, CView)

BEGIN_MESSAGE_MAP(CROOMESCAPEView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()

// CROOMESCAPEView 생성/소멸

CROOMESCAPEView::CROOMESCAPEView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CROOMESCAPEView::~CROOMESCAPEView()
{
}

BOOL CROOMESCAPEView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CROOMESCAPEView 그리기

void CROOMESCAPEView::OnDraw(CDC* pDC)
{
	CROOMESCAPEDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	UINT bitmapID = IDB_BITMAP_SINOPSIS3;
	if (view_count == 1) // 여기에 조건을 추가
	{
		bitmapID = IDB_BITMAP_SINOPSIS4; // 다른 비트맵
	}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	// 비트맵 로드
	CBitmap bitmap;
	bitmap.LoadBitmap(bitmapID); // IDB_MY_BITMAP은 리소스 ID입니다.

	// 비트맵 정보 가져오기
	BITMAP bmp;
	bitmap.GetBitmap(&bmp);

	// 메모리 DC 생성
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);

	// 비트맵 선택
	CBitmap* pOldBitmap = memDC.SelectObject(&bitmap);

	// 화면에 비트맵 그리기
	pDC->BitBlt(0, 0, bmp.bmWidth, bmp.bmHeight, &memDC, 0, 0, SRCCOPY);

	// 원래 비트맵 복원
	memDC.SelectObject(pOldBitmap);
}


// CROOMESCAPEView 인쇄

BOOL CROOMESCAPEView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CROOMESCAPEView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CROOMESCAPEView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CROOMESCAPEView 진단

#ifdef _DEBUG
void CROOMESCAPEView::AssertValid() const
{
	CView::AssertValid();
}

void CROOMESCAPEView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CROOMESCAPEDoc* CROOMESCAPEView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CROOMESCAPEDoc)));
	return (CROOMESCAPEDoc*)m_pDocument;
}
#endif //_DEBUG


// CROOMESCAPEView 메시지 처리기


void CROOMESCAPEView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnRButtonDown(nFlags, point);
}



int CROOMESCAPEView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


void CROOMESCAPEView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	view_count = 0;
	// 부모 CMDIChildWnd의 크기를 조정
	CMDIChildWnd* pParentFrame = static_cast<CMDIChildWnd*>(GetParentFrame());
	if (pParentFrame && pParentFrame->GetSafeHwnd())
	{
		pParentFrame->SetWindowPos(NULL, 0, 0, 1600, 800, SWP_NOZORDER | SWP_NOMOVE);
		// 클라이언트 영역 동기화
		CRect rect;
		pParentFrame->GetClientRect(&rect);
		this->MoveWindow(&rect); // View 크기 조정

		// MDI 프레임 창 크기를 1600 x 800으로 설정
		CRect rect2;
		CMDIFrameWnd* pMDIFrame = static_cast<CMDIFrameWnd*>(AfxGetMainWnd());
		pMDIFrame->GetWindowRect(&rect2);

		// 현재 위치를 유지하며 너비와 높이만 변경
		int x = rect2.left;
		int y = rect2.top;
		int width = 1620;
		int height = 920;

		// MDI 프레임 크기 변경
		pMDIFrame->MoveWindow(x, y, width, height);
	}
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	
}



void CROOMESCAPEView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (view_count == 1) {
		CDlg_tabControls* dlg_tabControls = new CDlg_tabControls();
		if (dlg_tabControls->Create(IDD_DLG_TAPCONTROL, this)) {
			dlg_tabControls->ShowWindow(SW_SHOW);
		}

		CDlg_inventory* dlg_inventory = new CDlg_inventory();
		if (dlg_inventory->Create(IDD_DIALOG_INVENTORY, this)) {
			dlg_inventory->ShowWindow(SW_SHOW);
			CRect tabRect;
			dlg_tabControls->GetWindowRect(&tabRect); // 화면 좌표 기준 위치와 크기 가져오기

			// 인벤토리 다이얼로그를 탭 컨트롤 다이얼로그 오른쪽으로 배치
			dlg_inventory->SetWindowPos(NULL,
				tabRect.right,  // 오른쪽으로 10픽셀 떨어진 위치
				tabRect.top,         // Y 좌표는 동일하게 설정
				0, 0,
				SWP_NOSIZE | SWP_NOZORDER); // 크기와 Z-order는 변경하지 않음

			dlg_inventory->SetWindowPos(&CWnd::wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}
	}

	if (view_count == 0) {
		CRect rect(656, 581, 949, 667);
		if (rect.PtInRect(point)) {
			view_count++;
			Invalidate();
		}
	}

	CView::OnLButtonDown(nFlags, point);
}


void CROOMESCAPEView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnMouseMove(nFlags, point);
}


BOOL CROOMESCAPEView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CView::OnSetCursor(pWnd, nHitTest, message);
}
