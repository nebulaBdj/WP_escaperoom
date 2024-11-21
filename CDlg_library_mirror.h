#pragma once
#include "afxdialogex.h"


// CDlg_library_mirror 대화 상자

class CDlg_library_mirror : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_library_mirror)

public:
	CDlg_library_mirror(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_library_mirror();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MIRROR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//	int m_rectLibraryMirrorPiece;
	CRect m_rectLibraryMirrorPiece;
	virtual BOOL OnInitDialog();
	//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	bool m_bLibraryMirrorPieceObtained;
};
