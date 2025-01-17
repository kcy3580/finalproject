
// FinalTestProjectDlg.h: 헤더 파일
//
#include "Start.h"
#include "MemDlg.h"

#pragma once


// CFinalTestProjectDlg 대화 상자
class CFinalTestProjectDlg : public CDialog
{
// 생성입니다.
public:
	CFinalTestProjectDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

	CStart m_StartDlg;
	CMemDlg m_MemDlg;

	CRect screen; //화면 크기 저장 변수
	int vsize, hsize; //폭과 높이 변수

	UINT htimer;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINALTESTPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStnClickedStaticDow();
	afx_msg void OnClickedButtonPm();
//	afx_msg void OnClickedButtonTp();
//	afx_msg void OnClickedButtonFt();
	afx_msg void OnClickedButtonStart();
//	afx_msg void OnClickedButtonId();
	afx_msg void OnClickedButtonMemin();
};
