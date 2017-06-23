#pragma once


// CDlgAddGeofence dialog

class CDlgAddGeofence : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgAddGeofence)

public:
	CDlgAddGeofence(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgAddGeofence();

// Dialog Data
	enum { IDD = IDD_DLG_AddGeofence };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
