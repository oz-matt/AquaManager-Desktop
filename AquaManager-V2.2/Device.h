#pragma once
#include "ColorListCtrol.h"

// CDevice dialog

class CDevice : public CDialog
{
	DECLARE_DYNAMIC(CDevice)

public:
	CDevice(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDevice();

// Dialog Data
	enum { IDD = IDD_DLG_Device };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CColorListCtrol m_lst_device;
	CBrush m_brush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	int nIndex;
	CImageList *ImgHeaders;
	afx_msg void OnLvnItemchangedLstDevice(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnAddmarker();
	CMFCButton m_btn_add_device;
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNMRClickLstDevice(NMHDR *pNMHDR, LRESULT *pResult);
};
