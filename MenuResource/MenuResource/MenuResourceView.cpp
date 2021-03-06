
// MenuResourceView.cpp : implementation of the CMenuResourceView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MenuResource.h"
#endif

#include "MenuResourceDoc.h"
#include "MenuResourceView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMenuResourceView

IMPLEMENT_DYNCREATE(CMenuResourceView, CView)

BEGIN_MESSAGE_MAP(CMenuResourceView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMenuResourceView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMenuResourceView construction/destruction

CMenuResourceView::CMenuResourceView() noexcept
{
	// TODO: add construction code here

}

CMenuResourceView::~CMenuResourceView()
{
}

BOOL CMenuResourceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMenuResourceView drawing

void CMenuResourceView::OnDraw(CDC* /*pDC*/)
{
	CMenuResourceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMenuResourceView printing


void CMenuResourceView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMenuResourceView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMenuResourceView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMenuResourceView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

//void CMenuResourceView::OnRButtonUp(UINT /* nFlags */, CPoint point)
//{
//	ClientToScreen(&point);
//	OnContextMenu(this, point);
//}

void CMenuResourceView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMenuResourceView diagnostics

#ifdef _DEBUG
void CMenuResourceView::AssertValid() const
{
	CView::AssertValid();
}

void CMenuResourceView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenuResourceDoc* CMenuResourceView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenuResourceDoc)));
	return (CMenuResourceDoc*)m_pDocument;
}
#endif //_DEBUG


// CMenuResourceView message handlers


void CMenuResourceView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMenu menu;
	CMenu *pSubMenu;

	menu.LoadMenu(IDR_POPUP_EDIT);
	pSubMenu = menu.GetSubMenu(0);
	ClientToScreen(&point);
	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);

	CView::OnRButtonDown(nFlags, point);
}
