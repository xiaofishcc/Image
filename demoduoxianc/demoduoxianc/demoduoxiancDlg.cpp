
// demoduoxiancDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "demoduoxianc.h"
#include "demoduoxiancDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CdemoduoxiancDlg �Ի���



CdemoduoxiancDlg::CdemoduoxiancDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CdemoduoxiancDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdemoduoxiancDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CdemoduoxiancDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_StartThread, &CdemoduoxiancDlg::OnBnClickedStartthread)
END_MESSAGE_MAP()


// CdemoduoxiancDlg ��Ϣ�������

BOOL CdemoduoxiancDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CdemoduoxiancDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CdemoduoxiancDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CdemoduoxiancDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CdemoduoxiancDlg::OnBnClickedStartthread()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (flag)
	{
		flag = false;
		GetDlgItem(IDC_StartThread)->SetWindowTextW(_T("�����߳�"));
	}
	else
	{
		AfxBeginThread(Thread1, this, THREAD_PRIORITY_IDLE);
		AfxBeginThread(Thread2, this);

		flag = true;
		GetDlgItem(IDC_StartThread)->SetWindowTextW(_T("�ر����߳�"));
	}
}
UINT CdemoduoxiancDlg::Thread1(void *param)

{

	CdemoduoxiancDlg *dlg = (CdemoduoxiancDlg*)param;

	CEdit *randBox = (CEdit*)dlg->GetDlgItem(IDC_Random);

	CString str;

	while (dlg->flag)

	{

		Sleep(100);

		str.Format(_T("%i"), rand() % 1000);

		randBox->SetWindowTextW(str);

	}

	return 0;

}
UINT CdemoduoxiancDlg::Thread2(void *param)

{

	CdemoduoxiancDlg *dlg = (CdemoduoxiancDlg*)param;

	CEdit *SysTimeBox = (CEdit*)dlg->GetDlgItem(IDC_SysTime);

	CString str;

	while (dlg->flag)

	{

		Sleep(1000);

		CTime time = CTime::GetCurrentTime();

		str = time.Format(_T("%Y-%m-%d %H:%M:%S %A"));

		SysTimeBox->SetWindowTextW(str);

	}

	return 0;

}