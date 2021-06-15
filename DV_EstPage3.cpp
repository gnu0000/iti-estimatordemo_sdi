// DV_EstPage3.cpp : implementation file
//

#include "stdafx.h"
#include "estdemo.h"
#include "DynaDialog.h"
#include "DV_EstPage3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDV_EstPage3 property page

IMPLEMENT_DYNCREATE(CDV_EstPage3, CDynaPropPage)

CDV_EstPage3::CDV_EstPage3() : CDynaPropPage(CDV_EstPage3::IDD)
{
	//{{AFX_DATA_INIT(CDV_EstPage3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDV_EstPage3::~CDV_EstPage3()
{
}

void CDV_EstPage3::DoDataExchange(CDataExchange* pDX)
{
	CDynaPropPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDV_EstPage3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDV_EstPage3, CDynaPropPage)
	//{{AFX_MSG_MAP(CDV_EstPage3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDV_EstPage3 message handlers

