
// ctrl_monitor_brightnessDlg.h : ͷ�ļ�
//

#pragma once

#include "pm_monitor_brightness.h"


// Cctrl_monitor_brightnessDlg �Ի���
class Cctrl_monitor_brightnessDlg : public CDialogEx
{
// ����
public:
	Cctrl_monitor_brightnessDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CTRL_MONITOR_BRIGHTNESS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


private:
	pm_monitor_brightness  _ctrl_brightness;


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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
