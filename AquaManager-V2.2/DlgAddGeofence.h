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
	virtual BOOL OnInitDialog();
	CString m_geo_name;
	CString m_radius;
	BOOL m_circle;
	BOOL m_polygon;
	int m_radius_int;
	double m_radius_double;
};
