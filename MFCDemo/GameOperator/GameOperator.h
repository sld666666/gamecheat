// GameOperator.h : GameOperator DLL ����ͷ�ļ�
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
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGameOperatorApp
// �йش���ʵ�ֵ���Ϣ������� GameOperator.cpp
//

_declspec(dllexport)void WINAPI installHook();
_declspec(dllexport)void WINAPI unInstallHook();

class CGameOperatorApp : public CWinApp
{
public:
	CGameOperatorApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
