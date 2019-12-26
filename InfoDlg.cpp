// InfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FinalTestProject.h"
#include "InfoDlg.h"
#include "afxdialogex.h"


// CInfoDlg dialog

IMPLEMENT_DYNAMIC(CInfoDlg, CDialogEx)

CInfoDlg::CInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, m_strId2(_T(""))
	, m_strName2(_T(""))
	, m_strA2(_T(""))
	, m_strPw2(_T(""))
	, m_strEmail2(_T(""))
{

}

CInfoDlg::~CInfoDlg()
{
}

void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_INFO_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_INFO_ID, m_strId2);
	DDX_Text(pDX, IDC_EDIT_INFO_NAME, m_strName2);
	//  DDX_Text(pDX, IDC_EDIT_INFO_EMAIL, m_strEmail);
	DDX_Text(pDX, IDC_EDIT_INFO_A, m_strA2);
	DDX_Text(pDX, IDC_EDIT_INFO_PW, m_strPw2);
	DDX_Text(pDX, IDC_EDIT_INFO_EMAIL, m_strEmail2);
}


BEGIN_MESSAGE_MAP(CInfoDlg, CDialogEx)
END_MESSAGE_MAP()


// CInfoDlg message handlers
