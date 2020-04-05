// FKDlg.h : header file
//

#if !defined(AFX_FKDLG_H__97BAF2C1_F833_4DC2_8E97_B2CE87D629CB__INCLUDED_)
#define AFX_FKDLG_H__97BAF2C1_F833_4DC2_8E97_B2CE87D629CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFKDlg dialog

class CFKDlg : public CDialog
{
// Construction
public:
	CFKDlg(CWnd* pParent = NULL);	// standard constructor
    void INT_START();
    void DRAW();
	bool DOWN(int ,int);
	void XC();
	void DRAWNEXT();

	bool bStart;
// Dialog Data
	//{{AFX_DATA(CFKDlg)
	enum { IDD = IDD_FK_DIALOG };
	CStatic	m_next;
	CStatic	m_pic;
	int		m_speed;
	int		m_score;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFKDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFKDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg void OnPause();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FKDLG_H__97BAF2C1_F833_4DC2_8E97_B2CE87D629CB__INCLUDED_)
