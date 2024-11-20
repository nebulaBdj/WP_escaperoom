#pragma once
#include "afxdialogex.h"
#include <GdiPlus.h>

// CDlg_doorStep 대화 상자

class CDlg_doorStep : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_doorStep)

public:
	CDlg_doorStep(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_doorStep();

	CRect m_guestBookRect; //!!여기서 부터 내가 추가
	CRect m_letterRect;
	CRect m_mirrorPieceRect;
	CRect m_curios;
	CRect m_Chandelier;
	ULONG_PTR gdiplusToken;

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
	void SetPictureControlImage(UINT nControlID, const CString& strImagePath);
	//void OnMouseMove(UINT nFlags, CPoint point);
	
	CStatic m_doorPictureControl;
};
