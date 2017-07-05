// EamilTarget.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "EamilTarget.h"
#include "afxdialogex.h"


// CEamilTarget dialog

IMPLEMENT_DYNAMIC(CEamilTarget, CDialogEx)

CEamilTarget::CEamilTarget(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEamilTarget::IDD, pParent)
{

	m_email = _T("");
}

CEamilTarget::~CEamilTarget()
{
}

void CEamilTarget::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Email, m_email);
}


BEGIN_MESSAGE_MAP(CEamilTarget, CDialogEx)
END_MESSAGE_MAP()


// CEamilTarget message handlers


BOOL CEamilTarget::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
