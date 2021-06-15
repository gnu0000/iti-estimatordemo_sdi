// SheetParent.cpp : implementation file
//

#include "stdafx.h"
#include "EstDemo.h"
#include "ResizingPropSheet.h"
#include "TV_EstPage.h"
#include "TV_CatPage.h"

#include "TV.h"
#include "TV_Sheet.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTV

IMPLEMENT_DYNCREATE(CTV, CView)

CTV::CTV()
{
}

CTV::~CTV()
{
}


BEGIN_MESSAGE_MAP(CTV, CView)
	//{{AFX_MSG_MAP(CTV)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTV drawing

void CTV::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CTV diagnostics

#ifdef _DEBUG
void CTV::AssertValid() const
{
	CView::AssertValid();
}

void CTV::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTV message handlers

// --- OnSize() -----------------------------------------------------
// 
void CTV::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	CWnd* pWnd = GetWindow(GW_CHILD);
	if (pWnd)
	{
		CTV_Sheet* pSheet = (CTV_Sheet*) pWnd;
		//pSheet->Resize(0, 0, cx, cy);
		pSheet->ResizeSheet (CRect(0, 0, cx, cy));
	}

//for debug
	CDocument *pDoc = GetDocument();
}
