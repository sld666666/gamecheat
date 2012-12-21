
// MFCDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCDemo.h"
#include "MFCDemoDlg.h"
#include "utils.h"
#include "GameOperator.h"
#include "log.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDemoDlg 对话框




CMFCDemoDlg::CMFCDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCDemoDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDB_TEST, &CMFCDemoDlg::OnBnClickedTest)
	ON_BN_CLICKED(IDB_INHOOK, &CMFCDemoDlg::OnBnClickedInhook)
	ON_BN_CLICKED(IDB_UNHOOK, &CMFCDemoDlg::OnBnClickedUnhook)
END_MESSAGE_MAP()


// CMFCDemoDlg 消息处理程序

BOOL CMFCDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
 	
	ProcessMsgManager::removeMsgQueue(INTERPRCESS_MESSAGE_QUEUE_NAME_IN
		, INTERPRCESS_MESSAGE_QUEUE_NAME_OUT);
 	processMsgManager_ = shared_ptr<ProcessMsgManager>(new ProcessMsgManager(INTERPRCESS_MESSAGE_QUEUE_NAME_IN,
		INTERPRCESS_MESSAGE_QUEUE_NAME_OUT));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCDemoDlg::OnBnClickedTest()
{
	processMsgManager_->sendMsgQueue();
}

void CMFCDemoDlg::OnBnClickedInhook()
{
	installHook();
 }

void CMFCDemoDlg::OnBnClickedUnhook()
{
	
	unInstallHook();
}
