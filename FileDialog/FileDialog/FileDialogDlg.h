
// FileDialogDlg.h : header file
//

#pragma once


// CFileDialogDlg dialog
class CFileDialogDlg : public CDialogEx
{
// Construction
public:
	CFileDialogDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILEDIALOG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpenButton();
	afx_msg void OnBnClickedSaveButton();
};
