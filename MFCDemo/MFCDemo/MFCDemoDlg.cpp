
// MFCDemoDlg.cpp : ʵ���ļ�
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


// CMFCDemoDlg �Ի���




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


// CMFCDemoDlg ��Ϣ�������

BOOL CMFCDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
 	
	ProcessMsgManager::removeMsgQueue(INTERPRCESS_MESSAGE_QUEUE_NAME_IN
		, INTERPRCESS_MESSAGE_QUEUE_NAME_OUT);
 	processMsgManager_ = shared_ptr<ProcessMsgManager>(new ProcessMsgManager(INTERPRCESS_MESSAGE_QUEUE_NAME_IN,
		INTERPRCESS_MESSAGE_QUEUE_NAME_OUT));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
