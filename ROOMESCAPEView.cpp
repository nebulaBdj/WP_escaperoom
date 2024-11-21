
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

void CROOMESCAPEView::OnDraw(CDC* /*pDC*/)
{
	CROOMESCAPEDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
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
	CDlg_tabControls dlg_tabControls;
	if (dlg_tabControls.DoModal() == IDC_BUTTON_LIBRARY_OK) {
	}
	CView::OnRButtonDown(nFlags, point);
}
