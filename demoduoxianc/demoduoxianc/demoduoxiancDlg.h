
// demoduoxiancDlg.h : ͷ�ļ�
//

#pragma once


// CdemoduoxiancDlg �Ի���
class CdemoduoxiancDlg : public CDialogEx
{
// ����
public:
	CdemoduoxiancDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DEMODUOXIANC_DIALOG };

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
	afx_msg void OnBnClickedStartthread();
	static UINT Thread1(void *param);
	static UINT Thread2(void *param);
	bool flag;
};
