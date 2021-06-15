// DV_EstPage2.cpp : implementation file
//

#include "stdafx.h"
#include "estdemo.h"
#include "DynaDialog.h"
#include "DV_EstPage2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDV_EstPage2 property page

IMPLEMENT_DYNCREATE(CDV_EstPage2, CDynaPropPage)

CDV_EstPage2::CDV_EstPage2() : CDynaPropPage(CDV_EstPage2::IDD)
{
	//{{AFX_DATA_INIT(CDV_EstPage2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDV_EstPage2::~CDV_EstPage2()
{
}

void CDV_EstPage2::DoDataExchange(CDataExchange* pDX)
{
	CDynaPropPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDV_EstPage2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDV_EstPage2, CDynaPropPage)
	//{{AFX_MSG_MAP(CDV_EstPage2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDV_EstPage2 message handlers
