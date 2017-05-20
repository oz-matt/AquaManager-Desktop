// DlgConfigureDevice.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DlgConfigureDevice.h"
#include "afxdialogex.h"


// CDlgConfigureDevice dialog

IMPLEMENT_DYNAMIC(CDlgConfigureDevice, CDialogEx)

CDlgConfigureDevice::CDlgConfigureDevice(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgConfigureDevice::IDD, pParent)
{

}

CDlgConfigureDevice::~CDlgConfigureDevice()
{
}

void CDlgConfigureDevice::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgConfigureDevice, CDialogEx)
END_MESSAGE_MAP()


// CDlgConfigureDevice message handlers
