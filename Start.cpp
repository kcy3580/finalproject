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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//Start Ŭ������ �ִ� m_IdDlg�� ���� m_nId�� m_nPw�� �θ�Ŭ������ CFinalTestProjectDlg�� m_MemDlg�� ���� m_strId�� m_strPw�� ���� ������ m_FoodDlg�� â�� ����.
	if (m_IdDlg.m_nId == ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strId, m_IdDlg.m_nPw == ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strPw) 
	{
		m_FoodDlg.DoModal();
	}
	// �Է°��� ���� ���, "ID�� �н����带 �Է��ϼ���." ������ �޼��� �ڽ��� ����.
	else if (m_IdDlg.m_nId == "", m_IdDlg.m_nPw == "")
	{
		AfxMessageBox(_T("ID�� �н����带 �Է��ϼ���."));
	}
	// ���� �ٸ� ���, "ID�� �н����尡 Ʋ���ϴ�.\n�ٽ� �õ��� �ֽʽÿ�." ������ �޼��� �ڽ��� ����.
	else
	{
		AfxMessageBox(_T("ID�� �н����尡 Ʋ���ϴ�.\n�ٽ� �õ��� �ֽʽÿ�."));
	}
}


void CStart::OnClickedButtonTp()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//Start Ŭ������ �ִ� m_IdDlg�� ���� m_nId�� m_nPw�� �θ�Ŭ������ CFinalTestProjectDlg�� m_MemDlg�� ���� m_strId�� m_strPw�� ���� ������ m_FoodDlg�� â�� ����.
	if (m_IdDlg.m_nId == ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strId, m_IdDlg.m_nPw == ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strPw)
	{
		m_TourPlanDlg.DoModal();
	}
	// �Է°��� ���� ���, "ID�� �н����带 �Է��ϼ���." ������ �޼��� �ڽ��� ����.
	else if (m_IdDlg.m_nId == "", m_IdDlg.m_nPw == "")
	{
		AfxMessageBox(_T("ID�� �н����带 �Է��ϼ���."));
	}
	// ���� �ٸ� ���, "ID�� �н����尡 Ʋ���ϴ�.\n�ٽ� �õ��� �ֽʽÿ�." ������ �޼��� �ڽ��� ����.
	else
	{
		AfxMessageBox(_T("ID�� �н����尡 Ʋ���ϴ�.\n�ٽ� �õ��� �ֽʽÿ�."));
	}
}


void CStart::OnClickedButtonId2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// m_IdDlg ���̾�α׸� ����.
	m_IdDlg.DoModal();
}


void CStart::OnClickedButtonInfo()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//�θ�Ŭ���� CFinalTestProjectDlg�� m_MemDlg ���̾�α��� ���� m_str~���� �����Ͽ� �ڽ�Ŭ������ Start Ŭ������ m_InfoDlg ���̾�α��� ���� m_str~2�鿡 ���� �����Ѵ�.
	UpdateData(TRUE);
	m_InfoDlg.m_strName2 = ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strName;
	m_InfoDlg.m_strId2 = ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strId;
	m_InfoDlg.m_strPw2 = ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strPw;
	m_InfoDlg.m_strEmail2 = ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strEmail;
	m_InfoDlg.m_strA2 = ((CFinalTestProjectDlg *)GetParent())->m_MemDlg.m_strA;
	UpdateData(FALSE);
	m_InfoDlg.DoModal();
}
