// FoodDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FinalTestProject.h"
#include "FoodDlg.h"
#include "afxdialogex.h"


// CFoodDlg dialog

IMPLEMENT_DYNAMIC(CFoodDlg, CDialogEx)

CFoodDlg::CFoodDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_FOOD, pParent)
{

}

CFoodDlg::~CFoodDlg()
{
}

void CFoodDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab1);
	DDX_Control(pDX, IDC_LIST_KF, m_listKf);
	DDX_Control(pDX, IDC_LIST_JF, m_listJf);
	DDX_Control(pDX, IDC_LIST_CF, m_listCf);
	DDX_Control(pDX, IDC_LIST_SM1, m_listSm1);
	DDX_Control(pDX, IDC_LIST_SM2, m_listSm2);
	DDX_Control(pDX, IDC_LIST_SM3, m_listSm3);
}


BEGIN_MESSAGE_MAP(CFoodDlg, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CFoodDlg::OnSelchangeTab1)
//	ON_BN_CLICKED(IDC_BUTTON_EXIT2, &CFoodDlg::OnClickedButtonExit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CFoodDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CFoodDlg::OnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CFoodDlg::OnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_D1, &CFoodDlg::OnClickedButtonD1)
	ON_BN_CLICKED(IDC_BUTTON_D2, &CFoodDlg::OnClickedButtonD2)
	ON_BN_CLICKED(IDC_BUTTON_D3, &CFoodDlg::OnClickedButtonD3)
END_MESSAGE_MAP()


// CFoodDlg message handlers


BOOL CFoodDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	TC_ITEM tabItem;
	LPSTR tabName[3] = { _T("한식"), _T("중식"), _T("일식") }; //탭의 갯수를 3개로 설정하고 각각의 이름을 '한식', '중식', '일식'으로 지정한다.
	for (int nIndex = 0; nIndex < 3; nIndex++)
	{
		tabItem.mask = TCIF_TEXT;
		tabItem.pszText = tabName[nIndex];
		m_tab1.InsertItem(nIndex, &tabItem);
	}
	//첫 초기화면에 한식 옵션만 뜬다.
	GetDlgItem(IDC_STATIC_KF)->ShowWindow(TRUE);
	GetDlgItem(IDC_LIST_KF)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_SM1)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON_D1)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	GetDlgItem(IDC_LIST_SM1)->ShowWindow(TRUE);

	GetDlgItem(IDC_STATIC_CF)->ShowWindow(FALSE);
	GetDlgItem(IDC_LIST_CF)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_SM2)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON_D2)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC2)->ShowWindow(FALSE);
	GetDlgItem(IDC_LIST_SM2)->ShowWindow(FALSE);

	GetDlgItem(IDC_STATIC_JF)->ShowWindow(FALSE);
	GetDlgItem(IDC_LIST_JF)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON5)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_SM3)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON_D3)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC3)->ShowWindow(FALSE);
	GetDlgItem(IDC_LIST_SM3)->ShowWindow(FALSE);

	//한식 메뉴
	m_listKf.AddString(_T("불고기"));
	m_listKf.AddString(_T("잡채"));
	m_listKf.AddString(_T("비빔밥"));
	m_listKf.AddString(_T("김치찌개"));
	m_listKf.AddString(_T("된장찌개"));
	m_listKf.AddString(_T("곱창"));
	m_listKf.AddString(_T("라면"));
	m_listKf.AddString(_T("백반"));
	m_listKf.AddString(_T("고등어자반"));
	m_listKf.AddString(_T("삼계탕"));
	m_listKf.AddString(_T("삼겹살"));
	m_listKf.AddString(_T("족발"));
	m_listKf.AddString(_T("순두부찌개"));
	m_listKf.AddString(_T("육회"));
	m_listKf.AddString(_T("오징어부추전"));
	m_listKf.AddString(_T("김치전"));
	m_listKf.AddString(_T("감자전"));
	m_listKf.AddString(_T("계란찜"));

	//중식 메뉴
	m_listCf.AddString(_T("짜장면"));
	m_listCf.AddString(_T("짬뽕"));
	m_listCf.AddString(_T("볶음밥"));
	m_listCf.AddString(_T("간짜장"));
	m_listCf.AddString(_T("삼선짜장"));
	m_listCf.AddString(_T("울면"));
	m_listCf.AddString(_T("잡채밥"));
	m_listCf.AddString(_T("짬뽕밥"));
	m_listCf.AddString(_T("유산슬"));
	m_listCf.AddString(_T("탕수육"));
	m_listCf.AddString(_T("팔보채"));
	m_listCf.AddString(_T("깐풍기"));
	m_listCf.AddString(_T("깐쇼새우"));
	m_listCf.AddString(_T("라조기"));
	m_listCf.AddString(_T("누룽지탕"));
	m_listCf.AddString(_T("크림새우"));
	m_listCf.AddString(_T("유린기"));
	m_listCf.AddString(_T("칠리새우"));
	m_listCf.AddString(_T("해파리냉채"));
	m_listCf.AddString(_T("죽순해삼"));
	m_listCf.AddString(_T("샥스핀"));
	m_listCf.AddString(_T("동파육"));
	m_listCf.AddString(_T("난자완스"));
	m_listCf.AddString(_T("고추잡채"));

	//일식 메뉴
	m_listJf.AddString(_T("생새우초밥"));
	m_listJf.AddString(_T("연어초밥"));
	m_listJf.AddString(_T("한우초밥"));
	m_listJf.AddString(_T("유부초밥"));
	m_listJf.AddString(_T("규동"));
	m_listJf.AddString(_T("사케동"));
	m_listJf.AddString(_T("에비동"));
	m_listJf.AddString(_T("가츠동"));
	m_listJf.AddString(_T("히레가츠동"));
	m_listJf.AddString(_T("네기가츠동"));
	m_listJf.AddString(_T("믹스가츠동"));
	m_listJf.AddString(_T("텐동"));
	m_listJf.AddString(_T("가츠나베"));
	m_listJf.AddString(_T("가라아게"));
	m_listJf.AddString(_T("에비우나가동"));
	m_listJf.AddString(_T("우나가동"));
	m_listJf.AddString(_T("낫또"));
	m_listJf.AddString(_T("수제 감자고로케"));
	m_listJf.AddString(_T("치즈스틱"));
	m_listJf.AddString(_T("애바후라이"));



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CFoodDlg::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nSelect = m_tab1.GetCurSel();

	switch (nSelect)
	{
	case 0:
		//한식을 눌렀을 때 한식옵션만 뜬다.
		GetDlgItem(IDC_STATIC_KF)->ShowWindow(TRUE);
		GetDlgItem(IDC_LIST_KF)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON1)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_SM1)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON_D1)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
		GetDlgItem(IDC_LIST_SM1)->ShowWindow(TRUE);

		GetDlgItem(IDC_STATIC_CF)->ShowWindow(FALSE);
		GetDlgItem(IDC_LIST_CF)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_SM2)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_D2)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(FALSE);
		GetDlgItem(IDC_LIST_SM2)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_JF)->ShowWindow(FALSE);
		GetDlgItem(IDC_LIST_JF)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON5)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_SM3)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_D3)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC3)->ShowWindow(FALSE);
		GetDlgItem(IDC_LIST_SM3)->ShowWindow(FALSE);
		break;

		//중식을 눌렀을 때 중식옵션만 뜬다.
	case 1:
		GetDlgItem(IDC_STATIC_KF)->ShowWindow(FALSE);
		GetDlgItem(IDC_LIST_KF)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON1)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_SM1)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_D1)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
		GetDlgItem(IDC_LIST_SM1)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_CF)->ShowWindow(TRUE);
		GetDlgItem(IDC_LIST_CF)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_SM2)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON_D2)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
		GetDlgItem(IDC_LIST_SM2)->ShowWindow(TRUE);

		GetDlgItem(IDC_STATIC_JF)->ShowWindow(FALSE);
		GetDlgItem(IDC_LIST_JF)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON5)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_SM3)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_D3)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC3)->ShowWindow(FALSE);
		GetDlgItem(IDC_LIST_SM3)->ShowWindow(FALSE);
		break;

		//일식을 눌렀을 때 일식옵션만 뜬다.
	case 2:
		GetDlgItem(IDC_STATIC_KF)->ShowWindow(FALSE);
		GetDlgItem(IDC_LIST_KF)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON1)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_SM1)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_D1)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
		GetDlgItem(IDC_LIST_SM1)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_CF)->ShowWindow(FALSE);
		GetDlgItem(IDC_LIST_CF)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_SM2)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_D2)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(FALSE);
		GetDlgItem(IDC_LIST_SM2)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_JF)->ShowWindow(TRUE);
		GetDlgItem(IDC_LIST_JF)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON5)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_SM3)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON_D3)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC3)->ShowWindow(TRUE);
		GetDlgItem(IDC_LIST_SM3)->ShowWindow(TRUE);
		break;
	}
	*pResult = 0;
}


