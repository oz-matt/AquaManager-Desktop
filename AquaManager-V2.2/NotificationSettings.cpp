// NotificationSettings.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "NotificationSettings.h"
#include "afxdialogex.h"


// CNotificationSettings dialog

IMPLEMENT_DYNAMIC(CNotificationSettings, CDialogEx)

CNotificationSettings::CNotificationSettings(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNotificationSettings::IDD, pParent)
{

}

CNotificationSettings::~CNotificationSettings()
{
}

void CNotificationSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNotificationSettings, CDialogEx)
END_MESSAGE_MAP()


// CNotificationSettings message handlers
