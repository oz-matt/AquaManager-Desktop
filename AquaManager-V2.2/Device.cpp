// Device.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "Device.h"
#include "afxdialogex.h"


// CDevice dialog

IMPLEMENT_DYNAMIC(CDevice, CDialog)

CDevice::CDevice(CWnd* pParent /*=NULL*/)
	: CDialog(CDevice::IDD, pParent)
{

}

CDevice::~CDevice()
{
}

void CDevice::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LST_Device, m_lst_device);
}


BEGIN_MESSAGE_MAP(CDevice, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDevice message handlers


BOOL CDevice::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	// Add some columns to the list control
	m_lst_device.InsertColumn( 0, _T("Name") );
	m_lst_device.InsertColumn( 1, _T("Location") );
	m_lst_device.InsertColumn( 2, _T("Battery") );

	// Set the column widths
	m_lst_device.SetColumnWidth( 0, 70 );
	m_lst_device.SetColumnWidth( 1, 70 );
	m_lst_device.SetColumnWidth( 2, LVSCW_AUTOSIZE_USEHEADER );

	m_lst_device.SetBkColor(RGB(0, 0, 0));

	m_brush.CreateSolidBrush(RGB(0, 0, 0));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


HBRUSH CDevice::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	HBRUSH hbr = m_brush;

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
