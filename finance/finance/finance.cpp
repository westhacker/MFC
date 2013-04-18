
// finance.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "finance.h"
#include "financeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfinanceApp

BEGIN_MESSAGE_MAP(CfinanceApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CfinanceApp ����

CfinanceApp::CfinanceApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CfinanceApp ����

CfinanceApp theApp;


// CfinanceApp ��ʼ��

BOOL CfinanceApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	

	AfxOleInit();
	HRESULT hr;
	try
	{
		hr = m_pConnection.CreateInstance("ADODB.Connection");///����Connection����
		if(SUCCEEDED(hr))
		{
			hr = m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source= AdoData.mdb","","",adModeUnknown);///�������ݿ�
			//����һ���������ִ��е�Provider�����ACCESS2000�����ģ�����ACCESS97,
			//��Ҫ��Ϊ:Provider=Microsoft.Jet.OLEDB.3.51;  }
		}
	}
	catch(_com_error e)///��׽�쳣
	{
		CString errormessage;
		
		AfxMessageBox(errormessage);///��ʾ������Ϣ
		return FALSE;
	} 

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CfinanceDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

