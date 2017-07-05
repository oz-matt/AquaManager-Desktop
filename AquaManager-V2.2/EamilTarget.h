#pragma once


// CEamilTarget dialog

class CEamilTarget : public CDialogEx
{
	DECLARE_DYNAMIC(CEamilTarget)

public:
	CEamilTarget(CWnd* pParent = NULL);   // standard constructor
	virtual ~CEamilTarget();

// Dialog Data
	enum { IDD = IDD_DLG_Email_Target };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_email;
};
