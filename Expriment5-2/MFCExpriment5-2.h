﻿
// MFCExpriment5-2.h: MFCExpriment5-2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CMFCExpriment52App:
// 有关此类的实现，请参阅 MFCExpriment5-2.cpp
//

class CMFCExpriment52App : public CWinApp
{
public:
	CMFCExpriment52App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExpriment52App theApp;
