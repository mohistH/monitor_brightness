
// ctrl_monitor_brightness.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cctrl_monitor_brightnessApp:
// �йش����ʵ�֣������ ctrl_monitor_brightness.cpp
//

class Cctrl_monitor_brightnessApp : public CWinApp
{
public:
	Cctrl_monitor_brightnessApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cctrl_monitor_brightnessApp theApp;