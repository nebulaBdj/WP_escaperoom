#pragma once
#include "afxdialogex.h"
#include "CDlg_library_mirror.h"
#include "CDlg_library_minigame.h"

// CDlg_library 대화 상자

class CDlg_library : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_library)

public:
	CDlg_library(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_library();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LIBRARY };
#endif

public:
	CDlg_library_mirror* m_pDlgLibraryMirror; // CDlg_library_mirror 포인터를 멤버 변수로 추가
	CDlg_library_minigame* m_pDlgLibraryMiniGame;
public:
	CDlg_library(CDlg_library_mirror* pDlgMirror); // 생성자에서 인스턴스를 받음
	CDlg_library(CDlg_library_minigame* pDlgMinigame);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

	CRect m_rectLibraryMirror;
	CRect m_rectLibraryJourney;
	CRect m_rectLibraryMiniGame;
	POINT m_mirrorPoints[5];  // Mirror 좌표 배열
	POINT m_journeyPoints[6]; // Journey 좌표 배열

public:
	//	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//	virtual BOOL OnInitDialog();
	//	afx_msg void OnPaint();
	//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	BOOL PtInPolygon(CPoint point, POINT* pPolygon, int nPoints);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CRect m_rectLibraryClickable;
	int m_bLibrary_Is_Hover;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};