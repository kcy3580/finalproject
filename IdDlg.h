#pragma once


// CIdDlg dialog

class CIdDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CIdDlg)

public:
	CIdDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CIdDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_nId;
	CString m_nPw;
};
