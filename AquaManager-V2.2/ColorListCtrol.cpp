// ColorListCtrol.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "ColorListCtrol.h"

#include "DlgConfigureDevice.h"
#include "DeviceRawData.h"
#include "DeviceRemove.h"

#include "NotificationSettings.h"
#include "NotificationRemove.h"

// CColorListCtrol

extern int currentTabSelected;

IMPLEMENT_DYNAMIC(CColorListCtrol, CListCtrl)

CColorListCtrol::CColorListCtrol()
{

}

CColorListCtrol::~CColorListCtrol()
{
}


BEGIN_MESSAGE_MAP(CColorListCtrol, CListCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &CColorListCtrol::OnNMCustomdraw)
	ON_NOTIFY_REFLECT(NM_CLICK, &CColorListCtrol::OnNMClick)
	ON_NOTIFY(HDN_ITEMCLICKA, 0, &CColorListCtrol::OnHdnItemclick)
	ON_NOTIFY(HDN_ITEMCLICKW, 0, &CColorListCtrol::OnHdnItemclick)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_DEVICE_INFO, &CColorListCtrol::OnDeviceInfo)
	ON_COMMAND(ID_DEVICE_RAWDATA, &CColorListCtrol::OnDeviceRawdata)
	ON_COMMAND(ID_DEVICE_REMOVE, &CColorListCtrol::OnDeviceRemove)
	ON_COMMAND(ID_NOTIFICATION_SETTINGS, &CColorListCtrol::OnNotificationSettings)
	ON_COMMAND(ID_NOTIFICATION_REMOVE, &CColorListCtrol::OnNotificationRemove)
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
				pLVCD->clrText = RGB(0, 0, 0);
				pLVCD->clrTextBk = RGB(192, 219, 255);
			}
			else if (1 == type) {
				pLVCD->clrText = RGB(0, 0, 0);
				pLVCD->clrTextBk = RGB(192, 219, 255);
			}
			else {
				pLVCD->clrText = RGB(0, 0, 0);
				pLVCD->clrTextBk = RGB(192, 219, 255);
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


void CColorListCtrol::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CColorListCtrol::OnHdnItemclick(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CColorListCtrol::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// Find out what subitem was clicked
	LVHITTESTINFO hitinfo = {0};
	hitinfo.flags = nFlags;
	hitinfo.pt = point;
	SubItemHitTest(&hitinfo);
	
	//if (hitinfo.iItem < 0)
		//return;

	int select = currentTabSelected;

	if (select == 0) {
		CMenu menu;
		CRect windowRect;  
		GetWindowRect(&windowRect); 
		ClientToScreen(&point);  
		menu.LoadMenu(IDR_POPUP_DeviceConfigure); //读取资源
		menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
	else if (select == 1) {
		CMenu menu;
		CRect windowRect;  
		GetWindowRect(&windowRect); 
		ClientToScreen(&point);  
		menu.LoadMenu(IDR_POPUP_NotificationConfigure); //读取资源
		menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
	else if (select == 2) {
		CMenu menu;
		CRect windowRect;  
		GetWindowRect(&windowRect); 
		ClientToScreen(&point);  
		menu.LoadMenu(IDR_POPUP_GeoConfigure); //读取资源
		menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
	else {}

	//CString Temp;
	//Temp.Format("Row: %d, Column %d", hitinfo.iItem, hitinfo.iSubItem);
	//MessageBox(Temp, "Information");
	
	//CListCtrl::OnLButtonDown(nFlags, point);
}


//void CColorListCtrol::OnLButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO: Add your message handler code here and/or call default
//
//	CListCtrl::OnLButtonUp(nFlags, point);
//}


void CColorListCtrol::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CListCtrl::OnLButtonDblClk(nFlags, point);
}


void CColorListCtrol::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CListCtrl::OnLButtonUp(nFlags, point);
}


void CColorListCtrol::OnDeviceInfo()
{
	// TODO: Add your command handler code here
	CDlgConfigureDevice dlg;
	dlg.DoModal();
}


void CColorListCtrol::OnDeviceRawdata()
{
	// TODO: Add your command handler code here
	CDeviceRawData dlg;
	dlg.DoModal();
}


void CColorListCtrol::OnDeviceRemove()
{
	// TODO: Add your command handler code here
	CDeviceRemove dlg;
	dlg.DoModal();
}


void CColorListCtrol::OnNotificationSettings()
{
	// TODO: Add your command handler code here
	CNotificationSettings dlg;
	dlg.DoModal();
}


void CColorListCtrol::OnNotificationRemove()
{
	// TODO: Add your command handler code here
	CNotificationRemove dlg;
	dlg.DoModal();
}
