// PropSheet.cpp : implementation file
//

#include "stdafx.h"
#include "DynaDialog.h"
#include "EstDemo.h"
#include "EstDemoDoc.h"
#include "ResizingPropSheet.h"
#include "TV_EstPage.h"
#include "TV_CatPage.h"
#include "TV_Sheet.h"
#include "MainFrm.h"
#include "DV_Est.h"
#include "DV_Group.h"
#include "DV_Blank.h"
#include "LV_GroupList.h"
#include "LV_ItemList.h"
#include "LV_CostList.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define SHEET_DEBUG		0


/////////////////////////////////////////////////////////////////////////////
// CTV_Sheet

IMPLEMENT_DYNAMIC(CTV_Sheet, CResizingPropSheet)

CTV_Sheet::CTV_Sheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:	CResizingPropSheet(nIDCaption, pParentWnd, iSelectPage), 
		m_page1(&m_lPaneType, &m_pSplitter),
		m_page2(&m_lPaneType, &m_pSplitter),
		m_pSplitter(NULL)
{
	Init();
}

CTV_Sheet::CTV_Sheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:	CResizingPropSheet(pszCaption, pParentWnd, iSelectPage),
		m_page1(&m_lPaneType, &m_pSplitter),
		m_page2(&m_lPaneType, &m_pSplitter),
		m_pSplitter(NULL)
{
	Init();
}

CTV_Sheet::~CTV_Sheet()
{
	delete m_pSplitter;
}


BEGIN_MESSAGE_MAP(CTV_Sheet, CResizingPropSheet)
	//{{AFX_MSG_MAP(CTV_Sheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



// ------------------------ CTV_Sheet ------------------------------

// --- OnInitDialog() -----------------------------------------------
// Change style of tab control to display page titles at bottom
//
BOOL CTV_Sheet::OnInitDialog() 
{

	CWnd* pWnd = GetDlgItem(AFX_IDC_TAB_CONTROL);
	if (pWnd)
		pWnd->ModifyStyle(0, TCS_BOTTOM);

	BOOL bResult = CResizingPropSheet::OnInitDialog();

	return bResult;
}


// --- Init() -------------------------------------------------------
// 
void CTV_Sheet::Init()
{
	AddPage(&m_page1);
	AddPage(&m_page2);
}



