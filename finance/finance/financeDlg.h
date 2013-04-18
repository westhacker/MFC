
// financeDlg.h : 头文件
//

#pragma once


// CfinanceDlg 对话框
class CfinanceDlg : public CDialogEx
{
// 构造
public:
	CfinanceDlg(CWnd* pParent = NULL);	// 标准构造函数
	void SaveData();
	void LoadData();
	BOOL m_bAutoSave;
	_variant_t vID,vmoney,vcost,vgain,vcostfor,vgainfor,vextra;
	BOOL m_bSuccess;
	int m_nCurrentSel;
	_RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CMSPRODlg)
	
// 对话框数据
	enum { IDD = IDD_FINANCE_DIALOG };

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
	CEdit m_money;
	afx_msg void OnBnClickedButton1();
	CEdit m_lx;
	CEdit m_reason;
	CEdit m_yue;
	CListCtrl m_list;
	CDateTimeCtrl m_time;
	afx_msg void OnBnClickedOk();
};
