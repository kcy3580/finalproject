#pragma once


// CMemDlg dialog

class CMemDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMemDlg)

public:
	CMemDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMemDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	void Init2();
	CString m_strName;
	CString m_strId;
	CString m_strPw;
	CString m_strEmail;
	CString m_strA;
	afx_msg void OnClickedButtonReset();
};
