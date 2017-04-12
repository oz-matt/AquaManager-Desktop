#pragma once
#include "ColorListCtrol.h"

// CGeofence dialog

class CGeofence : public CDialog
{
	DECLARE_DYNAMIC(CGeofence)

public:
	CGeofence(CWnd* pParent = NULL);   // standard constructor
	virtual ~CGeofence();

// Dialog Data
	enum { IDD = IDD_DLG_Geofence };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CColorListCtrol m_lst_geofence;
	CBrush m_brush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
