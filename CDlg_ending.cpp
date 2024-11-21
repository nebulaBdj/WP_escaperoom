// CDlg_ending.cpp: 구현 파일
//

#include "pch.h"
#include "ROOMESCAPE.h"
#include "afxdialogex.h"
#include "CDlg_ending.h"


// CDlg_ending 대화 상자

IMPLEMENT_DYNAMIC(CDlg_ending, CDialogEx)

CDlg_ending::CDlg_ending(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ENDING, pParent)
{

}

CDlg_ending::~CDlg_ending()
{
}

void CDlg_ending::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_ending, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ENDING_NEXT, &CDlg_ending::OnClickedButtonEndingNext)
	ON_BN_CLICKED(IDC_BUTTON_ENDING_PREV, &CDlg_ending::OnClickedButtonEndingPrev)
	ON_WM_PAINT()
    ON_BN_CLICKED(IDC_BUTTON_ENDING_ACTION1, &CDlg_ending::OnClickedButtonEndingAction1)
    ON_BN_CLICKED(IDC_BUTTON_ENDING_ACTION2, &CDlg_ending::OnClickedButtonEndingAction2)
END_MESSAGE_MAP()


// CDlg_ending 메시지 처리기


BOOL CDlg_ending::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
    ending_page_index = 0;
	CRect rect(0, 0, 1200, 800);
	MoveWindow(&rect);
    GetDlgItem(IDC_BUTTON_ENDING_ACTION1)->ShowWindow(SW_HIDE);
	// Picture Control의 핸들 가져오기
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlg_ending::OnClickedButtonEndingNext()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (ending_page_index < 4) {
		ending_page_index ++;
        Invalidate();
	}
}


void CDlg_ending::OnClickedButtonEndingPrev()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (ending_page_index > 0) {
		ending_page_index--;
        Invalidate();
	}
}


void CDlg_ending::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
    CStatic* pPictureCtrl = (CStatic*)GetDlgItem(IDC_STATIC_MIRRORTEXTBOX);
    switch (ending_page_index) {
    case 0: {
        if (pPictureCtrl) {
            HBITMAP hOldBitmap = (HBITMAP)pPictureCtrl->GetBitmap();
            if (hOldBitmap) {
                ::DeleteObject(hOldBitmap);
            }
            // IDB_BITMAP_MIRRORTEXT11 비트맵 로드
            HBITMAP hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_MIRRORTEXT11));
            if (hBitmap) {
                // Picture Control에 비트맵 설정
                pPictureCtrl->SetBitmap(hBitmap);
            }
            GetDlgItem(IDC_BUTTON_ENDING_ACTION1)->ShowWindow(SW_HIDE);
            GetDlgItem(IDC_BUTTON_ENDING_ACTION2)->ShowWindow(SW_HIDE);
            GetDlgItem(IDC_BUTTON_ENDING_NEXT)->ShowWindow(SW_SHOW);
        }
        break;
    }
    case 1: {
        if (pPictureCtrl) {
            HBITMAP hOldBitmap = (HBITMAP)pPictureCtrl->GetBitmap();
            if (hOldBitmap) {
                ::DeleteObject(hOldBitmap);
            }
            // IDB_BITMAP_MIRRORTEXT22 비트맵 로드
            HBITMAP hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_MIRRORTEXT22));
            if (hBitmap) {
                // Picture Control에 비트맵 설정
                pPictureCtrl->SetBitmap(hBitmap);
            }
            GetDlgItem(IDC_BUTTON_ENDING_ACTION1)->ShowWindow(SW_HIDE);
            GetDlgItem(IDC_BUTTON_ENDING_ACTION2)->ShowWindow(SW_HIDE);
            GetDlgItem(IDC_BUTTON_ENDING_NEXT)->ShowWindow(SW_SHOW);
        }
        break;
    }
    case 2: {
        if (pPictureCtrl) {
            HBITMAP hOldBitmap = (HBITMAP)pPictureCtrl->GetBitmap();
            if (hOldBitmap) {
                ::DeleteObject(hOldBitmap);
            }
            // IDB_BITMAP_MIRRORTEXT22 비트맵 로드
            HBITMAP hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_MIRRORTEXT33));
            if (hBitmap) {
                // Picture Control에 비트맵 설정
                pPictureCtrl->SetBitmap(hBitmap);
            }
            GetDlgItem(IDC_BUTTON_ENDING_ACTION1)->ShowWindow(SW_HIDE);
            GetDlgItem(IDC_BUTTON_ENDING_ACTION2)->ShowWindow(SW_HIDE);
            GetDlgItem(IDC_BUTTON_ENDING_NEXT)->ShowWindow(SW_SHOW);
        }
        break;
    }
    case 3: {
        if (pPictureCtrl) {
            HBITMAP hOldBitmap = (HBITMAP)pPictureCtrl->GetBitmap();
            if (hOldBitmap) {
                ::DeleteObject(hOldBitmap);
            }
            // IDB_BITMAP_MIRRORTEXT22 비트맵 로드
            HBITMAP hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_MIRRORTEXT44));
            if (hBitmap) {
                // Picture Control에 비트맵 설정
                pPictureCtrl->SetBitmap(hBitmap);
            }
            //CButton* pButton_action1 = (CButton*)GetDlgItem(IDC_BUTTON_ACTION1);
            GetDlgItem(IDC_BUTTON_ENDING_ACTION1)->ShowWindow(SW_HIDE);
            GetDlgItem(IDC_BUTTON_ENDING_ACTION2)->ShowWindow(SW_HIDE);
            GetDlgItem(IDC_BUTTON_ENDING_NEXT)->ShowWindow(SW_SHOW);
        }
        break;
    }
    case 4: {
        if (pPictureCtrl) {
            HBITMAP hOldBitmap = (HBITMAP)pPictureCtrl->GetBitmap();
            if (hOldBitmap) {
                ::DeleteObject(hOldBitmap);
            }
            GetDlgItem(IDC_BUTTON_ENDING_ACTION1)->ShowWindow(SW_SHOW);
            GetDlgItem(IDC_BUTTON_ENDING_ACTION2)->ShowWindow(SW_SHOW);
            GetDlgItem(IDC_BUTTON_ENDING_NEXT)->ShowWindow(SW_HIDE);
        }
        break;
    }
    default:
        // 다른 ending_page_index 값에 대한 처리가 필요한 경우 추가
        break;
    }
}


void CDlg_ending::OnClickedButtonEndingAction1()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    PostMessage(WM_CLOSE);
    CDlg_ending2 dlg_ending2; 
    dlg_ending2.DoModal();
}


void CDlg_ending::OnClickedButtonEndingAction2()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
