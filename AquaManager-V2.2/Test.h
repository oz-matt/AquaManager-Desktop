#pragma once


// CTest dialog

class CTest : public CDialogEx
{
	DECLARE_DYNAMIC(CTest)

public:
	CTest(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTest();

// Dialog Data
	enum { IDD = IDD_DLG_Test };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnSetcenter();
	afx_msg void OnBnClickedBtnAddmarker();
	afx_msg void OnBnClickedBtnSetzoom();
	afx_msg void OnBnClickedBtnDeletemarkers();
};
