
// GPADlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GPA.h"
#include "GPADlg.h"
#include "afxdialogex.h"
#include "help.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CGPADlg �Ի���




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


// CGPADlg ��Ϣ�������

BOOL CGPADlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGPADlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	if(szlx=="����"){
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox(_T("�ϸ�!"),_T("Evaluation"),MB_OK); }
	else {
		MessageBox(_T("���ϸ�!"),_T("Evaluation"),MB_OK); }
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CGPADlg::OnBnClickedButton4()
{double ajd;
ajd=hxjd/hxxf;
CString string;
string.Format(_T("%.2f"),ajd);
	MessageBox(string);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CGPADlg::OnBnClickedCancel2()
{   help helpdlg;
helpdlg.DoModal();
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
