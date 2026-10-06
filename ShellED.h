// ShellED.h : header file
//

#if !defined(AFX_SHELLED_H__2A4DE8EA_337A_4338_BEA6_DC4718015D38__INCLUDED_)
#define AFX_SHELLED_H__2A4DE8EA_337A_4338_BEA6_DC4718015D38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShellEDlg dialog

class CShellEDlg : public CDialog
{
// Construction
public:
	CShellEDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShellEDlg)
	enum { IDD = IDD_SHELLE_DIALOG };
	CString	m_StrOper;
	CString	m_StrFile;
	CString	m_StrPara;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShellEDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShellEDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExecute();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHELLED_H__2A4DE8EA_337A_4338_BEA6_DC4718015D38__INCLUDED_)
