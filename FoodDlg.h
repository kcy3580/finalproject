#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CFoodDlg dialog

class CFoodDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFoodDlg)

public:
	CFoodDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFoodDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FOOD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab1;
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	CListBox m_listKf;
	CListBox m_listJf;
	CListBox m_listCf;
	CListBox m_listSm1;
	CListBox m_listSm2;
	CListBox m_listSm3;
//	afx_msg void OnClickedButtonExit2();
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton3();
	afx_msg void OnClickedButton5();
	afx_msg void OnClickedButtonD1();
	afx_msg void OnClickedButtonD2();
	afx_msg void OnClickedButtonD3();
};
