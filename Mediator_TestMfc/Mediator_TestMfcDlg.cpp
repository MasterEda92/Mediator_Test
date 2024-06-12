
// Mediator_TestMfcDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Mediator_TestMfc.h"
#include "Mediator_TestMfcDlg.h"
#include "afxdialogex.h"
#include <AddCommand.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMediatorTestMfcDlg dialog



CMediatorTestMfcDlg::CMediatorTestMfcDlg(std::shared_ptr<MediatorTest::IMediator> pMediator, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MEDIATOR_TESTMFC_DIALOG, pParent)
	, m_nFirstNumber(0)
	, m_nSecondNumber(0)
	, m_nResult(0)
	, m_pMediator(pMediator)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMediatorTestMfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FIRST_NUM, m_nFirstNumber);
	DDX_Text(pDX, IDC_EDIT_SECOND_NUM, m_nSecondNumber);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_nResult);
}

BEGIN_MESSAGE_MAP(CMediatorTestMfcDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CALC, &CMediatorTestMfcDlg::OnBnClickedBtnCalc)
END_MESSAGE_MAP()


// CMediatorTestMfcDlg message handlers

BOOL CMediatorTestMfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMediatorTestMfcDlg::OnPaint()
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
HCURSOR CMediatorTestMfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMediatorTestMfcDlg::OnBnClickedBtnCalc()
{
	UpdateData();

	auto Result = m_pMediator->Send(MediatorTest::CAddCommand(m_nFirstNumber, m_nSecondNumber));
	m_nResult = ((MediatorTest::CAddCommandResult*)Result.get())->GetResult();

	UpdateData(FALSE);
}
