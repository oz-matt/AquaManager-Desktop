// PhoneTarget.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "PhoneTarget.h"
#include "afxdialogex.h"


// CPhoneTarget dialog

IMPLEMENT_DYNAMIC(CPhoneTarget, CDialogEx)

CPhoneTarget::CPhoneTarget(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPhoneTarget::IDD, pParent)
{

	m_phone = _T("");
}

CPhoneTarget::~CPhoneTarget()
{
}

void CPhoneTarget::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Phone, m_phone);
}


BEGIN_MESSAGE_MAP(CPhoneTarget, CDialogEx)
END_MESSAGE_MAP()


// CPhoneTarget message handlers


BOOL CPhoneTarget::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
