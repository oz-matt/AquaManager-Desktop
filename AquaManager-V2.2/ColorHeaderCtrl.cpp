// ColorHeaderCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "ColorHeaderCtrl.h"


// CColorHeaderCtrl

IMPLEMENT_DYNAMIC(CColorHeaderCtrl, CHeaderCtrl)

CColorHeaderCtrl::CColorHeaderCtrl()
{

}

CColorHeaderCtrl::~CColorHeaderCtrl()
{
}


BEGIN_MESSAGE_MAP(CColorHeaderCtrl, CHeaderCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &CColorHeaderCtrl::OnNMCustomdraw)
END_MESSAGE_MAP()



// CColorHeaderCtrl message handlers




void CColorHeaderCtrl::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	if (pNMCD->dwDrawStage == CDDS_PREPAINT)
	{
		CDC* pDC = CDC::FromHandle(pNMCD->hdc);
		CRect rect(0, 0, 0, 0);
		GetClientRect(&rect);
		pDC->FillSolidRect(&rect, RGB(0, 0, 0));

		*pResult = CDRF_NOTIFYITEMDRAW;
	}
	else if (pNMCD->dwDrawStage == CDDS_ITEMPREPAINT)
	{
		HDITEM hditem;
		TCHAR buffer[MAX_PATH] = { 0 };
		SecureZeroMemory(&hditem, sizeof(HDITEM));
		hditem.mask = HDI_TEXT;
		hditem.pszText = buffer;
		hditem.cchTextMax = MAX_PATH;
		GetItem(pNMCD->dwItemSpec, &hditem);
		CDC* pDC = CDC::FromHandle(pNMCD->hdc);
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkColor(RGB(0, 0, 0));
		CString str(buffer);
		pDC->DrawText(str, CRect(pNMCD->rc), DT_VCENTER | DT_LEFT);
		*pResult = CDRF_SKIPDEFAULT;
	}
}
