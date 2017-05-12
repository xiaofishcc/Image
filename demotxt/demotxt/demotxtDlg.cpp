
// demotxtDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "demotxt.h"
#include "demotxtDlg.h"
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


// CdemotxtDlg �Ի���



CdemotxtDlg::CdemotxtDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CdemotxtDlg::IDD, pParent)
	, m_DataType(0)
	, m_DataNum(100)//���ݸ���Ĭ��ֵ100
	, m_txtName(_T("Data.txt"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdemotxtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_Rand, m_DataType);
	DDX_Text(pDX, IDC_DataNum, m_DataNum);
	DDX_Text(pDX, IDC_txtName, m_txtName);
}

BEGIN_MESSAGE_MAP(CdemotxtDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Save, &CdemotxtDlg::OnBnClickedSave)
END_MESSAGE_MAP()


// CdemotxtDlg ��Ϣ�������

BOOL CdemotxtDlg::OnInitDialog()
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

void CdemotxtDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CdemotxtDlg::OnPaint()
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
HCURSOR CdemotxtDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CdemotxtDlg::OnBnClickedSave()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	double Data[10000] = { 0 };
	switch (m_DataType)
	{
	case 0:
		for (int i = 0; i < m_DataNum; i++)
		{
			Data[i] = rand() % 10000;
			break;
		}
	case 1:
		Data[1] = 1; Data[2] = 1;
		for (int i = 2; i < m_DataNum; i++)
		{
			Data[i] = Data[i - 1] + Data[i-2];
			break;
		}
	case 2:
		for (int i = 0; i < m_DataNum; i++)
		{
			Data[i] = 1;
			for (int j = 1; j < i+1; j++)
			{
				Data[i] *= j;
			}
			break;
		}
	}
	//ͨ��CStdioFile��Ķ�������д��txt�ļ��У�Open��������ָ������·����Ĭ�ϱ����ڹ����ļ���Demo\Demo\�ļ�����
	CStdioFile file;
	file.Open(m_txtName, CFile::modeCreate | CFile::modeWrite | CFile::typeText);
	CString str;
	for (int i = 0; i < m_DataNum; i++)
	{
		str.Format(_T("%d\t%g\n"), i + 1, Data[i]);
		file.WriteString(str);
	}
	file.Close();
	AfxMessageBox(_T("�ѱ������ݵ� ") + m_txtName + _T(" �ļ��У�"));
}
