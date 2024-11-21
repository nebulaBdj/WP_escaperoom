#pragma once
#include "afxdialogex.h"


// CDlg_doorStep 대화 상자

class CDlg_doorStep : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_doorStep)

public:
	CDlg_doorStep(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_doorStep();
	CStatic m_doorPictureControl;

	CRect m_doorstep_clickableRect_guestBookRect;
	CRect m_doorstep_clickableRect_letterRect;
	CRect m_doorstep_clickableRect_curios;
	CRect m_doorstep_clickableRect_chandelier;
	CRect m_doorstep_clickableRect_getMirror;

	bool doorstep_is_hober;

	CRect m_doorstep_guestBookRect; //!!여기서 부터 내가 추가
	CRect m_doorstep_letterRect;
	CRect m_doorstep_curios;
	CRect m_doorstep_chandelier;
	CRect m_doorstep_getMirror;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_DOORSTEP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public: // !!내가 추가한 부분
	afx_msg BOOL OnInitDialog(); // 초기화 처리
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point); // 클릭 처리
	//void SetPictureControlImage(UINT nControlID, const CString& strImagePath);
	//void OnMouseMove(UINT nFlags, CPoint point);

	//void OnStnClickedStaticPicture1();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);

};
