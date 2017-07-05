#pragma once


// CDlgMacAddress dialog

class CDlgMacAddress : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMacAddress)

public:
	CDlgMacAddress(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMacAddress();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_mac1;
	CString m_mac2;
	CString m_mac3;
	CString m_mac5;
	CString m_mac6;
	CString m_mac4;
	CString mac_addr;
	afx_msg void OnBnClickedOk();
};
