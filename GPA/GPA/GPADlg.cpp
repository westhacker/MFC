
// GPADlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GPA.h"
#include "GPADlg.h"
#include "afxdialogex.h"
#include "help.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGPADlg 对话框




CGPADlg::CGPADlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGPADlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	m_cj = 0.0;
	//  m_xf = 0;
	m_xf = 0;
}

void CGPADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_cj);
	DDV_MinMaxDouble(pDX, m_cj, 0, 100);
	//  DDX_Text(pDX, IDC_EDIT2, m_xf);
	//  DDV_MinMaxInt(pDX, m_xf, 0, 8);
	DDX_CBIndex(pDX, IDC_COMBO1, m_xf);
	DDV_MinMaxInt(pDX, m_xf, 0, 8);
	DDX_Control(pDX, IDC_COMBO2, m_lx);
	DDX_Control(pDX, IDC_EDIT2, m_hxjd);
	DDX_Control(pDX, IDC_EDIT3, m_zjd);
	DDX_Control(pDX, IDC_EDIT4, m_gpa);
	DDX_Control(pDX, IDC_EDIT5, m_pj);
	DDX_Control(pDX, IDC_EDIT1, m_cj0);
	DDX_Control(pDX, IDC_COMBO1, m_xf0);
}

BEGIN_MESSAGE_MAP(CGPADlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CGPADlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CGPADlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK2, &CGPADlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDC_BUTTON3, &CGPADlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CGPADlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDCANCEL2, &CGPADlg::OnBnClickedCancel2)
END_MESSAGE_MAP()


// CGPADlg 消息处理程序

BOOL CGPADlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGPADlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGPADlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGPADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

double hxcj=0,zcj=0,gpa=0,hxgpa=0,zjd,hxjd;
int zxf=0,hxxf=0;
void CGPADlg::OnBnClickedButton1()
{ CString szcj,szxf,szlx,szzcj,szzxf,szgpa,szhxgpa,szhxxf;

	m_lx.GetWindowTextW(szlx);
	m_cj0.GetWindowTextW(szcj);
	m_xf0.GetWindowTextW(szxf);

	double cj,jd;
	int xf;
	cj=_ttof(szcj);
	xf=_ttoi(szxf);
	
	if(cj>=95){jd=4.3;}
	else if(cj>=95){jd=4.3;}
	else if(cj>=90){jd=4;}
	else if(cj>=85){jd=3.7;}
	else if(cj>=80){jd=3.3;}
	else if(cj>=75){jd=3;}
	else if(cj>=70){jd=2.7;}
	else if(cj>=67){jd=2.3;}
	else if(cj>=65){jd=2;}
	else if(cj>=62){jd=1.7;}
	else if(cj>=60){jd=1;}
	else{jd=0;}

	zcj+=cj*xf;
	zxf+=xf;
	zjd+=jd*xf;
	if(szlx=="核心"){
		hxxf+=xf;
		hxcj+=cj*xf;
		hxgpa=hxcj/hxxf;
		hxjd+=jd*xf;
	}
	gpa=zcj/zxf;
	

	
	szzcj.Format(_T("%.2f"),zcj);
	szzxf.Format(_T("%d"), zxf); 
	szgpa.Format(_T("%.2f"),gpa);
	szhxgpa.Format(_T("%.2f"),hxgpa);
	szhxxf.Format(_T("%d"),hxxf);

	m_hxjd.SetWindowTextW(szzcj);
	m_gpa.SetWindowTextW(szzxf);
	m_zjd.SetWindowTextW(szhxgpa);
	m_pj.SetWindowTextW(szgpa);
	GetDlgItem(IDC_EDIT6)->SetWindowText(szhxxf);
	// TODO: 在此添加控件通知处理程序代码
}




void CGPADlg::OnBnClickedButton2()
{CString pj;
double pj0;
	m_zjd.GetWindowTextW(pj);
	pj0=_ttof(pj);
	if(pj0>=90){
		MessageBox(_T("EXCELENT!"),_T("Evaluation"),MB_OK); }
	else if(pj0>=80){
		MessageBox(_T("GOOD!"),_T("Evaluation"),MB_OK); }
	else if(pj0>=70){
		MessageBox(_T("NOT BAD!"),_T("Evaluation"),MB_OK); }
	else if(pj0>=60){
		MessageBox(_T("合格!"),_T("Evaluation"),MB_OK); }
	else {
		MessageBox(_T("不合格!"),_T("Evaluation"),MB_OK); }
	// TODO: 在此添加控件通知处理程序代码
}


void CGPADlg::OnBnClickedOk2()
{
	hxcj=0,zcj=0,gpa=0,hxgpa=0,zjd=0,hxjd=0;
zxf=0,hxxf=0;
m_hxjd.SetWindowText(NULL);
	m_gpa.SetWindowText(NULL);
	m_zjd.SetWindowText(NULL);
	m_pj.SetWindowText(NULL);
	GetDlgItem(IDC_COMBO1)->SetWindowText(NULL);
	GetDlgItem(IDC_EDIT1)->SetWindowText(NULL);
	GetDlgItem(IDC_EDIT6)->SetWindowText(NULL);
	GetDlgItem(IDC_COMBO2)->SetWindowText(NULL);

}


void CGPADlg::OnBnClickedButton3()
{double ajd;
ajd=zjd/zxf;
CString string;
string.Format(_T("%.2f"),ajd);
	MessageBox(string);

	// TODO: 在此添加控件通知处理程序代码
}


void CGPADlg::OnBnClickedButton4()
{double ajd;
ajd=hxjd/hxxf;
CString string;
string.Format(_T("%.2f"),ajd);
	MessageBox(string);
	// TODO: 在此添加控件通知处理程序代码
}


void CGPADlg::OnBnClickedCancel2()
{   help helpdlg;
helpdlg.DoModal();
	
	// TODO: 在此添加控件通知处理程序代码
}
