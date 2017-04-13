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
};


