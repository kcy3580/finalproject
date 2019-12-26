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

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	TC_ITEM tabItem;
	LPSTR tabName[3] = { _T("�ѽ�"), _T("�߽�"), _T("�Ͻ�") }; //���� ������ 3���� �����ϰ� ������ �̸��� '�ѽ�', '�߽�', '�Ͻ�'���� �����Ѵ�.
	for (int nIndex = 0; nIndex < 3; nIndex++)
	{
		tabItem.mask = TCIF_TEXT;
		tabItem.pszText = tabName[nIndex];
		m_tab1.InsertItem(nIndex, &tabItem);
	}
	//ù �ʱ�ȭ�鿡 �ѽ� �ɼǸ� ���.
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

	//�ѽ� �޴�
	m_listKf.AddString(_T("�Ұ��"));
	m_listKf.AddString(_T("��ä"));
	m_listKf.AddString(_T("�����"));
	m_listKf.AddString(_T("��ġ�"));
	m_listKf.AddString(_T("�����"));
	m_listKf.AddString(_T("��â"));
	m_listKf.AddString(_T("���"));
	m_listKf.AddString(_T("���"));
	m_listKf.AddString(_T("�����ڹ�"));
	m_listKf.AddString(_T("�����"));
	m_listKf.AddString(_T("����"));
	m_listKf.AddString(_T("����"));
	m_listKf.AddString(_T("���κ��"));
	m_listKf.AddString(_T("��ȸ"));
	m_listKf.AddString(_T("��¡�������"));
	m_listKf.AddString(_T("��ġ��"));
	m_listKf.AddString(_T("������"));
	m_listKf.AddString(_T("�����"));

	//�߽� �޴�
	m_listCf.AddString(_T("¥���"));
	m_listCf.AddString(_T("«��"));
	m_listCf.AddString(_T("������"));
	m_listCf.AddString(_T("��¥��"));
	m_listCf.AddString(_T("�Ｑ¥��"));
	m_listCf.AddString(_T("���"));
	m_listCf.AddString(_T("��ä��"));
	m_listCf.AddString(_T("«�͹�"));
	m_listCf.AddString(_T("���꽽"));
	m_listCf.AddString(_T("������"));
	m_listCf.AddString(_T("�Ⱥ�ä"));
	m_listCf.AddString(_T("��ǳ��"));
	m_listCf.AddString(_T("������"));
	m_listCf.AddString(_T("������"));
	m_listCf.AddString(_T("��������"));
	m_listCf.AddString(_T("ũ������"));
	m_listCf.AddString(_T("������"));
	m_listCf.AddString(_T("ĥ������"));
	m_listCf.AddString(_T("���ĸ���ä"));
	m_listCf.AddString(_T("�׼��ػ�"));
	m_listCf.AddString(_T("������"));
	m_listCf.AddString(_T("������"));
	m_listCf.AddString(_T("���ڿϽ�"));
	m_listCf.AddString(_T("������ä"));

	//�Ͻ� �޴�
	m_listJf.AddString(_T("�������ʹ�"));
	m_listJf.AddString(_T("�����ʹ�"));
	m_listJf.AddString(_T("�ѿ��ʹ�"));
	m_listJf.AddString(_T("�����ʹ�"));
	m_listJf.AddString(_T("�Ե�"));
	m_listJf.AddString(_T("���ɵ�"));
	m_listJf.AddString(_T("����"));
	m_listJf.AddString(_T("������"));
	m_listJf.AddString(_T("����������"));
	m_listJf.AddString(_T("�ױⰡ����"));
	m_listJf.AddString(_T("�ͽ�������"));
	m_listJf.AddString(_T("�ٵ�"));
	m_listJf.AddString(_T("��������"));
	m_listJf.AddString(_T("����ư�"));
	m_listJf.AddString(_T("����쳪����"));
	m_listJf.AddString(_T("�쳪����"));
	m_listJf.AddString(_T("����"));
	m_listJf.AddString(_T("���� ���ڰ����"));
	m_listJf.AddString(_T("ġ�ƽ"));
	m_listJf.AddString(_T("�ֹ��Ķ���"));



	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CFoodDlg::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nSelect = m_tab1.GetCurSel();

	switch (nSelect)
	{
	case 0:
		//�ѽ��� ������ �� �ѽĿɼǸ� ���.
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

		//�߽��� ������ �� �߽ĿɼǸ� ���.
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

		//�Ͻ��� ������ �� �ϽĿɼǸ� ���.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ������ �޴��� ����Ʈ�ڽ��� �߰��Ѵ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ������ �޴��� ����Ʈ�ڽ��� �߰��Ѵ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ������ �޴��� ����Ʈ�ڽ��� �߰��Ѵ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ������ �޴��� ����Ʈ�ڽ����� �����Ѵ�.
	int A;
	A = m_listSm1.GetCurSel();
	if (A != LB_ERR)
	{

		m_listSm1.DeleteString(A);
	}
	else //������ �޴��� ���� �� ���� ������ ���� �޼��� �ڽ��� ��Ÿ����.
	{
		AfxMessageBox(_T("������ �޴��� �����ϼ���"));
	}
}


void CFoodDlg::OnClickedButtonD2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ������ �޴��� ����Ʈ�ڽ����� �����Ѵ�.
	int B;
	B = m_listSm2.GetCurSel();
	if (B != LB_ERR)
	{

		m_listSm2.DeleteString(B);
	}
	else //������ �޴��� ���� �� ���� ������ ���� �޼��� �ڽ��� ��Ÿ����.
	{
		AfxMessageBox(_T("������ �޴��� �����ϼ���"));
	}
}


void CFoodDlg::OnClickedButtonD3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ������ �޴��� ����Ʈ�ڽ����� �����Ѵ�.
	int C;
	C = m_listSm3.GetCurSel();
	if (C != LB_ERR)
	{

		m_listSm3.DeleteString(C);
	}
	else //������ �޴��� ���� �� ���� ������ ���� �޼��� �ڽ��� ��Ÿ����.
	{
		AfxMessageBox(_T("������ �޴��� �����ϼ���"));
	}
}
