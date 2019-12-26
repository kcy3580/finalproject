// MemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FinalTestProject.h"
#include "MemDlg.h"
#include "afxdialogex.h"


// CMemDlg dialog

IMPLEMENT_DYNAMIC(CMemDlg, CDialogEx)

CMemDlg::CMemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_strName(_T(""))
	, m_strId(_T(""))
	, m_strPw(_T(""))
	, m_strEmail(_T(""))
	, m_strA(_T(""))
{

}

CMemDlg::~CMemDlg()
{
}

void CMemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MEMIN_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_MEMIN_ID, m_strId);
	DDX_Text(pDX, IDC_EDIT_MEMIN_PW, m_strPw);
	DDX_Text(pDX, IDC_EDIT_MEMIN_EMAIL, m_strEmail);
	DDX_Text(pDX, IDC_EDIT_MEMIN_A, m_strA);
}


BEGIN_MESSAGE_MAP(CMemDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CMemDlg::OnClickedButtonReset)
END_MESSAGE_MAP()


// CMemDlg message handlers


void CMemDlg::Init2() //초기화 함수
{
	UpdateData(TRUE);
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_EDIT_MEMIN_NAME);
	m_strName.Empty();
	m_strId.Empty();
	m_strPw.Empty();
	m_strEmail.Empty();
	m_strA.Empty();


	pEdit->SetFocus();
	UpdateData(FALSE);
}


void CMemDlg::OnClickedButtonReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//초기화 함수 실행
	Init2();
}
