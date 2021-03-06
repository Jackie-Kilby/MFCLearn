
// CheckButtonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CheckButton.h"
#include "CheckButtonDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCheckButtonDlg dialog



CCheckButtonDlg::CCheckButtonDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHECKBUTTON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCheckButtonDlg::InitAllCheckBoxStatus()
{
	//All forbidden
	m_check1.EnableWindow(FALSE);
	m_check2.EnableWindow(FALSE);
	m_check3.EnableWindow(FALSE);
	m_check4.EnableWindow(FALSE);
	m_check5.EnableWindow(FALSE);
	m_check6.EnableWindow(FALSE);

	//All unchosen
	m_check1.SetCheck(0);
	m_check2.SetCheck(0);
	m_check3.SetCheck(0);
	m_check4.SetCheck(0);
	m_check5.SetCheck(0);
	m_check6.SetCheck(0);
}

void CCheckButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK3, m_check3);
	DDX_Control(pDX, IDC_CHECK4, m_check4);
	DDX_Control(pDX, IDC_CHECK5, m_check5);
	DDX_Control(pDX, IDC_CHECK6, m_check6);
}

BEGIN_MESSAGE_MAP(CCheckButtonDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PORTAL_RADIO, &CCheckButtonDlg::OnBnClickedPortalRadio)
	ON_BN_CLICKED(IDC_FORUM_RADIO, &CCheckButtonDlg::OnBnClickedForumRadio)
	ON_BN_CLICKED(IDC_BLOG_RADIO, &CCheckButtonDlg::OnBnClickedBlogRadio)
	ON_BN_CLICKED(IDOK, &CCheckButtonDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CCheckButtonDlg message handlers

BOOL CCheckButtonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	CheckDlgButton(IDC_PORTAL_RADIO, 1);
	OnBnClickedPortalRadio();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCheckButtonDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCheckButtonDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCheckButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCheckButtonDlg::OnBnClickedPortalRadio()
{
	// TODO: Add your control notification handler code here
	InitAllCheckBoxStatus();
	m_check2.EnableWindow(TRUE);
	m_check5.EnableWindow(TRUE);
}


void CCheckButtonDlg::OnBnClickedForumRadio()
{
	// TODO: Add your control notification handler code here
	InitAllCheckBoxStatus();
	m_check3.EnableWindow(TRUE);
	m_check6.EnableWindow(TRUE);
}


void CCheckButtonDlg::OnBnClickedBlogRadio()
{
	// TODO: Add your control notification handler code here
	InitAllCheckBoxStatus();
	m_check1.EnableWindow(TRUE);
	m_check4.EnableWindow(TRUE);
}


void CCheckButtonDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	
	//To avoid exit the dialog, we need to cmt the OnOK() func.
	//CDialogEx::OnOK();

	CString strWebsiteSel;
	CString strCheckName;
	if (1 == m_check1.GetCheck())
	{		
		GetDlgItem(IDC_CHECK1)->GetWindowText(strCheckName);
		strWebsiteSel += strCheckName;		
	}
	if (1 == m_check2.GetCheck())
	{
		GetDlgItem(IDC_CHECK2)->GetWindowText(strCheckName);
		strWebsiteSel += strCheckName;
	}
	if (1 == m_check3.GetCheck())
	{
		GetDlgItem(IDC_CHECK3)->GetWindowText(strCheckName);
		strWebsiteSel += strCheckName;
	}
	if (1 == m_check4.GetCheck())
	{
		GetDlgItem(IDC_CHECK4)->GetWindowText(strCheckName);
		strWebsiteSel += strCheckName;
	}
	if (1 == m_check5.GetCheck())
	{
		GetDlgItem(IDC_CHECK5)->GetWindowText(strCheckName);
		strWebsiteSel += strCheckName;
	}
	if (1 == m_check6.GetCheck())
	{
		GetDlgItem(IDC_CHECK6)->GetWindowText(strCheckName);
		strWebsiteSel += strCheckName;
	}

	SetDlgItemText(IDC_WEBSITE_SEL_EDIT, strWebsiteSel);
}
