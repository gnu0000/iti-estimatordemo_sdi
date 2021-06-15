// DV_Blank.cpp : implementation file
//

#include "stdafx.h"
#include "EstDemo.h"
#include "DV_Blank.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDV_Blank

IMPLEMENT_DYNCREATE(CDV_Blank, CFormView)

CDV_Blank::CDV_Blank()
	: CFormView(CDV_Blank::IDD)
{
	//{{AFX_DATA_INIT(CDV_Blank)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDV_Blank::~CDV_Blank()
{
}

void CDV_Blank::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDV_Blank)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDV_Blank, CFormView)
	//{{AFX_MSG_MAP(CDV_Blank)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDV_Blank diagnostics

#ifdef _DEBUG
void CDV_Blank::AssertValid() const
{
	CFormView::AssertValid();
}

void CDV_Blank::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDV_Blank message handlers

