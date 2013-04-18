
// GPADlg.h : 头文件
//

#pragma once


// CGPADlg 对话框
class CGPADlg : public CDialogEx
{
// 构造
public:
	CGPADlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GPA_DIALOG };

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
	double m_cj;
//	int m_xf;
	int m_xf;
	CComboBox m_lx;
	CEdit m_hxjd;
	CEdit m_zjd;
	CEdit m_gpa;
	CEdit m_pj;
	afx_msg void OnBnClickedButton1();
	CEdit m_cj0;
	CComboBox m_xf0;
	afx_msg void OnBnClickedCommand1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedCancel2();
};
