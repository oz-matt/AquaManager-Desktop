// Device.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "Device.h"
#include "afxdialogex.h"

#include "DlgAddDevice.h"
#include "AquaLib.h"

// CDevice dialog

IMPLEMENT_DYNAMIC(CDevice, CDialog)

CDevice::CDevice(CWnd* pParent /*=NULL*/)
	: CDialog(CDevice::IDD, pParent)
{
	m_lst_device.type = 0;
	ImgHeaders = new CImageList;
}

CDevice::~CDevice()
{
	delete ImgHeaders;
}

void CDevice::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LST_Device, m_lst_device);
}


BEGIN_MESSAGE_MAP(CDevice, CDialog)
	ON_WM_CTLCOLOR()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LST_Device, &CDevice::OnLvnItemchangedLstDevice)
	ON_BN_CLICKED(IDC_BTN_AddMarker, &CDevice::OnBnClickedBtnAddmarker)
END_MESSAGE_MAP()


// CDevice message handlers


BOOL CDevice::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	ImgHeaders->Create(16, 16, ILC_MASK, 1, 1);
	ImgHeaders->Add(AfxGetApp()->LoadIcon(IDI_SETTING));
	m_lst_device.SetImageList(ImgHeaders, LVSIL_SMALL);

	LVCOLUMN lvColumn;
	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 70;
	lvColumn.pszText = _T("Name");
	m_lst_device.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH | LVCF_IMAGE;
	lvColumn.fmt = LVCFMT_LEFT | LVCFMT_IMAGE;
	lvColumn.iImage = 0;
	lvColumn.cx = 70;
	lvColumn.pszText =_T("Location");
	m_lst_device.InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH | LVCF_IMAGE;
	lvColumn.fmt = LVCFMT_LEFT | LVCFMT_IMAGE;
	lvColumn.iImage = 1;
	lvColumn.cx = 70;
	lvColumn.pszText =_T("Battery");
	m_lst_device.InsertColumn(1, &lvColumn);

	// Add some columns to the list control
	//m_lst_device.InsertColumn( 0, _T("Name") );
	//m_lst_device.InsertColumn( 1, _T("Location") );
	//m_lst_device.InsertColumn( 2, _T("Battery") );

	// Set the column widths
	m_lst_device.SetColumnWidth( 0, 70 );
	m_lst_device.SetColumnWidth( 1, 70 );
	m_lst_device.SetColumnWidth( 2, LVSCW_AUTOSIZE_USEHEADER );

	nIndex = m_lst_device.InsertItem(0, _T("Dev1"));
	m_lst_device.SetItemText(nIndex, 1, _T("Woods Way, New Fairfield CT, USA"));
	m_lst_device.SetItemText(nIndex, 2, _T("45%"));

	nIndex = m_lst_device.InsertItem(0, _T("Dev2"));
	m_lst_device.SetItemText(nIndex, 1, _T("St Louis St, Avon, CT USA"));
	m_lst_device.SetItemText(nIndex, 2, _T("88%"));

	nIndex = m_lst_device.InsertItem(0, _T("Dev3"));
	m_lst_device.SetItemText(nIndex, 1, _T("15th St, New York, NY, USA"));
	m_lst_device.SetItemText(nIndex, 2, _T("11%"));

	nIndex = m_lst_device.InsertItem(0, _T("Dev4"));
	m_lst_device.SetItemText(nIndex, 1, _T("Woods Way, New Fairfield CT, USA"));
	m_lst_device.SetItemText(nIndex, 2, _T("45%"));

	m_lst_device.SetBkColor(RGB(255, 255, 255));

	m_brush.CreateSolidBrush(RGB(255, 255, 255));

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


void CDevice::OnLvnItemchangedLstDevice(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CDevice::OnBnClickedBtnAddmarker()
{
	// TODO: Add your control notification handler code here
	CDlgAddDevice dlg;
	dlg.DoModal();
	dlg.m_aquaid;
	dlg.m_passcode;

	char* data;
	char ip[32] = "198.61.169.55:8081";
	char temp[1024] = "";

	sprintf(temp, "%s\"%s\",%s\"%s\",%s", "{\"reqtype\":\"auth\",\"id\":",dlg.m_aquaid, "\"pass\":", dlg.m_passcode, "\"iid\":\"12341234123412341234\"}");
	data = handle_url_fields(ip, temp);

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "Auth Info");
        free(data);
    }
}
