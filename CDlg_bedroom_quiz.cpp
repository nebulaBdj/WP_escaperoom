// CDlg_bedroom_quiz.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_bedroom_quiz.h"
#include "CDlg_bedroom_safety.h"


// CDlg_bedroom_quiz 대화 상자

IMPLEMENT_DYNAMIC(CDlg_bedroom_quiz, CDialogEx)

CDlg_bedroom_quiz::CDlg_bedroom_quiz(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_BEDROOM_QUIZ, pParent)
	, m_strBedroomQuizUser(_T(""))
	, m_strBedroomQuizCorrect(_T("7321"))
{

	
}

CDlg_bedroom_quiz::~CDlg_bedroom_quiz()
{
}

void CDlg_bedroom_quiz::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BEDROOM_QUIZ_USERANSWER, m_strBedroomQuizUser);
}


BEGIN_MESSAGE_MAP(CDlg_bedroom_quiz, CDialogEx)
//	ON_EN_CHANGE(IDC_EDIT_BEDROOM_QUIZ_USERANSWER, &CDlg_bedroom_quiz::OnEnChangeEditBedroomQuizUseranswer)
ON_EN_CHANGE(IDC_EDIT_BEDROOM_QUIZ_USERANSWER, &CDlg_bedroom_quiz::OnEnChangeEditBedroomQuizUseranswer)
ON_BN_CLICKED(IDC_BUTTON_BEDROOM_QUIZ_BUTTON, &CDlg_bedroom_quiz::OnBnClickedButtonBedroomQuizButton)
END_MESSAGE_MAP()


// CDlg_bedroom_quiz 메시지 처리기


//void CDlg_bedroom_quiz::OnEnChangeEditBedroomQuizUseranswer()
//{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
//}


void CDlg_bedroom_quiz::OnEnChangeEditBedroomQuizUseranswer()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}



void CDlg_bedroom_quiz::OnBnClickedButtonBedroomQuizButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);


	if (m_strBedroomQuizUser == m_strBedroomQuizCorrect) {
		AfxMessageBox(_T("금고가 열렸다."), MB_OK);
		CDialogEx::OnOK();
		CDlg_bedroom_safety safety;
		if (safety.DoModal() == IDOK) {
			CDialogEx::OnOK();  // 금고 다이얼로그 종료

		}
	}
	else {
		AfxMessageBox(_T("아닌 거 같다. 다시 해 보자."));
	}
}


BOOL CDlg_bedroom_quiz::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		// 기본 Enter 동작을 막음
		return TRUE;  // 메시지를 처리했음을 반환
	}

	// Esc 키 처리 (필요하다면)
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;  // 메시지를 처리했음을 반환
	}
	
	return CDialogEx::PreTranslateMessage(pMsg);
}
