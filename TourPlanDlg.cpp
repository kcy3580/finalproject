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
	
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	// ����Ʈ �ڽ��� ��Ÿ�� �׸��� ���� ��Ÿ����.
	char *szText[5] = { "�̸�", "����ó", "������", "��ȣ��������", "������� ��¥" };
	int nWidth[5] = { 70, 100, 100, 80, 150 }; //�� �׸��� ũ������

	LV_COLUMN iCol;
	iCol.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	iCol.fmt = LVCFMT_LEFT;
	m_list1.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	// 5���� ����
	for (int i = 0; i < 5; i++)
	{
		iCol.pszText = szText[i];
		iCol.iSubItem = i;
		iCol.cx = nWidth[i];
		m_list1.InsertColumn(i, &iCol);
	}

	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CTourPlanDlg::Init() //�ʱ�ȭ �Լ�
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	char szText[100] = "";
	int nIndex = 0;
	UpdateData(TRUE);
	LVITEM iItem;
	iItem.mask = LVIF_TEXT;
	iItem.iItem = nIndex;

	// ù ��° �׸� ���� m_strName�� ���� ����.
	iItem.iSubItem = 0;
	sprintf_s(szText, "%s", m_strName);
	iItem.pszText = (LPSTR)szText;
	m_list1.InsertItem(&iItem);

	// �� ��° �׸� ���� m_strCont�� ���� ����.
	iItem.iSubItem = 1;
	sprintf_s(szText, "%s", m_strCont);
	iItem.pszText = (LPSTR)szText;
	m_list1.SetItem(&iItem);

	// �� ��° �׸� ���� m_strTour�� ���� ����.
	iItem.iSubItem = 2;
	sprintf_s(szText, "%s", m_strTour);
	iItem.pszText = (LPSTR)szText;
	m_list1.SetItem(&iItem);

	iItem.iSubItem = 3; //�� ��° �׸� �޾�, ���� �� ������ �׸��� ���� ����.

	if (m_rRest.GetCheck() == BST_CHECKED)
	{
		sprintf_s(szText, "%s", _T("�޾�"));
	}

	else
	{
		sprintf_s(szText, "%s", _T("����"));
	}

	iItem.pszText = (LPSTR)szText;
	m_list1.SetItem(&iItem);

	iItem.iSubItem = 4; //�ټ� ��° �׸� ���� m_strOut�� ���� ����.
	sprintf_s(szText, "%s", m_strOut);
	iItem.pszText = (LPSTR)szText;
	m_list1.SetItem(&iItem);

	Init(); //�Է��� �� �Լ� Init�� ������ �׸��� ���µȴ�.
	nIndex++;
	UpdateData(FALSE);
}


void CTourPlanDlg::OnClickedButtonDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ����Ʈ ��Ʈ�ѿ��� ������ ���� �����Ѵ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Init();
}

void CTourPlanDlg::OnClickedButtonOut()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// DateTimePicker�� ���� ����Ѵ�.
	UpdateData();
	CString str1;
	str1.Format(_T("%d �� %d �� %d ��"), m_dtDate.GetYear(), m_dtDate.GetMonth(), m_dtDate.GetDay());
	
	m_strOut = str1;
	UpdateData(false);
}
