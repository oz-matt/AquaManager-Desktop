// DeviceListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DeviceListCtrl.h"


// CDeviceListCtrl

IMPLEMENT_DYNAMIC(CDeviceListCtrl, CListCtrl)

CDeviceListCtrl::CDeviceListCtrl()
{

}

CDeviceListCtrl::~CDeviceListCtrl()
{
}


BEGIN_MESSAGE_MAP(CDeviceListCtrl, CListCtrl)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_DEVICE_INFO, &CDeviceListCtrl::OnDeviceInfo)
	ON_COMMAND(ID_DEVICE_RAWDATA, &CDeviceListCtrl::OnDeviceRawdata)
	ON_COMMAND(ID_DEVICE_REMOVE, &CDeviceListCtrl::OnDeviceRemove)
END_MESSAGE_MAP()



// CDeviceListCtrl message handlers




void CDeviceListCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// Find out what subitem was clicked
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
	menu.LoadMenu(IDR_POPUP_DeviceConfigure); //¶ÁÈ¡×ÊÔ´
	menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y, this);

	CListCtrl::OnLButtonDown(nFlags, point);
}


void CDeviceListCtrl::OnDeviceInfo()
{
	// TODO: Add your command handler code here
	CDlgConfigureDevice dlg;

	for (std::list<DeviceData*>::iterator it = ((CDevice*)pdevice)->_device.begin(); it != ((CDevice*)pdevice)->_device.end(); ++it)
	{
		if ((*it)->device_index == 0) // TODO: correct index instead of default 0
		{
			dlg.m_name = (*it)->device_name.c_str();
			dlg.m_pct_battery = (*it)->pct_battery.c_str();
			dlg.m_temperature = (*it)->temperature.c_str();
			dlg.m_humidity = (*it)->humidity.c_str();
			dlg.m_height = (*it)->height.c_str();
			dlg.m_speed = (*it)->speed.c_str();
			dlg.m_direction = (*it)->direction.c_str();
			dlg.m_numsat = (*it)->numsat.c_str();
			dlg.m_phone = (*it)->phone.c_str();
			dlg.m_aquaid = (*it)->aquaid.c_str();
			dlg.m_aquakey = (*it)->aquakey.c_str();
			dlg.m_previous_time = (*it)->previous_time.c_str();
			dlg.m_current_time = (*it)->current_time.c_str();
			dlg.m_previous_location = (*it)->previous_location.c_str();
			dlg.m_current_location = (*it)->current_location.c_str();
			break;
		}
	}

	UpdateData(False);
	dlg.DoModal();
}


void CDeviceListCtrl::OnDeviceRawdata()
{
	// TODO: Add your command handler code here
	CDeviceRawData dlg;

	UpdateData(False);
	dlg.DoModal();
}


void CDeviceListCtrl::OnDeviceRemove()
{
	// TODO: Add your command handler code here
	CDeviceRemove dlg;

	if (dlg.DoModal() == IDOK) {
		this->DeleteItem(current_index);
	}
}
