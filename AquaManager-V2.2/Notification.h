#pragma once
#include "ColorListCtrol.h"

// CNotification dialog

class CNotification : public CDialog
{
	DECLARE_DYNAMIC(CNotification)

public:
	CNotification(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNotification();

// Dialog Data
	enum { IDD = IDD_DLG_Notification };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CColorListCtrol m_lst_notificaton;
	CBrush m_brush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
