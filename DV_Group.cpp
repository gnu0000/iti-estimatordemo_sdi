// DV_Group.cpp : implementation file
//

#include "stdafx.h"
#include "EstDemo.h"
#include "DynaDialog.h"
#include "DV_Group.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDV_Group

IMPLEMENT_DYNCREATE(CDV_Group, CDynaFormView)

CDV_Group::CDV_Group()
	: CDynaFormView(CDV_Group::IDD)
{
	//{{AFX_DATA_INIT(CDV_Group)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDV_Group::~CDV_Group()
{
}

void CDV_Group::DoDataExchange(CDataExchange* pDX)
{
	CDynaFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDV_Group)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDV_Group, CDynaFormView)
	//{{AFX_MSG_MAP(CDV_Group)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDV_Group diagnostics

#ifdef _DEBUG
void CDV_Group::AssertValid() const
{
	CDynaFormView::AssertValid();
}

void CDV_Group::Dump(CDumpContext& dc) const
{
	CDynaFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDV_Group message handlers

void CDV_Group::OnInitialUpdate() 
{
	CDynaFormView::OnInitialUpdate();
/***
	if (m_itemGrid.m_hWnd == 0)
		m_itemGrid.AttachGrid (this, IDC_ITEM_GRID);

  	// setup headings layout
	m_itemGrid.SetNumberCols (4);
	m_itemGrid.SetColWidth (0, 70);
	m_itemGrid.SetColWidth (1, 150);
	m_itemGrid.SetColWidth (2, 80);
	m_itemGrid.SetColWidth (3, 80);
	m_itemGrid.SetSH_Width (0);
//	m_itemGrid.SetTH_NumberRows (0);
//	m_itemGrid.SetTH_Height(20);

	m_itemGrid.SetVScrollMode (UG_SCROLLTRACKING);
	m_itemGrid.SetHScrollMode (UG_SCROLLTRACKING);

	m_itemGrid.QuickSetText(0, -1, "Quantity");
	m_itemGrid.QuickSetText(1, -1, "Name");
	m_itemGrid.QuickSetText(2, -1, "Price");
	m_itemGrid.QuickSetText(3, -1, "Extension");
***/	
}
