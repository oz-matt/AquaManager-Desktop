// AddPolygon.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "AddPolygon.h"
#include "afxdialogex.h"


// CAddPolygon dialog

IMPLEMENT_DYNAMIC(CAddPolygon, CDialogEx)

CAddPolygon::CAddPolygon(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddPolygon::IDD, pParent)
{

	m_side = 0;
}

CAddPolygon::~CAddPolygon()
{
}

void CAddPolygon::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Side, m_side);
}


BEGIN_MESSAGE_MAP(CAddPolygon, CDialogEx)
END_MESSAGE_MAP()


// CAddPolygon message handlers
