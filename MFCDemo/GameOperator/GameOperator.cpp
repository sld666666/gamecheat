// GameOperator.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "GameOperator.h"
#include "GameManager.h"
#include "XmlConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CGameOperatorApp, CWinApp)
END_MESSAGE_MAP()


// CGameOperatorApp ����

CGameOperatorApp::CGameOperatorApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CGameOperatorApp ����

CGameOperatorApp theApp;
HHOOK gHook;
shared_ptr<GameManager> gGameManager;


// CGameOperatorApp ��ʼ��

BOOL CGameOperatorApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0); 
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

LRESULT CALLBACK LauncherHook(int nCode,WPARAM wParam,LPARAM lParam)
{
	if (!gGameManager.get())
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());

		TRACE("hook");
		gGameManager = shared_ptr<GameManager>(new GameManager());

		AfxMessageBox(_T("hook secuss"));
	}

	LRESULT Result=CallNextHookEx(gHook,nCode,wParam,lParam);

	return Result;
}

_declspec(dllexport) void WINAPI installHook()
{
// 	gGameManager = shared_ptr<GameManager>(new GameManager());
// 	return;
	XmlConfig::instance().init();
	wstring targetCaption = s2ws(XmlConfig::instance().getValue("game.caption"));

	HWND targetHandle = FindWindow(NULL,targetCaption.c_str());
	if (!targetHandle)
	{
		AfxMessageBox(_T("can not find the game window"));
		return;
	}

	DWORD processId = ::GetWindowThreadProcessId(targetHandle, NULL);

	gHook=(HHOOK)SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)LauncherHook,
		theApp.m_hInstance,processId);

}

_declspec(dllexport) void WINAPI unInstallHook()
{
	AfxMessageBox(_T("un hook"));
	::UnhookWindowsHookEx(gHook);
}
