#pragma once


// CCDlg dialog

class CCDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCDlg)

public:
	CCDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CCDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_C_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
