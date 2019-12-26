// IdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FinalTestProject.h"
#include "IdDlg.h"
#include "afxdialogex.h"


// CIdDlg dialog

IMPLEMENT_DYNAMIC(CIdDlg, CDialogEx)

CIdDlg::CIdDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_nId(_T(""))
	, m_nPw(_T(""))
{

}

CIdDlg::~CIdDlg()
{
}

void CIdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_nId);
	DDX_Text(pDX, IDC_EDIT_PW, m_nPw);
}


BEGIN_MESSAGE_MAP(CIdDlg, CDialogEx)
//	ON_BN_CLICKED(IDC_BUTTON_TOSS, &CIdDlg::OnClickedButtonToss)
END_MESSAGE_MAP()

