#pragma once


// CGeofenceRemove dialog

class CGeofenceRemove : public CDialogEx
{
	DECLARE_DYNAMIC(CGeofenceRemove)

public:
	CGeofenceRemove(CWnd* pParent = NULL);   // standard constructor
	virtual ~CGeofenceRemove();

// Dialog Data
	enum { IDD = IDD_DLG_Geofence_Remove };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_remove;
	virtual BOOL OnInitDialog();
};
