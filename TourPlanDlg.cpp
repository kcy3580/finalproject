// TourPlanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FinalTestProject.h"
#include "TourPlanDlg.h"
#include "afxdialogex.h"


// CTourPlanDlg dialog

IMPLEMENT_DYNAMIC(CTourPlanDlg, CDialogEx)

CTourPlanDlg::CTourPlanDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_TOURPLAN, pParent)
	, m_strName(_T(""))
	, m_strCont(_T(""))
	, m_strTour(_T(""))
	, m_nSelected(0)
	, m_dtDate(COleDateTime::GetCurrentTime())
	, m_strOut(_T(""))
{

}

CTourPlanDlg::~CTourPlanDlg()
{
}

void CTourPlanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_CONT, m_strCont);
	DDX_Text(pDX, IDC_EDIT_TOUR, m_strTour);
	DDX_Control(pDX, IDC_RADIO_REST, m_rRest);
	//  DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE, m_dtDate);
	DDX_Text(pDX, IDC_EDIT_OUT, m_strOut);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}


BEGIN_MESSAGE_MAP(CTourPlanDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_INPUT, &CTourPlanDlg::OnClickedButtonInput)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CTourPlanDlg::OnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CTourPlanDlg::OnClickedButtonReset)
//	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CTourPlanDlg::OnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_OUT, &CTourPlanDlg::OnClickedButtonOut)
END_MESSAGE_MAP()



BOOL CTourPlanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	// 리스트 박스에 나타낼 항목을 각각 나타낸다.
	char *szText[5] = { "이름", "연락처", "여행지", "선호여행유형", "가고싶은 날짜" };
	int nWidth[5] = { 70, 100, 100, 80, 150 }; //각 항목의 크기지정

	LV_COLUMN iCol;
	iCol.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	iCol.fmt = LVCFMT_LEFT;
	m_list1.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	// 5개로 지정
	for (int i = 0; i < 5; i++)
	{
		iCol.pszText = szText[i];
		iCol.iSubItem = i;
		iCol.cx = nWidth[i];
		m_list1.InsertColumn(i, &iCol);
	}

	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CTourPlanDlg::Init() //초기화 함수
{
	UpdateData(TRUE);
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_EDIT_NAME);
	m_strName.Empty();
	m_strCont.Empty();
	m_strTour.Empty();
	m_strOut.Empty();
	
	m_rRest.SetCheck(BST_UNCHECKED);

	pEdit->SetFocus();
	UpdateData(FALSE);
}

void CTourPlanDlg::OnClickedButtonInput()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	char szText[100] = "";
	int nIndex = 0;
	UpdateData(TRUE);
	LVITEM iItem;
	iItem.mask = LVIF_TEXT;
	iItem.iItem = nIndex;

	// 첫 번째 항목에 변수 m_strName의 값이 들어간다.
	iItem.iSubItem = 0;
	sprintf_s(szText, "%s", m_strName);
	iItem.pszText = (LPSTR)szText;
	m_list1.InsertItem(&iItem);

	// 두 번째 항목에 변수 m_strCont의 값이 들어간다.
	iItem.iSubItem = 1;
	sprintf_s(szText, "%s", m_strCont);
	iItem.pszText = (LPSTR)szText;
	m_list1.SetItem(&iItem);

	// 세 번째 항목에 변수 m_strTour의 값이 들어간다.
	iItem.iSubItem = 2;
	sprintf_s(szText, "%s", m_strTour);
	iItem.pszText = (LPSTR)szText;
	m_list1.SetItem(&iItem);

	iItem.iSubItem = 3; //네 번째 항목에 휴양, 관광 중 선택한 항목의 값이 들어간다.

	if (m_rRest.GetCheck() == BST_CHECKED)
	{
		sprintf_s(szText, "%s", _T("휴양"));
	}

	else
	{
		sprintf_s(szText, "%s", _T("관광"));
	}

	iItem.pszText = (LPSTR)szText;
	m_list1.SetItem(&iItem);

	iItem.iSubItem = 4; //다섯 번째 항목에 변수 m_strOut의 값이 들어간다.
	sprintf_s(szText, "%s", m_strOut);
	iItem.pszText = (LPSTR)szText;
	m_list1.SetItem(&iItem);

	Init(); //입력할 시 함수 Init이 지정한 항목은 리셋된다.
	nIndex++;
	UpdateData(FALSE);
}


void CTourPlanDlg::OnClickedButtonDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 리스트 컨트롤에서 선택한 값을 삭제한다.
	for (int nItem = 0; nItem < m_list1.GetItemCount(); )
	{
		if (m_list1.GetItemState(nItem, LVIS_SELECTED) == LVIS_SELECTED)
			m_list1.DeleteItem(nItem);
		else
			++nItem;
	}
	UpdateData(FALSE);
}


void CTourPlanDlg::OnClickedButtonReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Init();
}

void CTourPlanDlg::OnClickedButtonOut()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// DateTimePicker의 값을 출력한다.
	UpdateData();
	CString str1;
	str1.Format(_T("%d 년 %d 월 %d 일"), m_dtDate.GetYear(), m_dtDate.GetMonth(), m_dtDate.GetDay());
	
	m_strOut = str1;
	UpdateData(false);
}
