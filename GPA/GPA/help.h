#pragma once


// help �Ի���

class help : public CDialog
{
	DECLARE_DYNAMIC(help)

public:
	help(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~help();

// �Ի�������
	enum { IDD = IDD_HELP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
