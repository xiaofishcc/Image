
// MFCApplication1jiyuduihuakuangDlg.h : ͷ�ļ�
//

#pragma once


// CMFCApplication1jiyuduihuakuangDlg �Ի���
class CMFCApplication1jiyuduihuakuangDlg : public CDialogEx
{
// ����
public:
	CMFCApplication1jiyuduihuakuangDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION1JIYUDUIHUAKUANG_DIALOG };

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
};
