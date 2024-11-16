// CDlg_secretRoom.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_secretRoom.h"


// CDlg_secretRoom 대화 상자

IMPLEMENT_DYNAMIC(CDlg_secretRoom, CDialogEx)

CDlg_secretRoom::CDlg_secretRoom(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_SECRETROOM, pParent)
{

}

CDlg_secretRoom::~CDlg_secretRoom()
{
}

void CDlg_secretRoom::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_secretRoom, CDialogEx)
END_MESSAGE_MAP()


// CDlg_secretRoom 메시지 처리기
