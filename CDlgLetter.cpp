// CDlgLetter.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlgLetter.h"


// CDlgLetter 대화 상자

IMPLEMENT_DYNAMIC(CDlgLetter, CDialogEx)

CDlgLetter::CDlgLetter(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDlgLetter::~CDlgLetter()
{
}

void CDlgLetter::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgLetter, CDialogEx)
	ON_WM_CLOSE() // WM_CLOSE 메시지 매핑
	ON_STN_CLICKED(IDC_STATIC_LETTER, &CDlgLetter::OnStnClickedStaticLetter)
END_MESSAGE_MAP()


// CDlgLetter 메시지 처리기

void CDlgLetter::OnStnClickedStaticLetter()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}



void CDlgLetter::OnClose()
{
	// 다이얼로그가 닫힐 때 메시지 출력
	AfxMessageBox(_T("편지를 다 읽었다."
		"\n테일러는 누군가에게 협박편지를 받아온 것 같군"), MB_ICONINFORMATION);

	// 부모 클래스의 OnClose 호출 (다이얼로그 종료 처리)
	CDialogEx::OnClose();
}
