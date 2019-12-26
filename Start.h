#pragma once

#include "FoodDlg.h"
#include "TourPlanDlg.h"
#include "IdDlg.h"
#include "InfoDlg.h"

// CStart dialog

class CStart : public CDialogEx
{
	DECLARE_DYNAMIC(CStart)

public:
	CStart(CWnd* pParent = NULL);   // standard constructor
	CIdDlg m_IdDlg;
	CFoodDlg m_FoodDlg;
	CTourPlanDlg m_TourPlanDlg;
	CInfoDlg m_InfoDlg;
	virtual ~CStart();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonFd();
	afx_msg void OnClickedButtonTp();
	afx_msg void OnClickedButtonId2();
	afx_msg void OnClickedButtonInfo();
};
