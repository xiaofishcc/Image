
// demoduoxianc.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CdemoduoxiancApp: 
// �йش����ʵ�֣������ demoduoxianc.cpp
//

class CdemoduoxiancApp : public CWinApp
{
public:
	CdemoduoxiancApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CdemoduoxiancApp theApp;