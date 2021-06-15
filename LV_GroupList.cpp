// LV_GroupList.cpp : implementation file
//

#include "stdafx.h"
#include "LV_GroupList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



IMPLEMENT_DYNCREATE(CLV_GroupList, CView)


/////////////////////////////////////////////////////////////////////////////
// CLV_GroupList

CLV_GroupList::CLV_GroupList()
{
}

CLV_GroupList::~CLV_GroupList()
{
}


BEGIN_MESSAGE_MAP(CLV_GroupList, CWnd)
	//{{AFX_MSG_MAP(CLV_GroupList)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// ------------------------------------------------------------------

// --- Init() -------------------------------------------------------
// 
void CLV_GroupList::Init()
{

	m_grid.CreateGrid(WS_CHILD|WS_VISIBLE, CRect(0,0,0,0), this, 0);

  	// setup headings layout
	m_grid.SetNumberCols (3);
	m_grid.SetSH_Width (0);
//	m_grid.SetTH_Height(20);

	m_grid.SetVScrollMode (UG_SCROLLTRACKING);
	m_grid.SetHScrollMode (UG_SCROLLTRACKING);
	m_grid.QuickSetText(0, -1, "Group ID");
	m_grid.QuickSetText(1, -1, "Group Name");
	m_grid.QuickSetText(2, -1, "Group Total");
   m_grid.FitToWindow (0, 2);

}



// --- OnSize() -----------------------------------------------------
// 
void CLV_GroupList::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	
	if (m_grid.m_hWnd != NULL)
	{
		m_grid.MoveWindow(0, 0, cx, cy);
		m_grid.SetColWidth (0, 4);
		m_grid.SetColWidth (1, 12);
		m_grid.SetColWidth (2, 6);
		m_grid.FitToWindow (0, 2);
	}
}
