#pragma once


// CNotifyListCtrl

class CNotifyListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CNotifyListCtrl)

public:
	CNotifyListCtrl();
	virtual ~CNotifyListCtrl();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNotificationSettings();
	afx_msg void OnNotificationRemove();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


