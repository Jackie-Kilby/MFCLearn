#pragma once


// CJackDlg dialog

class CJackDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CJackDlg)

public:
	CJackDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CJackDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_JACK_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
