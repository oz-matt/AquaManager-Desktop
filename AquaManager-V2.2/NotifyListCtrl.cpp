// NotifyListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "NotifyListCtrl.h"

#include "NotificationSettings.h"
#include "NotificationRemove.h"

// CNotifyListCtrl

IMPLEMENT_DYNAMIC(CNotifyListCtrl, CListCtrl)

CNotifyListCtrl::CNotifyListCtrl()
{

}

CNotifyListCtrl::~CNotifyListCtrl()
{
}


BEGIN_MESSAGE_MAP(CNotifyListCtrl, CListCtrl)
	ON_COMMAND(ID_NOTIFICATION_SETTINGS, &CNotifyListCtrl::OnNotificationSettings)
	ON_COMMAND(ID_NOTIFICATION_REMOVE, &CNotifyListCtrl::OnNotificationRemove)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CNotifyListCtrl message handlers




void CNotifyListCtrl::OnNotificationSettings()
{
	// TODO: Add your command handler code here
	CNotificationSettings dlg;

	dlg.DoModal();
}


void CNotifyListCtrl::OnNotificationRemove()
{
	// TODO: Add your command handler code here
	CNotificationRemove dlg;

	dlg.DoModal();
}


void CNotifyListCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	LVHITTESTINFO hitinfo = {0};
	hitinfo.flags = nFlags;
	hitinfo.pt = point;
	SubItemHitTest(&hitinfo);

	if (hitinfo.iItem < 0)
	{
		return;
	}

	current_index = hitinfo.iItem;

	CMenu menu;
	CRect windowRect;
	GetWindowRect(&windowRect);
	ClientToScreen(&point);
	menu.LoadMenu(IDR_POPUP_NotificationConfigure); //¶ÁÈ¡×ÊÔ´
	menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y, this);

	CListCtrl::OnLButtonDown(nFlags, point);
}
