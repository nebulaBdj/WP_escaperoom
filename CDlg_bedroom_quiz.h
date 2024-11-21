#pragma once
#include "afxdialogex.h"


// CDlg_bedroom_quiz 대화 상자

class CDlg_bedroom_quiz : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_bedroom_quiz)

public:
	CDlg_bedroom_quiz(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_bedroom_quiz();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_BEDROOM_QUIZ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
private:
	CString m_strBedroomQuizUser;
	
public:
//	afx_msg void OnEnChangeEditBedroomQuizUseranswer();
	
	afx_msg void OnEnChangeEditBedroomQuizUseranswer();
	afx_msg void OnBnClickedButtonBedroomQuizButton();
private:
	CString m_strBedroomQuizCorrect;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
