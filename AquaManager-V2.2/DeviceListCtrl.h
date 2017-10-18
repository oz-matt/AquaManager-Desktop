#pragma once


// CDeviceListCtrl

class CDeviceListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CDeviceListCtrl)

public:
	CDeviceListCtrl();
	virtual ~CDeviceListCtrl();

	friend class CDevice;

protected:
	DECLARE_MESSAGE_MAP()

	void *pdevice;
	int current_index;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDeviceInfo();
	afx_msg void OnDeviceRawdata();
	afx_msg void OnDeviceRemove();
};


