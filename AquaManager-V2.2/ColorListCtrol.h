#pragma once
#include "ColorHeaderCtrl.h"

// CColorListCtrol

class CColorListCtrol : public CListCtrl
{
	DECLARE_DYNAMIC(CColorListCtrol)

public:
	CColorListCtrol();
	virtual ~CColorListCtrol();

protected:
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();

	CColorHeaderCtrl m_HeaderCtrl;
public:
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	int type;
	afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHdnItemclick(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDeviceInfo();
	afx_msg void OnDeviceRawdata();
	afx_msg void OnDeviceRemove();
	afx_msg void OnNotificationSettings();
	afx_msg void OnNotificationRemove();
};


