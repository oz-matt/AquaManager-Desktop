#pragma once


// CDlgNoGeofence dialog

class CDlgNoGeofence : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgNoGeofence)

public:
	CDlgNoGeofence(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgNoGeofence();

// Dialog Data
	enum { IDD = IDD_DLG_NoGeofence };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
//	CEdit m_nogeofence;
	CString m_nogeofence;
};
