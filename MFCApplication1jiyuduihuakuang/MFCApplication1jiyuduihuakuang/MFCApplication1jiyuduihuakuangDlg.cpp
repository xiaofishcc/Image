
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
	, m_add1(0)
	, m_add2(0)
	, m_result(0)
	, m_passWord(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1jiyuduihuakuangDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Enable, m_Enable);
	DDX_Control(pDX, IDC_Exit, m_Exit);
	//  DDX_Control(pDX, IDC_Delete, m_Delete);
	DDX_Control(pDX, IDC_Toast, m_toast);
	DDX_Control(pDX, IDC_Wangyi, m_Wangyi);
	DDX_Control(pDX, IDC_Toast2, m_toast2);
	DDX_Control(pDX, IDC_Record, m_record);
}
//��Ϣӳ�䣬�����ַ�������Ϣ����Դ�ʹ�����
BEGIN_MESSAGE_MAP(CMFCApplication1jiyuduihuakuangDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	/*ON_WM_CLOSE()*/
	//�������
	//ON_BN_CLICKED(IDC_Enable, &CMFCApplication1jiyuduihuakuangDlg::OnClickedEnable)
	//ON_BN_CLICKED(IDC_Exit, &CMFCApplication1jiyuduihuakuangDlg::OnBnClickedExit)
	////ON_BN_CLICKED(IDC_Delete, &CMFCApplication1jiyuduihuakuangDlg::m_Delete)
	//ON_BN_CLICKED(IDC_LinkBaidu, &CMFCApplication1jiyuduihuakuangDlg::OnStnClickedLinkbaidu)
	//ON_BN_CLICKED(IDC_LinkHao123, &CMFCApplication1jiyuduihuakuangDlg::OnStnClickedLinkhao123)
	//ON_STN_CLICKED(IDC_Toast, &CMFCApplication1jiyuduihuakuangDlg::OnStnClickedToast)
	//ON_STN_CLICKED(IDC_Wangyi, &CMFCApplication1jiyuduihuakuangDlg::OnStnClickedWangyi)
	//��Ϣӳ�����
	/*ON_CONTROL_RANGE(BN_CLICKED, IDC_BUTTON1, IDC_BUTTON4, OnBnClickedXXX)
	ON_STN_CLICKED(IDC_Toast2, &CMFCApplication1jiyuduihuakuangDlg::OnStnClickedToast2)*/
	//���������
	ON_BN_CLICKED(IDC_CALC, &CMFCApplication1jiyuduihuakuangDlg::OnBnClickedCalc)
	ON_EN_CHANGE(IDC_Status, &CMFCApplication1jiyuduihuakuangDlg::OnEnChangeStatus)
	ON_EN_CHANGE(IDC_Password, &CMFCApplication1jiyuduihuakuangDlg::OnEnChangePassword)
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

	//ʹ�ܿ����˳���ť�Ŀ�����
	m_Exit.EnableWindow(false);//ʹ���˳�����ť������

	//����������������㰴ť������
	m_record.SetWindowTextW(_T("���������룡\n"));
	GetDlgItem(IDC_CALC)->EnableWindow(false);

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
	// �ؼ�ʹ�ܶ��˳��Ŀ���ʵ��
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


void CMFCApplication1jiyuduihuakuangDlg::OnStnClickedLinkbaidu()
{
	// �򿪰ٶ���ҳ
	ShellExecute(0, NULL, _T("http://www.baidu.com"), NULL, NULL, SW_NORMAL);
	GetDlgItem(IDC_LinkBaidu)->SetWindowTextW(_T("��ðٶ�"));
	m_toast.SetWindowTextW(_T("�Ѵ򿪰ٶ���ҳ��"));
}


void CMFCApplication1jiyuduihuakuangDlg::OnStnClickedLinkhao123()
{
	// ��hao123��ҳ
	ShellExecute(0, NULL, _T("http://www.hao123.com"), NULL, NULL, SW_NORMAL);
	GetDlgItem(IDC_LinkHao123)->SetWindowTextW(_T("���hao123"));
	m_toast.SetWindowTextW(_T("�Ѵ�hao123��ҳ��"));
}



void CMFCApplication1jiyuduihuakuangDlg::OnStnClickedToast()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFCApplication1jiyuduihuakuangDlg::OnStnClickedWangyi()
{
	// ��163��ҳ
	ShellExecute(0, NULL, _T("http://http://www.163.com/"), NULL, NULL, SW_NORMAL);
	GetDlgItem(IDC_Wangyi)->SetWindowTextW(_T("���163"));
	m_toast.SetWindowTextW(_T("�Ѵ�163��ҳ��"));
}
//��Ϣӳ�䣬����ͬһ�ఴť
void CMFCApplication1jiyuduihuakuangDlg::OnBnClickedXXX(UINT nID)
{
	int ID = nID - IDC_BUTTON1;
	CString str;
	str.Format(_T("%s%i%s"), _T("��ť"), ID + 1, _T("���£�"));
	m_toast2.SetWindowTextW(str);
	//ע�͵��ĺ�ǰ�����д��������һ��
	//switch (ID)
	//{
	//case 0:m_toast2.SetWindowTextW(_T("��ť1���£�")); break;
	//case 1:m_toast2.SetWindowTextW(_T("��ť2���£�")); break;
	//case 2:m_toast2.SetWindowTextW(_T("��ť3���£�")); break;
	//case 3:m_toast2.SetWindowTextW(_T("��ť4���£�")); break;
	//}
}

void CMFCApplication1jiyuduihuakuangDlg::OnStnClickedToast2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFCApplication1jiyuduihuakuangDlg::OnBnClickedCalc()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);//��ȡ����
	m_result = m_add1 + m_add2;
	UpdateData(false);//��������
	CString str;
	str.Format(_T("%g%s%g%s%g"),m_add1, _T("+"), m_add2, _T("="),m_result);//������ʾ��ʽ
	str += _T("\r\n");//�س�����
	int lastLine = m_record.LineIndex(m_record.GetLineCount() - 1);
	m_record.SetSel(lastLine + 1, lastLine + 2, 0);
	m_record.ReplaceSel(str);//�����һ������µ�����
}

//������༭�����һ���麯����1��ֹ���»س�����esc��ťʱ�˳�����2�ж������Ƿ���ȷ����������
BOOL CMFCApplication1jiyuduihuakuangDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �ڴ����ר�ô����/����û���
	switch (pMsg->wParam)
	{
	case VK_RETURN:
		UpdateData(true);
		if (m_passWord == _T("111111"))
		{
			GetDlgItem(IDC_CALC)->EnableWindow(true);
			GetDlgItem(IDC_Status)->SetWindowTextW(_T("sucess"));
		}
		else
		{
			GetDlgItem(IDC_Status)->SetWindowTextW(_T("error"));
		}
	case VK_ESCAPE:
		return true; break;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CMFCApplication1jiyuduihuakuangDlg::OnEnChangeStatus()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFCApplication1jiyuduihuakuangDlg::OnEnChangePassword()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
