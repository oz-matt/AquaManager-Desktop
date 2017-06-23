// DeviceRawData.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DeviceRawData.h"
#include "afxdialogex.h"


// CDeviceRawData dialog

IMPLEMENT_DYNAMIC(CDeviceRawData, CDialogEx)

CDeviceRawData::CDeviceRawData(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeviceRawData::IDD, pParent)
{

}

CDeviceRawData::~CDeviceRawData()
{
}

void CDeviceRawData::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDeviceRawData, CDialogEx)
END_MESSAGE_MAP()


// CDeviceRawData message handlers
