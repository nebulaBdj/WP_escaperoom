// CDlg_ending2.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_ending2.h"
#include "CDlg_ending4.h"
#include "CDlg_ending5.h"


// CDlg_ending2 대화 상자

IMPLEMENT_DYNAMIC(CDlg_ending2, CDialogEx)

CDlg_ending2::CDlg_ending2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ENDING2, pParent)
{

}

CDlg_ending2::~CDlg_ending2()
{
}

void CDlg_ending2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_ending2, CDialogEx)
	ON_WM_TIMER()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlg_ending2 메시지 처리기


BOOL CDlg_ending2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect bitRect(0, 0, 1600, 800);

	CClientDC dc(this);
	m_memDC.CreateCompatibleDC(&dc);
	m_bitmap.CreateCompatibleBitmap(&dc, bitRect.Width(), bitRect.Height());
	m_memDC.SelectObject(&m_bitmap);
	m_memDC.FillSolidRect(bitRect, RGB(255, 255, 255));

	// 배경 그리기 (그리드)
	CBrush blueBrush(RGB(0, 128, 255)); // 파란색 브러시 생성
	CBrush* pOldBrush = m_memDC.SelectObject(&blueBrush);
	rect_count = 0;
	for (int x = 0; x <= 1600; x += 125) {
		for (int y = 0; y <= 800; y += 125) {
			CRect rect(x, y, x + 75, y + 75);
			m_memDC.Rectangle(rect);
			gridRects[rect_count++] = rect;
		}
	}
	//목표 지점에 도착했는지 판단하는 변수, 초기상태 false
	ending_is_goal = false;

	// 점을 생성하고 저장 (125 간격으로 생성)
	point_count = 0;  // 점의 개수 초기화
	for (int x = 100; x <= 1600; x += 125) {
		for (int y = 100; y <= 800; y += 125) {
			if (point_count < GRID_POINT_COUNT) { // 배열의 크기 초과하지 않도록 확인
				gridPoints[point_count++] = CPoint(x, y);
			}
		}
	}

	// 적 초기화 및 초기 목표 설정
	for (int i = 0; i < ENEMY_COUNT; ++i) {
		enemies[i].x = gridPoints[rand() % point_count].x;  // 적의 초기 위치를 랜덤 점으로 설정
		enemies[i].y = gridPoints[rand() % point_count].y;
		SetNewTarget(enemies[i]); // 적의 초기 목표 지점을 설정
	}
	for (int i = 0; i < FAST_ENEMY_COUNT; ++i) {
		fast_enemies[i].x = gridPoints[rand() % point_count].x;  // 적의 초기 위치를 랜덤 점으로 설정
		fast_enemies[i].y = gridPoints[rand() % point_count].y;
		SetNewTarget(fast_enemies[i]); // 적의 초기 목표 지점을 설정
	}

	goal_spot.SetRect(1460, 710, 1490, 740);

	playerPosition_x = 0;
	playerPosition_y = 120;
	inGameTime = 30;

	SetTimer(1, 16, NULL); //프레임 실행 함수
	SetTimer(2, 1000, NULL); //게임 내 타이머 1000ms (1초)마다 호출. 아이디는 2
	CRect rect(0, 0, 1600, 840);
	MoveWindow(&rect);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_ending2::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 1) // 타이머 ID 확인
	{
		//빈공간
	}
	if (nIDEvent == 2) // 게임 타이머 ID 확인
	{
		inGameTime--;
		if (inGameTime == 0) {
			AfxMessageBox(_T("당신은 끝내 경찰의 추격을 피해 도망치는데 성공하셨습니다."));
			KillTimer(2);
			ending_is_goal = true;
			CDlg_ending3 dlg_ending3;
			dlg_ending3.DoModal();
			PostMessage(WM_CLOSE);
		}
	}

	if (goal_spot.PtInRect(CPoint(playerPosition_x, playerPosition_y))) {
		if (!ending_is_goal) {
			KillTimer(1);
			KillTimer(2);
			int response = AfxMessageBox(_T("당신은 경찰서에 자수를 하였습니다."), MB_OK | MB_ICONINFORMATION);
			ending_is_goal = true;
			CDlg_ending4 dlg_ending4;
			dlg_ending4.DoModal();
			PostMessage(WM_CLOSE);
		}
	}
	int player_size = 20;
	CRect player(playerPosition_x - player_size, playerPosition_y - player_size, playerPosition_x + player_size, playerPosition_y + player_size);
	for (int i = 0; i < ENEMY_COUNT; ++i) {
		if (player.PtInRect(CPoint(enemies[i].x, enemies[i].y))) {
			KillTimer(1);
			KillTimer(2);
			int response = AfxMessageBox(_T("당신은 도주중 경찰에게 붙잡혔습니다."), MB_OK | MB_ICONINFORMATION);
			ending_is_goal = true;
			CDlg_ending5 dlg_ending5; //이거 ending4로 바꿔놓기 나중에 
			dlg_ending5.DoModal();
			PostMessage(WM_CLOSE);
		}
	}
	for (int i = 0; i < FAST_ENEMY_COUNT; ++i) {
		if (player.PtInRect(CPoint(fast_enemies[i].x, fast_enemies[i].y))) {
			KillTimer(1);
			KillTimer(2);
			int response = AfxMessageBox(_T("당신은 도주중 경찰에게 붙잡혔습니다."), MB_OK | MB_ICONINFORMATION);
			ending_is_goal = true;
			CDlg_ending5 dlg_ending5; //이거 ending4로 바꿔놓기 나중에 
			dlg_ending5.DoModal();
			PostMessage(WM_CLOSE);
		}
	}

	is_player_inRect = 0;
	int player_speed = 10;
	int temp_position_x = playerPosition_x;
	int temp_position_y = playerPosition_y;

	// 키 입력 상태 확인
	//if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		//player_speed = 20;
	//}

	if (GetAsyncKeyState('W') & 0x8000) { // W 키가 눌린 상태라면
		if (playerPosition_y > 0) {
			temp_position_y -= player_speed; // 속도만큼 y 좌표 감소
		}
	}
	if (GetAsyncKeyState('A') & 0x8000) { // A 키가 눌린 상태라면
		if (playerPosition_x > 0) {
			temp_position_x -= player_speed; // 속도만큼 x 좌표 감소
		}
	}
	if (GetAsyncKeyState('S') & 0x8000) { // S 키가 눌린 상태라면
		if (playerPosition_y < 800) {
			temp_position_y += player_speed; // 속도만큼 y 좌표 증가
		}
	}
	if (GetAsyncKeyState('D') & 0x8000) { // D 키가 눌린 상태라면
		if (playerPosition_x < 1600) {
			temp_position_x += player_speed; // 속도만큼 x 좌표 증가
		}
	}

	// 플레이어가 사각형 안에 있는지 검사
	for (int i = 0; i < rect_count; ++i) {
		if (gridRects[i].PtInRect(CPoint(temp_position_x, temp_position_y))) {
			is_player_inRect = 1;
			break;
		}
	}

	if (!is_player_inRect) {
		playerPosition_x = temp_position_x;
		playerPosition_y = temp_position_y;
	}


	int move_speed = 5;
	int spark_value = 5;

	// 적의 격자 기반 이동
	for (int i = 0; i < ENEMY_COUNT; ++i) {
		if (enemies[i].x < enemies[i].target_x) {
			enemies[i].x += move_speed;
			if (enemies[i].x > enemies[i].target_x) enemies[i].x = enemies[i].target_x; // 목표 위치 도달 시 조정
		}
		else if (enemies[i].x > enemies[i].target_x) {
			enemies[i].x -= move_speed;
			if (enemies[i].x < enemies[i].target_x) enemies[i].x = enemies[i].target_x; // 목표 위치 도달 시 조정
		}

		if (enemies[i].y < enemies[i].target_y) {
			enemies[i].y += move_speed;
			if (enemies[i].y > enemies[i].target_y) enemies[i].y = enemies[i].target_y; // 목표 위치 도달 시 조정
		}
		else if (enemies[i].y > enemies[i].target_y) {
			enemies[i].y -= move_speed;
			if (enemies[i].y < enemies[i].target_y) enemies[i].y = enemies[i].target_y; // 목표 위치 도달 시 조정
		}

		// 목표 지점에 도달하면 새로운 목표 지점 설정
		if (enemies[i].x == enemies[i].target_x && enemies[i].y == enemies[i].target_y) {
			SetNewTarget(enemies[i]);
		}
	}

	for (int i = 0; i < FAST_ENEMY_COUNT; ++i) {
		float speed = 0.1;
		int adjust = 10;
		if (fast_enemies[i].x < fast_enemies[i].target_x) {
			fast_enemies[i].x = lerp(fast_enemies[i].x, fast_enemies[i].target_x, speed);
			if (fast_enemies[i].target_x - fast_enemies[i].x < adjust) fast_enemies[i].x = fast_enemies[i].target_x; // 목표 위치 도달 시 조정
		}
		else if (fast_enemies[i].x > fast_enemies[i].target_x) {
			fast_enemies[i].x = lerp(fast_enemies[i].x, fast_enemies[i].target_x, speed);
			if (fast_enemies[i].x - fast_enemies[i].target_x < adjust) fast_enemies[i].x = fast_enemies[i].target_x; // 목표 위치 도달 시 조정
		}

		if (fast_enemies[i].y < fast_enemies[i].target_y) {
			fast_enemies[i].y = lerp(fast_enemies[i].y, fast_enemies[i].target_y, speed);
			if (fast_enemies[i].target_y - fast_enemies[i].y < adjust) fast_enemies[i].y = fast_enemies[i].target_y; // 목표 위치 도달 시 조정
		}
		else if (fast_enemies[i].y > fast_enemies[i].target_y) {
			fast_enemies[i].y = lerp(fast_enemies[i].y, fast_enemies[i].target_y, speed);
			if (fast_enemies[i].y - fast_enemies[i].target_y < adjust) fast_enemies[i].y = fast_enemies[i].target_y; // 목표 위치 도달 시 조정
		}

		// 목표 지점에 도달하면 새로운 목표 지점 설정
		if (fast_enemies[i].x == fast_enemies[i].target_x && fast_enemies[i].y == fast_enemies[i].target_y) {
			SetNewTarget(fast_enemies[i]);
		}
	}

	Invalidate(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}


