// GPA.cpp : 实现文件
//

#include "stdafx.h"
#include "SJTUGPA.h"
#include "GPA.h"
#include "afxdialogex.h"
#include "CApplication.h"  
#include "CRange.h"  
#include "CRanges.h"
#include "CWorkbook.h"  
#include "CWorkbooks.h"  
#include "CWorksheet.h"  
#include "CWorksheets.h"

// GPA 对话框

IMPLEMENT_DYNAMIC(GPA, CDialog)

GPA::GPA(CWnd* pParent /*=NULL*/)
	: CDialog(GPA::IDD, pParent)
{
	
}


GPA::~GPA()
{
	 // TODO: 在此添加控件通知处理程序代码  
  
}

void GPA::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
}


BEGIN_MESSAGE_MAP(GPA, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON2, &GPA::OnBnClickedButton2)
END_MESSAGE_MAP()


// GPA 消息处理程序


void GPA::OnPaint()
{ CPaintDC   dc(this);   

          CRect   rect;   

          GetClientRect(&rect);   

          CDC   dcMem;   

          dcMem.CreateCompatibleDC(&dc);   

          CBitmap   bmpBackground;   

          bmpBackground.LoadBitmap(IDB_BITMAP3);                  

          BITMAP   bitmap;   

          bmpBackground.GetBitmap(&bitmap);   

          CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   

          dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   

         bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);  
		  
}


HBRUSH GPA::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	 if( nCtlColor == CTLCOLOR_STATIC)     
 {   
  pDC->SetBkMode(TRANSPARENT);   //设置背景透明
  pDC->SetTextColor(RGB(240,240,240));
  return   HBRUSH(GetStockObject(HOLLOW_BRUSH));   
  
 }   
	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
CString GetModulePath(){
    TCHAR lpszFileName[MAX_PATH+1];
    ::GetModuleFileName(NULL,lpszFileName,MAX_PATH+1);
    CString sModulePath = lpszFileName;
    int index = sModulePath.ReverseFind('\\');
    sModulePath = sModulePath.Left(index+1);
    long len = sModulePath.GetLength();
    #ifdef _DEBUG
        CString dbg = sModulePath.Right(6);
        dbg.MakeUpper();
        if(dbg == "DEBUG\\")
            sModulePath = sModulePath.Left(len-6);
    #else
        CString dbg = sModulePath.Right(8);
        dbg.MakeUpper();
        if(dbg == "RELEASE\\")
            sModulePath = sModulePath.Left(len-8);
    #endif
    return sModulePath;
	}


