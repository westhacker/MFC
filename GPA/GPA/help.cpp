// help.cpp : 实现文件
//

#include "stdafx.h"
#include "GPA.h"
#include "help.h"
#include "afxdialogex.h"


// help 对话框

IMPLEMENT_DYNAMIC(help, CDialog)

help::help(CWnd* pParent /*=NULL*/)
	: CDialog(help::IDD, pParent)
{

}

help::~help()
{
}

void help::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(help, CDialog)
END_MESSAGE_MAP()


// help 消息处理程序