void CDlg_ending2::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	//미리 그려놓은 벽 호출하는 부분
	dc.BitBlt(0, 0, 1600, 800, &m_memDC, 0, 0, SRCCOPY);

	CString timeText;
	timeText.Format(_T("남은 시간: %d"), inGameTime);  // inGameTime 값을 문자열로 변환
	dc.TextOutW(800, 10, timeText);

	//dc.BitBlt(prevRect.left, prevRect.top, prevRect.Width(), prevRect.Height(), &m_memDC, prevRect.left, prevRect.top, SRCCOPY);
	// 얇고 긴 직사각형 여러 개 그리기
	CBrush brush(RGB(0, 128, 255));  // 파란색 브러시 생성 (직사각형 채우기용)
	CBrush* pOldBrush = dc.SelectObject(&brush);

	int size = 15;
	CBrush blackBrush(RGB(0, 0, 0));
	dc.SelectObject(&blackBrush);
	//적 그리기 
	for (int i = 0; i < ENEMY_COUNT; ++i) {
		dc.Ellipse(
			enemies[i].x - size, enemies[i].y - size,  // 좌측 상단 좌표 (적의 크기를 20x20으로 설정)
			enemies[i].x + size, enemies[i].y + size   // 우측 하단 좌표
		);
	}

	//초록 브러시 생성
	CBrush greenBrush(RGB(0, 255, 0));
	dc.SelectObject(&greenBrush);
	//적 그리기 
	for (int i = 0; i < FAST_ENEMY_COUNT; ++i) {
		dc.Ellipse(
			fast_enemies[i].x - size, fast_enemies[i].y - size,  // 좌측 상단 좌표 (적의 크기를 20x20으로 설정)
			fast_enemies[i].x + size, fast_enemies[i].y + size   // 우측 하단 좌표
		);
	}

	// 빨간색 브러시 생성
	CBrush yellowBrush(RGB(255, 255, 0));
	dc.SelectObject(&yellowBrush);
	dc.Ellipse(
		1475 - size, 725 - size,  // 좌측 상단 좌표 (적의 크기를 20x20으로 설정)
		1475 + size, 725 + size   // 우측 하단 좌표
	);
	dc.TextOutW(1445, 750, _T("경찰서"));

	// 빨간색 브러시 생성
	CBrush redBrush(RGB(255, 0, 0));
	dc.SelectObject(&redBrush);  // 빨간색 브러시 적용
	//플레이어 그리기 
	dc.Ellipse(
		playerPosition_x - size, playerPosition_y - size,  // 좌측 상단 좌표
		playerPosition_x + size, playerPosition_y + size   // 우측 하단 좌표
	);

	//기본 브러시로 다시 변환
	dc.SelectObject(pOldBrush);
}

float CDlg_ending2::lerp(float start, float end, float t) {
	return start + t * (end - start);
};

void CDlg_ending2::SetNewTarget(ENEMY& enemy)
{
	// 상하좌우로 이동 가능한 후보 지점 선택
	CPoint candidatePoints[4];
	int candidateCount = 0;

	// 상
	if (enemy.y > 100) {
		candidatePoints[candidateCount++] = CPoint(enemy.x, enemy.y - 125);
	}
	// 하
	if (enemy.y < 900) {
		candidatePoints[candidateCount++] = CPoint(enemy.x, enemy.y + 125);
	}
	// 좌
	if (enemy.x > 100) {
		candidatePoints[candidateCount++] = CPoint(enemy.x - 125, enemy.y);
	}
	// 우
	if (enemy.x < 1600) {
		candidatePoints[candidateCount++] = CPoint(enemy.x + 125, enemy.y);
	}

	// 후보 지점 중 랜덤으로 하나 선택
	if (candidateCount > 0) {
		CPoint newTarget = candidatePoints[rand() % candidateCount];
		enemy.target_x = newTarget.x;
		enemy.target_y = newTarget.y;
	}
}
