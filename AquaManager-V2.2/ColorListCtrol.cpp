// ColorListCtrol.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "ColorListCtrol.h"


// CColorListCtrol

IMPLEMENT_DYNAMIC(CColorListCtrol, CListCtrl)

CColorListCtrol::CColorListCtrol()
{

}

CColorListCtrol::~CColorListCtrol()
{
}


BEGIN_MESSAGE_MAP(CColorListCtrol, CListCtrl)
END_MESSAGE_MAP()



// CColorListCtrol message handlers




void CColorListCtrol::PreSubclassWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	CHeaderCtrl* pHeader = NULL;
	pHeader = GetHeaderCtrl();
	if (pHeader != NULL)
	{
		VERIFY(m_HeaderCtrl.SubclassWindow(pHeader->m_hWnd)); // m_HeaderCtrl is the new wrapper object
	}

	CListCtrl::PreSubclassWindow();
}
