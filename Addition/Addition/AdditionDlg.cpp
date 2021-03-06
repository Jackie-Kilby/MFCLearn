
// AdditionDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Addition.h"
#include "AdditionDlg.h"
#include "afxdialogex.h"

#include "CTipDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CAdditionDlg 对话框



CAdditionDlg::CAdditionDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADDITION_DIALOG, pParent)
	, m_editSummand(0)
	, m_editAddend(0)
	, m_editSum(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdditionDlg::DoDataExchange(CDataExchange* pDX)
{
	//处理MFC默认的数据交换
	CDialogEx::DoDataExchange(pDX);
	//处理控件IDC_xxxx_EDIT 和变量m_editxxxx之间的数据交换, 调用交换动作需要调用CDialogEx::UpdateData()函数
	DDX_Text(pDX, IDC_SUMMAND_EDIT, m_editSummand);
	DDX_Text(pDX, IDC_ADDEND_EDIT, m_editAddend);
	DDX_Text(pDX, IDC_SUM_EDIT, m_editSum);
}

BEGIN_MESSAGE_MAP(CAdditionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CAdditionDlg::OnBnClickedAddButton)
END_MESSAGE_MAP()


// CAdditionDlg 消息处理程序

BOOL CAdditionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetDlgItemText(IDC_SUMMAND_EDIT, L"");
	SetDlgItemText(IDC_ADDEND_EDIT, L"");
	SetDlgItemText(IDC_SUM_EDIT, L"0");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAdditionDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAdditionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAdditionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAdditionDlg::OnBnClickedAddButton()
{
	// TODO: 在此添加控件通知处理程序代码
	// 询问是否确定进行加法计算
	INT_PTR nRes;					//用于存放DoMal函数的返回值
#ifdef MODEL_MODE					//通过模态对话框方式
	CTipDlg tipDlg;					//构造对话框类CTipDlg的实例
	nRes = tipDlg.DoModal();		//弹出对话框
	if (nRes == IDCANCEL)
		return;
#else								//通过消息对话框方式
#ifdef AFX_STYLE
	nRes = AfxMessageBox(_T("您确定要进行加法计算吗？"), MB_OKCANCEL | MB_ICONQUESTION);
	if (IDCANCEL == nRes)
		return;
#else
	nRes = MessageBox(_T("您确定要进行加法计算吗？"), _T("加法计算器"), MB_OKCANCEL | MB_ICONQUESTION);
	if (IDCANCEL == nRes)
		return;
#endif
#endif

	//获取控件的值
	UpdateData(TRUE);
	//将控件的值进行计算
	m_editSum = m_editSummand + m_editAddend;
	//将计算的值返回控件
	UpdateData(FALSE);
}

void CDialog::OnOK()
{
	//回车计算
}
