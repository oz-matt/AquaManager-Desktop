
// AquaManager-V2.2View.cpp : implementation of the CAquaManagerV22View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "AquaManager-V2.2.h"
#endif

#include "AquaManager-V2.2Doc.h"
#include "AquaManager-V2.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAquaManagerV22View

IMPLEMENT_DYNCREATE(CAquaManagerV22View, CHtmlView)

BEGIN_MESSAGE_MAP(CAquaManagerV22View, CHtmlView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CAquaManagerV22View construction/destruction

CAquaManagerV22View::CAquaManagerV22View()
{
	// TODO: add construction code here

}

CAquaManagerV22View::~CAquaManagerV22View()
{
}

BOOL CAquaManagerV22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

void CAquaManagerV22View::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://www.msdn.microsoft.com/visualc/"),NULL,NULL);
}

void CAquaManagerV22View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CAquaManagerV22View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CAquaManagerV22View diagnostics

#ifdef _DEBUG
void CAquaManagerV22View::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CAquaManagerV22View::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CAquaManagerV22Doc* CAquaManagerV22View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAquaManagerV22Doc)));
	return (CAquaManagerV22Doc*)m_pDocument;
}
#endif //_DEBUG


// CAquaManagerV22View message handlers
