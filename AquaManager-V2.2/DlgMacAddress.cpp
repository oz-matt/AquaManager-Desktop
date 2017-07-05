// DlgMacAddress.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DlgMacAddress.h"
#include "afxdialogex.h"


// CDlgMacAddress dialog

IMPLEMENT_DYNAMIC(CDlgMacAddress, CDialogEx)

CDlgMacAddress::CDlgMacAddress(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgMacAddress::IDD, pParent)
{

	m_mac1 = _T("");
	m_mac2 = _T("");
	m_mac3 = _T("");
	m_mac5 = _T("");
	m_mac6 = _T("");
	m_mac4 = _T("");
}

CDlgMacAddress::~CDlgMacAddress()
{
}

void CDlgMacAddress::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Mac1, m_mac1);
	DDX_Text(pDX, IDC_EDIT_Mac2, m_mac2);
	DDX_Text(pDX, IDC_EDIT_Mac3, m_mac3);
	DDX_Text(pDX, IDC_EDIT_Mac5, m_mac5);
	DDX_Text(pDX, IDC_EDIT_Mac6, m_mac6);
	DDX_Text(pDX, IDC_EDIT_Mac4, m_mac4);
}


BEGIN_MESSAGE_MAP(CDlgMacAddress, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgMacAddress::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgMacAddress message handlers


BOOL CDlgMacAddress::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgMacAddress::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	mac_addr = m_mac1 + m_mac2 + m_mac3 + m_mac4 + m_mac5 + m_mac6;
	CDialogEx::OnOK();
}
