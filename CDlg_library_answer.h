#pragma once
#include "afxdialogex.h"

// CDlg_library_answer 대화 상자

class CDlg_library_answer : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_library_answer)

public:
	CDlg_library_answer(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_library_answer();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ANSWER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();  // 다이얼로그 초기화 함수
	afx_msg void OnBnClickedButtonCheck();  // '확인' 버튼 클릭 이벤트 핸들러
	afx_msg void OnEnChangeEditInput();  // 텍스트 변경 이벤트 핸들러
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString m_strLibraryAnswer;
	//	virtual void OnOK();
};
