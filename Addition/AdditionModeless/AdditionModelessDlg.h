
// AdditionModelessDlg.h: 头文件
//
#include "CTipDlg.h"

#pragma once


// CAdditionModelessDlg 对话框
class CAdditionModelessDlg : public CDialogEx
{
// 构造
public:
	CAdditionModelessDlg(CWnd* pParent = nullptr);	// 标准构造函数
	~CAdditionModelessDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDITIONMODELESS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double m_editSummand;
	double m_editAddend;
	double m_editSum;
	afx_msg void OnBnClickedAddButton();

private:
	CTipDlg *m_pTipDlg;
};
