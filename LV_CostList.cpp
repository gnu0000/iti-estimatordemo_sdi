// LV_CostList.cpp : implementation file
//

#include "stdafx.h"
#include "EstDemo.h"
#include "LV_CostList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLV_CostList

IMPLEMENT_DYNCREATE(CLV_CostList, CView)

CLV_CostList::CLV_CostList()
{
}

CLV_CostList::~CLV_CostList()
{
}


BEGIN_MESSAGE_MAP(CLV_CostList, CView)
	//{{AFX_MSG_MAP(CLV_CostList)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLV_CostList drawing

void CLV_CostList::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CLV_CostList diagnostics

#ifdef _DEBUG
void CLV_CostList::AssertValid() const
{
	CView::AssertValid();
}

void CLV_CostList::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

// ------------------------------------------------------------------

// --- Init() -------------------------------------------------------
// 
void CLV_CostList::Init()
{
	m_grid.CreateGrid(WS_CHILD|WS_VISIBLE, CRect(0,0,0,0), this, 0);

  	// setup headings layout
	m_grid.SetNumberCols (3);
	m_grid.SetSH_Width (0);
//	m_grid.SetTH_Height(20);

	m_grid.SetVScrollMode (UG_SCROLLTRACKING);
	m_grid.SetHScrollMode (UG_SCROLLTRACKING);

	m_grid.QuickSetText(0, -1, "Price ID");
	m_grid.QuickSetText(1, -1, "Price Type");
	m_grid.QuickSetText(2, -1, "Total");
}


// --- OnSize() -----------------------------------------------------
// 
void CLV_CostList::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	if (m_grid.m_hWnd != NULL)
	{
		m_grid.MoveWindow(0, 0, cx, cy);
		m_grid.SetColWidth (0, 6);
		m_grid.SetColWidth (1, 12);
		m_grid.SetColWidth (2, 12);
		m_grid.FitToWindow (0, 2);
	}
}


