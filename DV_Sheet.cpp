// DV_Sheet.cpp : implementation file
//

#include "stdafx.h"
#include "estdemo.h"
#include "DynaDialog.h"
#include "EstDemoDoc.h"
#include "DV_Sheet.h"
#include "DV_Est.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDV_Sheet

IMPLEMENT_DYNAMIC(CDV_Sheet, CResizingPropSheet)

CDV_Sheet::CDV_Sheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CResizingPropSheet(nIDCaption, pParentWnd, iSelectPage)
{
Init ();
}

CDV_Sheet::CDV_Sheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CResizingPropSheet(pszCaption, pParentWnd, iSelectPage)
{
Init ();
}

CDV_Sheet::~CDV_Sheet()
{
}


BEGIN_MESSAGE_MAP(CDV_Sheet, CResizingPropSheet)
	//{{AFX_MSG_MAP(CDV_Sheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDV_Sheet message handlers


BOOL CDV_Sheet::OnInitDialog() 
	{
	CWnd* pWnd = GetDlgItem(AFX_IDC_TAB_CONTROL);
	if (pWnd)
		pWnd->ModifyStyle(0, TCS_BOTTOM);

	BOOL bResult = CResizingPropSheet::OnInitDialog();

//	CDV_Est *pcParent = (CDV_Est *)GetParent ();
//	m_pDocument = (CEstDemoDoc *)pcParent->GetDocument ();
	
	return bResult;
	}



// --- Init() -------------------------------------------------------
// 
void CDV_Sheet::Init()
	{
	AddPage(&m_cPage1);
	AddPage(&m_cPage2);
	AddPage(&m_cPage3);
	}

