
// MFCApplicationTutorialDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CMFCApplicationTutorialDlg dialog
class CMFCApplicationTutorialDlg : public CDialogEx
{
// Construction
public:
	CMFCApplicationTutorialDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUTORIAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CString m_EchoText;
	int m_OkCount;
	int m_Seconds;
public:
	afx_msg void OnBnClickedBtnAdd();
private:
	CString m_VSliderEcho;
public:
	CSliderCtrl m_VSliderBar;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
private:
	CStatic m_HSliderEcho;
public:
	CSliderCtrl m_HSliderBar;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
private:
	CString m_HSliderBar1;
public:
	afx_msg void OnStnClickedTimerEcho3();
private:
	CString m_TimerEcho1;
public:
	CString m_MouseEcho;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
private:
	BOOL m_TimerCtrlSliders;
public:
	afx_msg void OnBnClickedTimerControlSliders();
private:
	BOOL m_TimerCtrlSliders1;
public:
	afx_msg void OnBnClickedButton2();
};
