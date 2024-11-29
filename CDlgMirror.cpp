// CDlgMirror.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlgMirror.h"


// CDlgMirror 대화 상자

IMPLEMENT_DYNAMIC(CDlgMirror, CDialogEx)

CDlgMirror::CDlgMirror(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIG_DOORSTEP_MIRROR, pParent)
{

}

CDlgMirror::~CDlgMirror()
{
}

void CDlgMirror::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMirror, CDialogEx)
	ON_WM_CLOSE() // WM_CLOSE 메시지 매핑
END_MESSAGE_MAP()


// CDlgMirror 메시지 처리기


void CDlgMirror::OnStnClickedStaticMirror()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CDlgMirror::OnClose()
{
	// 다이얼로그가 닫힐 때 메시지 출력
	int choice = AfxMessageBox(_T("소중하게 보관되어 있던 깨진 거울 조각이다."
		"\n사건 해결에는 관련이 없어보이지만.. 챙겨야 할까?"), MB_YESNO | MB_ICONQUESTION);
	if (choice == IDYES && !door_step_isMirror) {
		AfxMessageBox(_T("유리 조각을 조심스럽게 가방에 넣었다."));
		mirror_count += 1;
		door_step_isMirror = !door_step_isMirror;
	}
	else {
		AfxMessageBox(_T("어째선지 가져가선 안될 것 같은 느낌이 든다."));
	}
	// 부모 클래스의 OnClose 호출 (다이얼로그 종료 처리)
	CDialogEx::OnClose();
}