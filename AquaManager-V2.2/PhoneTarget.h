#pragma once


// CPhoneTarget dialog

class CPhoneTarget : public CDialogEx
{
	DECLARE_DYNAMIC(CPhoneTarget)

public:
	CPhoneTarget(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPhoneTarget();

// Dialog Data
	enum { IDD = IDD_DLG_Phone_Target };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_phone;
};
