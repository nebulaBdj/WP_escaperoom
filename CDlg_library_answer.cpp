// CDlg_library_answer.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_library_answer.h"


// CDlg_library_answer 대화 상자

IMPLEMENT_DYNAMIC(CDlg_library_answer, CDialogEx)

CDlg_library_answer::CDlg_library_answer(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_LIBRARY_ANSWER, pParent)
{

}

CDlg_library_answer::~CDlg_library_answer()
{
}

void CDlg_library_answer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INPUT, m_strLibraryAnswer);
}


BEGIN_MESSAGE_MAP(CDlg_library_answer, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LIBRARY_OK, &CDlg_library_answer::OnBnClickedButtonCheck)
	ON_EN_CHANGE(IDC_EDIT_INPUT, &CDlg_library_answer::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CDlg_library_answer 메시지 처리기

BOOL CDlg_library_answer::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 추가적인 초기화 코드가 있으면 여기에 작성
	return TRUE;
}

void CDlg_library_answer::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}



//void CDlg_library_answer::OnOK()
//{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

//	CDialogEx::OnOK();
//}
void CDlg_library_answer::OnBnClickedButtonCheck()
{
	UpdateData(TRUE);
	if (m_strLibraryAnswer.IsEmpty())
	{
		AfxMessageBox(_T("답을 입력해주세요."));
		return;
	}

	EndDialog(IDOK);
}

void CDlg_library_answer::OnEnChangeEditInput()
{
	if (GetDlgItem(IDC_EDIT_INPUT)->GetSafeHwnd() != NULL)
	{
		// Enter 키를 눌렀을 때
		if (GetAsyncKeyState(VK_RETURN))
		{
			OnBnClickedButtonCheck();  // 확인 버튼 클릭과 동일한 동작 수행
		}
	}
}
