
// MFCApplication1jiyuduihuakuang.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCApplication1jiyuduihuakuangApp: 
// �йش����ʵ�֣������ MFCApplication1jiyuduihuakuang.cpp
//

class CMFCApplication1jiyuduihuakuangApp : public CWinApp
{
public:
	CMFCApplication1jiyuduihuakuangApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication1jiyuduihuakuangApp theApp;//��Ŀ���ɺ󣬶�������һ������CMFCApplication1jiyuduihuakuangApp���theApp����