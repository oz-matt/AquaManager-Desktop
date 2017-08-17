
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

#include "Geofence.h"

extern CGeofence *CGeofence_Instance;

CComQIPtr<IHTMLDocument2> pDoc;

// CAquaManagerV22View

IMPLEMENT_DYNCREATE(CAquaManagerV22View, CHtmlView)

BEGIN_MESSAGE_MAP(CAquaManagerV22View, CHtmlView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
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

	Init();

	pDoc = (IHTMLDocument2*)GetHtmlDocument();
	//(CAquaManagerV22Doc*)m_pDocument;

	//SetTimer(1, 1000, NULL);
	//CGeofence_Instance->SaveGeoObject();
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


// Init Google Map


void CAquaManagerV22View::Init(void)
{
	// Read full path
	char szCurDir[MAX_PATH];
	memset(szCurDir, 0, sizeof(szCurDir));
	DWORD length = sizeof(szCurDir);
	GetModuleFileName(NULL, szCurDir, length);

	// Remove APP name from full path
	CString app;
	app.Format("%s", szCurDir);
	int end = app.ReverseFind('\\');
	app = app.Left(end);

	// Get Google Map template
	CString res;
	res.Format("%s", app);
	end = res.ReverseFind('\\');
	res = res.Left(end);
	CString sPath;
	sPath.Format(_T("%s\\%s"), res, "AquaManager-V2.2\\res\\google_map.html");
	//sPath.Format(_T("res://%s//%d"), szCurDir, IDR_HTML1);

	Navigate2(_T(sPath), NULL, NULL);
}


void CAquaManagerV22View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CGeofence_Instance->SaveGeoObject();

	CHtmlView::OnTimer(nIDEvent);
}


//HRESULT CAquaManagerV22View::accNavigate(long navDir, VARIANT varStart, VARIANT *pvarEndUpAt)
//{
//	// TODO: Add your specialized code here and/or call the base class
//
//	return CHtmlView::accNavigate(navDir, varStart, pvarEndUpAt);
//}


void CAquaManagerV22View::OnDocumentComplete(LPCTSTR lpszURL)
{
	// TODO: Add your specialized code here and/or call the base class
	CGeofence_Instance->SaveGeoObject();

	CHtmlView::OnDocumentComplete(lpszURL);
}
