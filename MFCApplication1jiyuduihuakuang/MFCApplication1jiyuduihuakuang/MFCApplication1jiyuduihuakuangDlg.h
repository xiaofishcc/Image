
// MFCApplication1jiyuduihuakuangDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFCApplication1jiyuduihuakuangDlg �Ի���
class CMFCApplication1jiyuduihuakuangDlg : public CDialogEx
{
// ����
public:
	CMFCApplication1jiyuduihuakuangDlg(CWnd* pParent = NULL);	// ��׼���캯��//ͨ���������ɵ��Զ���������߿ؼ��Ĺ������������ڹ��캯���г�ʼ��һ��ֵ�������߿���ֱ����ͷ�ļ�������������ֶ��ڹ��캯������ӳ�ʼ�����
	//���ԣ����캯���Ǹ�����ֵ�ĺõط�

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION1JIYUDUIHUAKUANG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��//���ڴ�Ÿ���ؼ��ı�����Ϣ


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();//��ʼ���Ի���
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();//���ƴ��ں�ͼ��
	afx_msg HCURSOR OnQueryDragIcon();//���ع��
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedEnable();
	afx_msg void OnBnClickedExit();
	CButton m_Enable;
	CButton m_Exit;
	// ״̬���ı�	���������ַ
	CStatic m_toast;
	afx_msg void OnStnClickedLinkbaidu();
	afx_msg void OnStnClickedLinkhao123();
	CStatic m_Wangyi;
	afx_msg void OnStnClickedToast();
	afx_msg void OnStnClickedWangyi();
	afx_msg void OnClose();
	afx_msg void OnBnClickedXXX(UINT nID);//������Ϣʱ��Ӧ�Ŀؼ�ID����Ӧ����
	CStatic m_toast2;
	afx_msg void OnStnClickedToast2();
	//�������ӷ����
	afx_msg void OnBnClickedCalc();
	double m_add1;
	double m_add2;
	double m_result;
	CEdit m_record;
	CString m_passWord;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnEnChangeStatus();
	afx_msg void OnEnChangePassword();
};
