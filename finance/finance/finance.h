
// finance.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "DEBUG\msado15.tlh"

// CfinanceApp:
// �йش����ʵ�֣������ finance.cpp
//

class CfinanceApp : public CWinApp
{
public:
	_ConnectionPtr m_pConnection;
	CfinanceApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CfinanceApp theApp;