void GPA::OnBnClickedButton2()
{  CApplication app;  
    CWorkbooks books;  
    CWorkbook book;  
    CWorksheets sheets;  
    CWorksheet sheet;  
    CRange range;  
	CRanges ranges;
    CRange iCell;  
	CString strbook,szzxf,szzcj,szgpa,szjd,szzc,gpa7;

	

	strbook=GetModulePath()+_T("SJTUGPA.xls");
    LPDISPATCH lpDisp;  
    COleVariant vResult;  
    COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);  
    if(!app.CreateDispatch(L"Excel.Application"))  
    {  
    AfxMessageBox(L"无法启动Excel服务器!");  
    return;  
    }  
    books.AttachDispatch(app.get_Workbooks());  
    lpDisp = books.Open(strbook,covOptional, covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional,covOptional);  
      
    //得到Workbook  
    book.AttachDispatch(lpDisp);  
    //得到Worksheets  
    sheets.AttachDispatch(book.get_Worksheets());  
   
    //得到当前活跃sheet  
    //如果有单元格正处于编辑状态中，此操作不能返回，会一直等待  
    lpDisp=book.get_ActiveSheet();  
    sheet.AttachDispatch(lpDisp);  
    //读取第一个单元格的值  
	double zcj=0,zjd=0,hxjd=0,gpa=0,hxgpa=0,hxcj=0,hxxf=0;
	double cj[999],xf[999],jd[999];
	int i=2,zxf=0,zc=0;
	do{
    range.AttachDispatch(sheet.get_Cells());  
    range.AttachDispatch(range.get_Item (COleVariant((long)i),COleVariant((long)3)).pdispVal );  
    /*COleVariant*/ vResult =range.get_Value2();  
    CString str;  
    if(vResult.vt == VT_BSTR) //字符串  
    {  
    str=vResult.bstrVal;  
    }  
    else if (vResult.vt==VT_R8) //8字节的数字  
    {  
    str.Format(L"%f",vResult.dblVal);  
    }  
	xf[i-2]=_ttof(str);
	zxf+=_ttof(str);
	zc++;
	i++;
	}while(vResult.vt!=VT_EMPTY);
	zc=i-3;
	int j=2;
	do{
    range.AttachDispatch(sheet.get_Cells());  
    range.AttachDispatch(range.get_Item (COleVariant((long)j),COleVariant((long)4)).pdispVal );  
    /*COleVariant*/ vResult =range.get_Value2();  
    CString str;  
    if(vResult.vt == VT_BSTR) //字符串  
    {  
    str=vResult.bstrVal;  
    }  
    else if (vResult.vt==VT_R8) //8字节的数字  
    {  
    str.Format(L"%f",vResult.dblVal);  
    }  
	cj[j-2]=_ttof(str);
	if(cj[j-2]>=95){jd[j-2]=4.3;}
	else if(cj[j-2]>=95){jd[j-2]=4.3;}
	else if(cj[j-2]>=90){jd[j-2]=4;}
	else if(cj[j-2]>=85){jd[j-2]=3.7;}
	else if(cj[j-2]>=80){jd[j-2]=3.3;}
	else if(cj[j-2]>=75){jd[j-2]=3;}
	else if(cj[j-2]>=70){jd[j-2]=2.7;}
	else if(cj[j-2]>=67){jd[j-2]=2.3;}
	else if(cj[j-2]>=65){jd[j-2]=2;}
	else if(cj[j-2]>=62){jd[j-2]=1.7;}
	else if(cj[j-2]>=60){jd[j-2]=1;}
	else{jd[j-2]=0;}
	zcj+=cj[j-2]*xf[j-2];
	gpa+=jd[j-2]*xf[j-2]/zxf;
	j++;
	}while(vResult.vt!=VT_EMPTY);

	zjd=zcj/zxf;

	
    /*else if(vResult.vt==VT_DATE) //时间格式 
    { 
    SYSTEMTIME st; 
    VariantTimeToSystemTime(&vResult.date, &st); 
    } 
    else if(vResult.vt==VT_EMPTY) //单元格空的 
    { 
    str=""; 
    }*/    
	 
	szzcj.Format(L"%f",zcj); 
	szjd.Format(L"%f",zjd); 
	szgpa.Format(L"%f",gpa); 
	szzc.Format(_T("%d"),zc);
	szzxf.Format(_T("%d"), zxf); 
	gpa7.Format(L"%f",zjd*0.7);
    books.Close();   
    app.Quit();             // 退出  
    //释放对象    
    range.ReleaseDispatch();  
    sheet.ReleaseDispatch();  
    sheets.ReleaseDispatch();  
    book.ReleaseDispatch();  
    books.ReleaseDispatch();  
    app.ReleaseDispatch();  
	GetDlgItem(IDC_EDIT2)->SetWindowText(szzc); 
	GetDlgItem(IDC_EDIT3)->SetWindowText(szzxf); 
	GetDlgItem(IDC_EDIT4)->SetWindowText(szzcj); 
	GetDlgItem(IDC_EDIT5)->SetWindowText(szjd); 
	GetDlgItem(IDC_EDIT6)->SetWindowText(gpa7); 
	GetDlgItem(IDC_EDIT7)->SetWindowText(szgpa); 
	// TODO: 在此添加控件通知处理程序代码
}