void CFoodDlg::OnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 선택한 메뉴를 리스트박스에 추가한다.
	CString str;
	int a = m_listKf.GetCount();

	for (int i = a - 1; i >= 0; i--)
	{
		if (m_listKf.GetSel(i))
		{
			m_listKf.GetText(i, str);
			m_listSm1.AddString(str);
		}
	}
}


void CFoodDlg::OnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 선택한 메뉴를 리스트박스에 추가한다.
	CString str2;
	int b = m_listCf.GetCount();

	for (int i = b - 1; i >= 0; i--)
	{
		if (m_listCf.GetSel(i))
		{
			m_listCf.GetText(i, str2);
			m_listSm2.AddString(str2);
		}
	}
}


void CFoodDlg::OnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 선택한 메뉴를 리스트박스에 추가한다.
	CString str3;
	int c = m_listJf.GetCount();

	for (int i = c - 1; i >= 0; i--)
	{
		if (m_listJf.GetSel(i))
		{
			m_listJf.GetText(i, str3);
			m_listSm3.AddString(str3);
		}
	}
}


void CFoodDlg::OnClickedButtonD1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 선택한 메뉴를 리스트박스에서 삭제한다.
	int A;
	A = m_listSm1.GetCurSel();
	if (A != LB_ERR)
	{

		m_listSm1.DeleteString(A);
	}
	else //선택한 메뉴가 없을 시 밑의 내용이 적힌 메세지 박스가 나타난다.
	{
		AfxMessageBox(_T("삭제할 메뉴를 선택하세요"));
	}
}


void CFoodDlg::OnClickedButtonD2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 선택한 메뉴를 리스트박스에서 삭제한다.
	int B;
	B = m_listSm2.GetCurSel();
	if (B != LB_ERR)
	{

		m_listSm2.DeleteString(B);
	}
	else //선택한 메뉴가 없을 시 밑의 내용이 적힌 메세지 박스가 나타난다.
	{
		AfxMessageBox(_T("삭제할 메뉴를 선택하세요"));
	}
}


void CFoodDlg::OnClickedButtonD3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 선택한 메뉴를 리스트박스에서 삭제한다.
	int C;
	C = m_listSm3.GetCurSel();
	if (C != LB_ERR)
	{

		m_listSm3.DeleteString(C);
	}
	else //선택한 메뉴가 없을 시 밑의 내용이 적힌 메세지 박스가 나타난다.
	{
		AfxMessageBox(_T("삭제할 메뉴를 선택하세요"));
	}
}
