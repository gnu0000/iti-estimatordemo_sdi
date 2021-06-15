// DV_Item.cpp : implementation file
//

#include "stdafx.h"
#include "EstDemo.h"
#include "DynaDialog.h"
#include "DV_Item.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDV_Item dialog

IMPLEMENT_DYNCREATE(CDV_Item, CDynaFormView)

CDV_Item::CDV_Item()
	: CDynaFormView(CDV_Item::IDD)
{
	//{{AFX_DATA_INIT(CDV_Item)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDV_Item::DoDataExchange(CDataExchange* pDX)
{
	CDynaFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDV_Item)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDV_Item, CDynaFormView)
	//{{AFX_MSG_MAP(CDV_Item)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDV_Item message handlers
