// Start.cpp : implementation file
//

#include "stdafx.h"
#include "FinalTestProject.h"
#include "Start.h"
#include "afxdialogex.h"
#include "FinalTestProjectDlg.h"

// CStart dialog

IMPLEMENT_DYNAMIC(CStart, CDialogEx)

CStart::CStart(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CStart::~CStart()
{
}

void CStart::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStart, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_FD, &CStart::OnClickedButtonFd)
	ON_BN_CLICKED(IDC_BUTTON_TP, &CStart::OnClickedButtonTp)
	ON_BN_CLICKED(IDC_BUTTON_ID2, &CStart::OnClickedButtonId2)
	ON_BN_CLICKED(IDC_BUTTON_INFO, &CStart::OnClickedButtonInfo)
END_MESSAGE_MAP()


// CStart message handlers


void CStart::OnClickedButtonFd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//Start 클래스에 있는 m_IdDlg의 변수 m_nId와 m_nPw가 부모클래스인 CFinalTestProjectDlg의 m_MemDlg의 변수 m_strId와 m_strPw의 값과 같으면 m_FoodDlg의 창을 띄운다.
	if (m_IdDlg.m_nId == ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strId, m_IdDlg.m_nPw == ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strPw) 
	{
		m_FoodDlg.DoModal();
	}
	// 입력값이 없을 경우, "ID와 패스워드를 입력하세요." 문구의 메세지 박스를 띄운다.
	else if (m_IdDlg.m_nId == "", m_IdDlg.m_nPw == "")
	{
		AfxMessageBox(_T("ID와 패스워드를 입력하세요."));
	}
	// 값이 다를 경우, "ID와 패스워드가 틀립니다.\n다시 시도해 주십시오." 문구의 메세지 박스를 띄운다.
	else
	{
		AfxMessageBox(_T("ID와 패스워드가 틀립니다.\n다시 시도해 주십시오."));
	}
}


void CStart::OnClickedButtonTp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//Start 클래스에 있는 m_IdDlg의 변수 m_nId와 m_nPw가 부모클래스인 CFinalTestProjectDlg의 m_MemDlg의 변수 m_strId와 m_strPw의 값과 같으면 m_FoodDlg의 창을 띄운다.
	if (m_IdDlg.m_nId == ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strId, m_IdDlg.m_nPw == ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strPw)
	{
		m_TourPlanDlg.DoModal();
	}
	// 입력값이 없을 경우, "ID와 패스워드를 입력하세요." 문구의 메세지 박스를 띄운다.
	else if (m_IdDlg.m_nId == "", m_IdDlg.m_nPw == "")
	{
		AfxMessageBox(_T("ID와 패스워드를 입력하세요."));
	}
	// 값이 다를 경우, "ID와 패스워드가 틀립니다.\n다시 시도해 주십시오." 문구의 메세지 박스를 띄운다.
	else
	{
		AfxMessageBox(_T("ID와 패스워드가 틀립니다.\n다시 시도해 주십시오."));
	}
}


void CStart::OnClickedButtonId2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// m_IdDlg 다이얼로그를 띄운다.
	m_IdDlg.DoModal();
}


void CStart::OnClickedButtonInfo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//부모클래스 CFinalTestProjectDlg의 m_MemDlg 다이얼로그의 변수 m_str~들을 참조하여 자식클래스인 Start 클래스의 m_InfoDlg 다이얼로그의 변수 m_str~2들에 각각 대입한다.
	UpdateData(TRUE);
	m_InfoDlg.m_strName2 = ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strName;
	m_InfoDlg.m_strId2 = ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strId;
	m_InfoDlg.m_strPw2 = ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strPw;
	m_InfoDlg.m_strEmail2 = ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strEmail;
	m_InfoDlg.m_strA2 = ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strA;
	UpdateData(FALSE);
	m_InfoDlg.DoModal();
}
