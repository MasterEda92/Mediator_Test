
// Mediator_TestMfcDlg.h : header file
//

#pragma once
#include <memory>
#include <IMediator.h>

// CMediatorTestMfcDlg dialog
class CMediatorTestMfcDlg : public CDialogEx
{
// Construction
public:
	CMediatorTestMfcDlg(std::shared_ptr<MediatorTest::IMediator> pMediator, CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEDIATOR_TESTMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nFirstNumber;
	int m_nSecondNumber;
	int m_nResult;
	afx_msg void OnBnClickedBtnCalc();

private:
	std::shared_ptr<MediatorTest::IMediator> m_pMediator;
};
