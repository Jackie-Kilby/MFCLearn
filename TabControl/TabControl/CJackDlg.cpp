// CJackDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TabControl.h"
#include "CJackDlg.h"
#include "afxdialogex.h"


// CJackDlg dialog

IMPLEMENT_DYNAMIC(CJackDlg, CDialogEx)

CJackDlg::CJackDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_JACK_DIALOG, pParent)
{

}

CJackDlg::~CJackDlg()
{
}

void CJackDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CJackDlg, CDialogEx)
END_MESSAGE_MAP()


// CJackDlg message handlers
