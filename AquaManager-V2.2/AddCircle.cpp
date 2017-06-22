// AddCircle.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "AddCircle.h"
#include "afxdialogex.h"


// CAddCircle dialog

IMPLEMENT_DYNAMIC(CAddCircle, CDialogEx)

CAddCircle::CAddCircle(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddCircle::IDD, pParent)
{

	m_radius = 0;
}

CAddCircle::~CAddCircle()
{
}

void CAddCircle::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Radius, m_radius);
}


BEGIN_MESSAGE_MAP(CAddCircle, CDialogEx)
END_MESSAGE_MAP()


// CAddCircle message handlers
