
// MFCApplication1jiyuduihuakuangDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1jiyuduihuakuang.h"
#include "MFCApplication1jiyuduihuakuangDlg.h"
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
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()


// CMFCApplication1jiyuduihuakuangDlg �Ի���



CMFCApplication1jiyuduihuakuangDlg::CMFCApplication1jiyuduihuakuangDlg(CWnd* pParent /*=NULL*/)//ͨ���������ɵ��Զ���������߿ؼ��Ĺ������������ڹ��캯���г�ʼ��һ��ֵ�������߿���ֱ����ͷ�ļ�������������ֶ��ڹ��캯������ӳ�ʼ�����
//���ԣ����캯���Ǹ�����ֵ�ĺõط�
	: CDialogEx(CMFCApplication1jiyuduihuakuangDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1jiyuduihuakuangDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Enable, m_Enable);
	DDX_Control(pDX, IDC_Exit, m_Exit);
	//  DDX_Control(pDX, IDC_Delete, m_Delete);
}
//��Ϣӳ�䣬�����ַ�������Ϣ����Դ�ʹ�����
BEGIN_MESSAGE_MAP(CMFCApplication1jiyuduihuakuangDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Enable, &CMFCApplication1jiyuduihuakuangDlg::OnClickedEnable)
	ON_BN_CLICKED(IDC_Exit, &CMFCApplication1jiyuduihuakuangDlg::OnBnClickedExit)
	//ON_BN_CLICKED(IDC_Delete, &CMFCApplication1jiyuduihuakuangDlg::m_Delete)
END_MESSAGE_MAP()


// CMFCApplication1jiyuduihuakuangDlg ��Ϣ�������

BOOL CMFCApplication1jiyuduihuakuangDlg::OnInitDialog()
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
	m_Exit.EnableWindow(false);//ʹ���˳�����ť������
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication1jiyuduihuakuangDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1jiyuduihuakuangDlg::OnPaint()//���ƴ��ں�ͼ��
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;//�洢���ڴ�С�Ľṹ��
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
HCURSOR CMFCApplication1jiyuduihuakuangDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAboutDlg::OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/)
{
	// TODO:  �ڴ˴������Ϣ����������
}



void CMFCApplication1jiyuduihuakuangDlg::OnClickedEnable()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	m_Enable.GetWindowTextW(str);
	if (str == "ʹ��"){
		m_Exit.EnableWindow(true);
		m_Enable.SetWindowTextW(_T("��ʹ��"));
	}
	else
	{
		m_Exit.EnableWindow(false);
		m_Enable.SetWindowTextW(_T("ʹ��"));
	}
}


void CMFCApplication1jiyuduihuakuangDlg::OnBnClickedExit()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SendMessage(WM_CLOSE, 0, 0);
}


//void CMFCApplication1jiyuduihuakuangDlg::OnBnClickedDelete()
//{
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}
