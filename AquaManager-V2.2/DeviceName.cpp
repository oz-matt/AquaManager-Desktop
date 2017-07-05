// DeviceName.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DeviceName.h"
#include "afxdialogex.h"


// CDeviceName dialog

IMPLEMENT_DYNAMIC(CDeviceName, CDialogEx)

CDeviceName::CDeviceName(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeviceName::IDD, pParent)
{

	m_device_name = _T("");
}

CDeviceName::~CDeviceName()
{
}

void CDeviceName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DeviceName, m_device_name);
}


BEGIN_MESSAGE_MAP(CDeviceName, CDialogEx)
END_MESSAGE_MAP()


// CDeviceName message handlers


BOOL CDeviceName::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_device_name = "USA";

	UpdateData(False);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
