// GameOperator.h : GameOperator DLL 的主头文件
//
/** 
* @file         GameOperator.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2012-12-19
*/
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CGameOperatorApp
// 有关此类实现的信息，请参阅 GameOperator.cpp
//

_declspec(dllexport)void WINAPI installHook();
_declspec(dllexport)void WINAPI unInstallHook();

class CGameOperatorApp : public CWinApp
{
public:
	CGameOperatorApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
