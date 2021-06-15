// DV_Est.cpp : implementation file
//

#include "stdafx.h"
#include "estdemo.h"
#include "DynaDialog.h"
#include "EstDemoDoc.h"
#include "DV_Est.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDV_Est

IMPLEMENT_DYNCREATE(CDV_Est, CView)

CDV_Est::CDV_Est()
{
}

CDV_Est::~CDV_Est()
{
}


BEGIN_MESSAGE_MAP(CDV_Est, CView)
	//{{AFX_MSG_MAP(CDV_Est)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDV_Est drawing

void CDV_Est::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CDV_Est diagnostics

#ifdef _DEBUG
void CDV_Est::AssertValid() const
{
	CView::AssertValid();
}

void CDV_Est::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDV_Est message handlers

void CDV_Est::OnSize(UINT nType, int cx, int cy) 
	{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here

	CWnd* pWnd = GetWindow(GW_CHILD);
	if (pWnd)
		{
		CDV_Sheet* pSheet = (CDV_Sheet*) pWnd;
		pSheet->ResizeSheet (CRect(0, 0, cx, cy));
		}
	}
