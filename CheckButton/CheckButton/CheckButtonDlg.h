
// CheckButtonDlg.h : header file
//

#pragma once


// CCheckButtonDlg dialog
class CCheckButtonDlg : public CDialogEx
{
// Construction
public:
	CCheckButtonDlg(CWnd* pParent = nullptr);	// standard constructor

	void CCheckButtonDlg::InitAllCheckBoxStatus();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHECKBUTTON_DIALOG };
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
	CButton m_check1;
	CButton m_check2;
	CButton m_check3;
	CButton m_check4;
	CButton m_check5;
	CButton m_check6;
	afx_msg void OnBnClickedPortalRadio();
	afx_msg void OnBnClickedForumRadio();
	afx_msg void OnBnClickedBlogRadio();
	afx_msg void OnBnClickedOk();
};
