#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "ATLComTime.h"


// CTourPlanDlg dialog

class CTourPlanDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTourPlanDlg)

public:
	CTourPlanDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTourPlanDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TOURPLAN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strCont;
	CString m_strTour;
	CButton m_rRest;
//	CListCtrl m_list1;
	int m_nSelected;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButtonInput();
	COleDateTime m_dtDate;
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnClickedButtonReset();
//	afx_msg void OnClickedButtonExit();
	void Init();
	afx_msg void OnClickedButtonOut();
	CString m_strOut;
	CListCtrl m_list1;
};
