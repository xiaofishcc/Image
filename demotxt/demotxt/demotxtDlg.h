
// demotxtDlg.h : ͷ�ļ�
//

#pragma once


// CdemotxtDlg �Ի���
class CdemotxtDlg : public CDialogEx
{
// ����
public:
	CdemotxtDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DEMOTXT_DIALOG };

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
	int m_DataType;
	UINT m_DataNum;
	CString m_txtName;
	afx_msg void OnBnClickedSave();
};
