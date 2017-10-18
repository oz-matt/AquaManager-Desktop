#pragma once


// CGeofenceListCtrl

class CGeofenceListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CGeofenceListCtrl)

public:
	CGeofenceListCtrl();
	virtual ~CGeofenceListCtrl();

protected:
	DECLARE_MESSAGE_MAP()

	int current_index;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnGeofenceRemove();
};


