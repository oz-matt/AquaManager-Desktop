// DeviceRawDataShow.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DeviceRawDataShow.h"
#include "afxdialogex.h"


// CDeviceRawDataShow dialog

IMPLEMENT_DYNAMIC(CDeviceRawDataShow, CDialogEx)

CDeviceRawDataShow::CDeviceRawDataShow(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeviceRawDataShow::IDD, pParent)
{

	m_raw_data_show = _T("");
}

CDeviceRawDataShow::~CDeviceRawDataShow()
{
}

void CDeviceRawDataShow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RawData, m_raw_data_show);
}


BEGIN_MESSAGE_MAP(CDeviceRawDataShow, CDialogEx)
END_MESSAGE_MAP()


// CDeviceRawDataShow message handlers


BOOL CDeviceRawDataShow::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
