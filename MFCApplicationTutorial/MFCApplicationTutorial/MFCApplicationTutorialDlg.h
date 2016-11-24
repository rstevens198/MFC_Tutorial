
// MFCApplicationTutorialDlg.h : header file
//

#pragma once


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
public:
	afx_msg void OnBnClickedBtnAdd();
};
