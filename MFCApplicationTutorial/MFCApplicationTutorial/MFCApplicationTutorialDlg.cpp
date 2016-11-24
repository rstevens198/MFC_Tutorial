
// MFCApplicationTutorialDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplicationTutorial.h"
#include "MFCApplicationTutorialDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplicationTutorialDlg dialog



CMFCApplicationTutorialDlg::CMFCApplicationTutorialDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATIONTUTORIAL_DIALOG, pParent)
	, m_EchoText(_T(""))
	, m_VSliderEcho(_T(""))
	, m_HSliderBar1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationTutorialDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ECHO_AREA, m_EchoText);
	DDX_Text(pDX, IDC_V_SLIDER_ECHO, m_VSliderEcho);
	DDX_Control(pDX, IDC_V_SLIDER_BAR, m_VSliderBar);
	DDX_Control(pDX, IDC_H_SLIDER_ECHO, m_HSliderEcho);
	DDX_Control(pDX, IDC_H_SLIDER_BAR, m_HSliderBar);
	DDX_Text(pDX, IDC_H_SLIDER_ECHO, m_HSliderBar1);
}

BEGIN_MESSAGE_MAP(CMFCApplicationTutorialDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ADD, &CMFCApplicationTutorialDlg::OnBnClickedBtnAdd)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CMFCApplicationTutorialDlg message handlers

BOOL CMFCApplicationTutorialDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	m_OkCount = 0;

	m_VSliderBar.SetRange(0, 100, TRUE);
	m_VSliderBar.SetPos(0);
	m_VSliderEcho.Format(_T("%d"), 0);

	m_HSliderBar.SetRange(0, 100, TRUE);
	m_HSliderBar.SetPos(0);
	m_HSliderBar1.Format(_T("%d"), 0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplicationTutorialDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplicationTutorialDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplicationTutorialDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplicationTutorialDlg::OnBnClickedBtnAdd()
{
	// TODO: Add your control notification handler code here
	m_OkCount++;
	m_EchoText.Format(_T("%d"), m_OkCount);
	// without UpdateData() status area will _NOT_ be updated.
	UpdateData(FALSE);
}


void CMFCApplicationTutorialDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	if (pScrollBar == (CScrollBar *)&m_VSliderBar)
	{
		int value = m_VSliderBar.GetPos();
		m_VSliderEcho.Format(_T("%d"), value);
		UpdateData(FALSE);
	}
	else 
		CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CMFCApplicationTutorialDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	if (pScrollBar == (CScrollBar *)&m_HSliderBar)
	{
		int value = m_HSliderBar.GetPos();
		m_HSliderBar1.Format(_T("%d"), value);
		UpdateData(FALSE);
	}
	else 
		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
