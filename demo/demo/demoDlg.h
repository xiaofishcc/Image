
// demoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CdemoDlg �Ի���
class CdemoDlg : public CDialogEx
{
// ����
public:
	CdemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeAdd2();
	CStatic m_algorithm;
	afx_msg void OnBnClickedCalc1();
	afx_msg void OnEnChangeAdd1();
	afx_msg void OnBnClickedUse();
	afx_msg void OnBnClickedNuse();
	//���������������¼�
	afx_msg void OnBnClickedAlgor(UINT nID);
	double m_add1;
	double m_add2;
	double m_result;
	int m_plus;
	BOOL m_use;
	CButton m_pisa1;
	CButton m_pisa2;
	CButton m_pisa3;
	UINT m_num1;
	UINT m_num2;
	UINT m_num3;
	afx_msg void OnBnClickedButton1();
	double m_result1;
};
