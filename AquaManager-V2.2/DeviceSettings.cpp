// DeviceSettings.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DeviceSettings.h"
#include "afxdialogex.h"


// CDeviceSettings dialog

IMPLEMENT_DYNAMIC(CDeviceSettings, CDialogEx)

CDeviceSettings::CDeviceSettings(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeviceSettings::IDD, pParent)
{

}

CDeviceSettings::~CDeviceSettings()
{
}

void CDeviceSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDeviceSettings, CDialogEx)
END_MESSAGE_MAP()


// CDeviceSettings message handlers
