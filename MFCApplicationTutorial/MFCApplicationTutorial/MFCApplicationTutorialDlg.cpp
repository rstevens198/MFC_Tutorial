
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
	, m_TimerEcho1(_T(""))
	, m_MouseEcho(_T(""))
	, m_TimerCtrlSliders(FALSE)
	, m_TimerCtrlSliders1(FALSE)
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
	/*DDX_Text(pDX, IDC_TIMER_ECHO, m_TimerEcho1);
	DDX_Text(pDX, IDC_MOUSE_ECHO1, m_MouseEcho);
	DDX_Check(pDX, IDC_TIMER_CONTROL_SLIDERS, m_TimerCtrlSliders);*/
	DDX_Check(pDX, IDC_TIMER_CONTROL_SLIDERS, m_TimerCtrlSliders1);
}

BEGIN_MESSAGE_MAP(CMFCApplicationTutorialDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ADD, &CMFCApplicationTutorialDlg::OnBnClickedBtnAdd)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_TIMER_CONTROL_SLIDERS, &CMFCApplicationTutorialDlg::OnBnClickedTimerControlSliders)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplicationTutorialDlg::OnBnClickedButton2)
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

	m_Seconds = 0;
	SetTimer(0, 1000, NULL);

	m_TimerCtrlSliders1 = TRUE;
	UpdateData(FALSE);

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




void CMFCApplicationTutorialDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	m_Seconds++;
	m_TimerEcho1.Format(_T("%d Seconds have passed"), m_Seconds);
	if (m_TimerCtrlSliders1)
	{
		// Get ready to decrease the sliders ... 
		int hvalue = m_HSliderBar.GetPos();
		if (hvalue > 0)
		{
			m_HSliderBar.SetPos(hvalue - 1);
			m_HSliderBar1.Format(_T("%d"), hvalue - 1);
		}
		// do the same for the vertical slider 
		int vvalue = m_VSliderBar.GetPos();
		if (vvalue > 0)
		{
			m_VSliderBar.SetPos(vvalue - 1);
			m_VSliderEcho.Format(_T("%d"), vvalue - 1);
		}
		if ((hvalue == 0) && (vvalue == 0))
		{
			m_TimerCtrlSliders1 = FALSE;
		}
	}

	UpdateData(FALSE);
}


void CMFCApplicationTutorialDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	CDialogEx::OnMouseMove(nFlags, point);
	m_MouseEcho.Format(_T("Mouse Move at %d,%d"), point.x, point.y);
	UpdateData(FALSE);
}


void CMFCApplicationTutorialDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnLButtonDown(nFlags, point);
	m_MouseEcho.Format(_T("Left mouse down at %d,%d"), point.x, point.y);
	UpdateData(FALSE);
}


void CMFCApplicationTutorialDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnRButtonDown(nFlags, point);
	m_MouseEcho.Format(_T("Right mouse down at %d,%d"), point.x, point.y);
	UpdateData(FALSE);
}


void CMFCApplicationTutorialDlg::OnBnClickedTimerControlSliders()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	// This will fill all UI-connected variables with whatever 
	// value that is showing on the UI control objects.
}


void CMFCApplicationTutorialDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	m_OkCount = 0;
	m_EchoText.Format(_T("%d"), m_OkCount);
	// without UpdateData() status area will _NOT_ be updated.
	UpdateData(FALSE);
}
