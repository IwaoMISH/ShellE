// ShellE.h : main header file for the SHELLE application
//

#if !defined(AFX_SHELLE_H__D17BBE32_41FD_437F_AC37_F3AE18649CDC__INCLUDED_)
#define AFX_SHELLE_H__D17BBE32_41FD_437F_AC37_F3AE18649CDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShellEApp:
// See ShellE.cpp for the implementation of this class
//

class CShellEApp : public CWinApp
{
public:
	CShellEApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShellEApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShellEApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHELLE_H__D17BBE32_41FD_437F_AC37_F3AE18649CDC__INCLUDED_)
