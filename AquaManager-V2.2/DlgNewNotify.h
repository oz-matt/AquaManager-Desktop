#pragma once


// CDlgNewNotify dialog

class CDlgNewNotify : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgNewNotify)

public:
	CDlgNewNotify(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgNewNotify();

// Dialog Data
	enum { IDD = IDD_DLG_NewNotify };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
