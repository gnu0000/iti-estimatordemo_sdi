// ResizingPropSheet.cpp : implementation file
//

#include "stdafx.h"
#include "estdemo.h"
#include "ResizingPropSheet.h"
#include "DynaDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResizingPropSheet

IMPLEMENT_DYNAMIC(CResizingPropSheet, CPropertySheet)


BEGIN_MESSAGE_MAP(CResizingPropSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CResizingPropSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CResizingPropSheet::CResizingPropSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
m_bMetricsStored = FALSE;
}

CResizingPropSheet::CResizingPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
m_bMetricsStored = FALSE;
}

CResizingPropSheet::~CResizingPropSheet()
{
}				

// for debugging
//#define ZZ(p,r) s.Format ("%s [%d:%d:%d:%d]",p,r.left,r.top,r.right,r.bottom); AfxMessageBox (s);

						  
void CResizingPropSheet::ResizeSheet (CRect &rNewSize)
	{
	if (!StoreMetrics())
		return;

	/*--- Resize sheet to fit parent client ---*/	
	MoveWindow (rNewSize);

	/*--- Resize Tab Ctrl ---*/	
	CRect rTab = rNewSize;
	rTab -= m_rTabDelta;
	//rTab.top = rTab.bottom - m_rTabDelta.top; // m_rTabDelta.top is actually the height
	CTabCtrl* pTab = GetTabControl ();
	if (!pTab)
		return;
	pTab->MoveWindow (&rTab);

	/*--- Resize Pages ---*/	
	CRect rPage = rNewSize;
	rPage -= m_rPageDelta;
   int nPageCnt = GetPageCount();
	for (int index = 0 ; index < nPageCnt; index++)
		{
		CDynaPropPage* pPage = (CDynaPropPage*)GetPage(index);
		if (pPage && (pPage->m_hWnd != NULL))
			pPage->MoveWindow (rPage);
		}
	}

/////////////////////////////////////////////////////////////////////////////
// CResizingPropSheet message handlers

BOOL CResizingPropSheet::StoreMetrics()
	{
	if (m_bMetricsStored)
		return TRUE;

	CRect rcSheet;
	GetWindowRect (rcSheet);

	CTabCtrl* pTab = GetTabControl ();
	if (!pTab)
		return FALSE;
	CRect rc;
	pTab->GetWindowRect (&rc);

	m_rTabDelta  =	CRect(rc.left - rcSheet.left,
								rc.top - rcSheet.top,
								rcSheet.right - rc.right,
								rcSheet.bottom - rc.bottom);

   if (!GetPageCount())
		return FALSE;
	CPropertyPage* pPage = GetPage(0);
	if (!pPage || !pPage->m_hWnd)
		return FALSE;
	pPage->GetWindowRect (&rc);

	m_rPageDelta = CRect (rc.left - rcSheet.left,
								 rc.top - rcSheet.top,
								 rcSheet.right - rc.right,
								 rcSheet.bottom - rc.bottom);

	CRect rAdjust (-m_rTabDelta.left,	 // Modify default gap sizes
		            -m_rTabDelta.top,		 // around tabs/pages
					   m_rTabDelta.right,	 // In this case we reduce it
					   m_rTabDelta.bottom);	 // to zero

	m_rTabDelta  -= rAdjust;
	m_rPageDelta -= rAdjust;

	return m_bMetricsStored = TRUE;
	}
