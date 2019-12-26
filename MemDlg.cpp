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


void CMemDlg::Init2() //�ʱ�ȭ �Լ�
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//�ʱ�ȭ �Լ� ����
	Init2();
}
