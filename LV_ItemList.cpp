// LV_ItemList.cpp : implementation file
//

#include "stdafx.h"
#include "EstDemo.h"
#include "LV_ItemList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLV_ItemList

IMPLEMENT_DYNCREATE(CLV_ItemList, CView)

CLV_ItemList::CLV_ItemList()
{
}

CLV_ItemList::~CLV_ItemList()
{
}


BEGIN_MESSAGE_MAP(CLV_ItemList, CView)
	//{{AFX_MSG_MAP(CLV_ItemList)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLV_ItemList drawing

void CLV_ItemList::OnDraw(CDC* pDC)
{
//	CDocument* pDoc = GetDocument();
}

/////////////////////////////////////////////////////////////////////////////
// CLV_ItemList diagnostics

#ifdef _DEBUG
void CLV_ItemList::AssertValid() const
{
	CView::AssertValid();
}

void CLV_ItemList::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG



// ------------------------------------------------------------------

void CLV_ItemList::Init()
{
	m_grid.CreateGrid(WS_CHILD|WS_VISIBLE, CRect(0,0,0,0), this, 0);

  	// setup headings layout
	m_grid.SetNumberCols (7);
	m_grid.SetSH_Width (0);
//	m_grid.SetTH_Height(20);

	m_grid.SetVScrollMode (UG_SCROLLTRACKING);
	m_grid.SetHScrollMode (UG_SCROLLTRACKING);

	m_grid.QuickSetText(0, -1, "Line #");
	m_grid.QuickSetText(1, -1, "Item #");
	m_grid.QuickSetText(2, -1, "Quantity");
	m_grid.QuickSetText(3, -1, "Unit");
	m_grid.QuickSetText(4, -1, "Unit Price");
	m_grid.QuickSetText(5, -1, "Extension");
	m_grid.QuickSetText(6, -1, "Descripton");
}

void CLV_ItemList::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);

	if (!m_grid.m_hWnd)
		return;

	CDC* pDC = GetDC( );
	TEXTMETRIC tmMetric;
	pDC->GetTextMetrics (&tmMetric);
	ReleaseDC (pDC); //GNX
	int iCWidth = tmMetric.tmAveCharWidth;

	m_grid.MoveWindow(0, 0, cx, cy);
	m_grid.SetColWidth (0, iCWidth * 6 );	 // Line #
	m_grid.SetColWidth (1, iCWidth * 13);	 // Item #
	m_grid.SetColWidth (2, iCWidth * 16);	 // Quantity
	m_grid.SetColWidth (3, iCWidth * 5 );	 // Unit
	m_grid.SetColWidth (4, iCWidth * 16);	 // Unit Price
	m_grid.SetColWidth (5, iCWidth * 16);	 // Extension
	m_grid.SetColWidth (6, iCWidth * 40);	 // Descripton

//	if (!m_grid.GetLeftCol() && cx > iCWidth*72)
//		m_grid.FitToWindow (0, 5);

}
