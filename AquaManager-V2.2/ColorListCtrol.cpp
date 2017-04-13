// ColorListCtrol.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "ColorListCtrol.h"


// CColorListCtrol

IMPLEMENT_DYNAMIC(CColorListCtrol, CListCtrl)

CColorListCtrol::CColorListCtrol()
{

}

CColorListCtrol::~CColorListCtrol()
{
}


BEGIN_MESSAGE_MAP(CColorListCtrol, CListCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &CColorListCtrol::OnNMCustomdraw)
END_MESSAGE_MAP()



// CColorListCtrol message handlers




void CColorListCtrol::PreSubclassWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	CHeaderCtrl* pHeader = NULL;
	pHeader = GetHeaderCtrl();
	if (pHeader != NULL)
	{
		VERIFY(m_HeaderCtrl.SubclassWindow(pHeader->m_hWnd)); // m_HeaderCtrl is the new wrapper object
	}

	CListCtrl::PreSubclassWindow();
}


void CColorListCtrol::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	*pResult = 0;

	// TODO: Add your control notification handler code here
	NMTVCUSTOMDRAW* pLVCD = reinterpret_cast<NMTVCUSTOMDRAW *>( pNMHDR );

	//obtain row and column of item
	NMLVCUSTOMDRAW *pCD = (NMLVCUSTOMDRAW*)pNMHDR;
    int iRow = pCD->nmcd.dwItemSpec;
    int iCol = pCD->iSubItem;

	//Remove standard highlighting of selected (sub)item.
    //pCD->nmcd.uItemState = CDIS_DEFAULT;

	switch( pNMCD->dwDrawStage )
	{
	case CDDS_PREPAINT: // First stage (for the whole control)
		// Item prepaint notification.
		*pResult= CDRF_NOTIFYITEMDRAW;
		break;

	case CDDS_ITEMPREPAINT:
		{
			//if( ( CDIS_SELECTED == ( pNMCD->uItemState & CDIS_SELECTED )))
			//{
				//pNMCD->uItemState = CDIS_DEFAULT;
				//pLVCD->clrText   =  RGB(255, 255, 255);
				//pLVCD->clrTextBk =  RGB(255, 0, 0);
			//}
			*pResult = CDRF_NOTIFYSUBITEMDRAW;
		}
		break;

	case  CDDS_ITEMPREPAINT | CDDS_SUBITEM : // Stage three
		{
			//if (sub)item is of interest, set custom text/background color
            //if( 1 == iRow && 1 == iCol  )
			if (0 == type) {
				if (0 == iRow % 3)
				{
					pLVCD->clrText = RGB(255, 255, 255);
					pLVCD->clrTextBk = RGB(255, 0, 0);
				}
				else if (1 == iRow % 3)
				{
					pLVCD->clrText = RGB(255, 255, 255);
					pLVCD->clrTextBk = RGB(255, 255, 0);
				}
				else
				{
					pLVCD->clrText = RGB(255, 255, 255);
					pLVCD->clrTextBk = RGB(0, 255, 0);
				}
			}
			else if (1 == type) {
				pLVCD->clrText = RGB(255, 255, 255);
				pLVCD->clrTextBk = RGB(0, 0, 255);
			}
			else {
				pLVCD->clrText = RGB(255, 255, 255);
				pLVCD->clrTextBk = RGB(0, 255, 0);
			}
            *pResult =  CDRF_NOTIFYPOSTPAINT;
		}
		break;

	case CDDS_ITEMPOSTPAINT | CDDS_SUBITEM: // Stage four (called for each subitem of the focused item)
        break;

	default:
		*pResult = CDRF_DODEFAULT;
		break;
	}
}
