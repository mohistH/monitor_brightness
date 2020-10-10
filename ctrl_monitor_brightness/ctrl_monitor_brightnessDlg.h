
// ctrl_monitor_brightnessDlg.h : 头文件
//

#pragma once

#include "pm_monitor_brightness.h"


// Cctrl_monitor_brightnessDlg 对话框
class Cctrl_monitor_brightnessDlg : public CDialogEx
{
// 构造
public:
	Cctrl_monitor_brightnessDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CTRL_MONITOR_BRIGHTNESS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


private:
	pm_monitor_brightness  _ctrl_brightness;


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
