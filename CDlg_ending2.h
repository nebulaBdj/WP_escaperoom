#pragma once
#include "afxdialogex.h"
#include "CDlg_ending3.h"

#define ENEMY_COUNT 20
#define FAST_ENEMY_COUNT 5
#define GRID_POINT_COUNT 300

// CDlg_ending2 대화 상자

class CDlg_ending2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_ending2)

public:
	CDlg_ending2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlg_ending2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ENDING2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	CDlg_ending3* dlg_ending3;
	int inGameTime;
	int playerPosition_x;
	int playerPosition_y;
	struct ENEMY {
		int x;
		int y;
		int target_x; // 목표 x 좌표
		int target_y; // 목표 y 좌표
	};
	ENEMY enemies[ENEMY_COUNT];
	ENEMY fast_enemies[FAST_ENEMY_COUNT];
	CBitmap m_bitmap;  // 메모리 비트맵
	CDC m_memDC;       // 메모리 DC
	CRect gridRects[100];
	CRect goal_spot;
	bool ending_is_goal;
	int rect_count;
	int is_player_inRect;
	int point_count;
	CPoint gridPoints[GRID_POINT_COUNT];     // 생성한 점들을 저장할 배열
	void SetNewTarget(ENEMY& enemy);
	float lerp(float start, float end, float t);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
};
