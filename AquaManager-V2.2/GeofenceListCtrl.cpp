// GeofenceListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "GeofenceListCtrl.h"

#include "GeofenceRemove.h"

// CGeofenceListCtrl

IMPLEMENT_DYNAMIC(CGeofenceListCtrl, CListCtrl)

CGeofenceListCtrl::CGeofenceListCtrl()
{

}

CGeofenceListCtrl::~CGeofenceListCtrl()
{
}


BEGIN_MESSAGE_MAP(CGeofenceListCtrl, CListCtrl)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_GEOFENCE_REMOVE, &CGeofenceListCtrl::OnGeofenceRemove)
END_MESSAGE_MAP()



// CGeofenceListCtrl message handlers




void CGeofenceListCtrl::OnLButtonDown(UINT nFlags, CPoint point)
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
	menu.LoadMenu(IDR_POPUP_GeoConfigure); //¶ÁÈ¡×ÊÔ´
	menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y, this);

	CListCtrl::OnLButtonDown(nFlags, point);
}


void CGeofenceListCtrl::OnGeofenceRemove()
{
	// TODO: Add your command handler code here
	CGeofenceRemove dlg;

	dlg.DoModal();
}
