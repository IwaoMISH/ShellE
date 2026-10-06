// ShellED.cpp : implementation file
//

#include "stdafx.h"
#include "ShellE.h"
#include "ShellED.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShellEDlg dialog

CShellEDlg::CShellEDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShellEDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShellEDlg)
	m_StrOper = _T("");
	m_StrFile = _T("");
	m_StrPara = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShellEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShellEDlg)
	DDX_CBString(pDX, IDC_COMBO_OPERATION, m_StrOper);
	DDX_CBString(pDX, IDC_COMBO_FILE, m_StrFile);
	DDX_CBString(pDX, IDC_COMBO_PARAMETERS, m_StrPara);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShellEDlg, CDialog)
	//{{AFX_MSG_MAP(CShellEDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXECUTE, OnExecute)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShellEDlg message handlers

BOOL CShellEDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShellEDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShellEDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShellEDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

CString	Error_FormatMessage(const DWORD error)
{
	CString	message ;
	LPVOID	lpMessageBuffer = NULL ;
	if (::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,error,MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),
			(LPTSTR)&lpMessageBuffer,0,NULL)) {
		message = LPTSTR(lpMessageBuffer) ;
		::LocalFree(lpMessageBuffer) ;
		}
	return	message ;
	}

void CShellEDlg::OnExecute() 
{
	UpdateData(TRUE) ;
	HINSTANCE	hInst = ::ShellExecute(this->GetSafeHwnd(),m_StrOper,m_StrFile,m_StrPara,NULL,SW_SHOW) ;
	if (UINT64(hInst) > 32)	{	return ;	}
	DWORD	error = ::GetLastError() ;
	CString	str ;
	{
		str.Format(_T("%d\r\n%d"),DWORD(hInst),error) ;
		str += _T("    ") + ::Error_FormatMessage(error) ;
		str += _T("\r\n") + m_StrOper ;
		str += _T("\r\n") + m_StrFile ;
		str += _T("\r\n") + m_StrPara ;
		}
	AfxMessageBox(str) ;
	}
