// DV_EstPage1.cpp : implementation file
//

#include "stdafx.h"
#include "estdemo.h"
#include "DynaDialog.h"
#include "EstDemoDoc.h"
#include "DV_EstPage1.h"
#include "DV_Sheet.h"
#include "DV_Est.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDV_EstPage1 property page

IMPLEMENT_DYNCREATE(CDV_EstPage1, CDynaPropPage)

BEGIN_MESSAGE_MAP(CDV_EstPage1, CDynaPropPage)
	//{{AFX_MSG_MAP(CDV_EstPage1)
	ON_EN_KILLFOCUS(IDC_ESTIMATE_ID			 , OnKillFocusSetData)
	ON_EN_KILLFOCUS(IDC_ESTIMATE_NAME		 , OnKillFocusSetData)
	ON_EN_KILLFOCUS(IDC_ESTIMATE_DESCRIPTION, OnKillFocusSetData)
	ON_EN_KILLFOCUS(IDC_ESTIMATE_WORKTYPE	 , OnKillFocusSetData)
	ON_EN_KILLFOCUS(IDC_ESTIMATE_HIGHWAYTYPE, OnKillFocusSetData)
	ON_EN_KILLFOCUS(IDC_ESTIMATE_COUNTY		 , OnKillFocusSetData)
	ON_EN_KILLFOCUS(IDC_ESTIMATE_COST		 , OnKillFocusSetData)
	ON_EN_KILLFOCUS(IDC_ESTIMATE_CONTINGENCY, OnKillFocusSetData)
	ON_EN_KILLFOCUS(IDC_ESTIMATE_TOTAL		 , OnKillFocusSetData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CDV_EstPage1::CDV_EstPage1() : CDynaPropPage(CDV_EstPage1::IDD)
{
	//{{AFX_DATA_INIT(CDV_EstPage1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDV_EstPage1::~CDV_EstPage1()
{
}

void CDV_EstPage1::DoDataExchange(CDataExchange* pDX)
{
	CDynaPropPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDV_EstPage1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDV_EstPage1 message handlers

CString sTmpBuff;

CString NumStr (double f)
	{
	sTmpBuff.Format ("%lf", f);
	return sTmpBuff;
	}

CEstimate *CDV_EstPage1::GetEstimate() 
	{
//	CView *cView = (CView *)(GetParent()->GetParent());
//	CEstDemoDoc *pDocument = (CEstDemoDoc *)cView->GetDocument();

	if (!m_hWnd)
		return NULL;

	CDV_Sheet 	*pSheet		= (CDV_Sheet *)	GetParent();
	CDV_Est	 	*pEst			= (CDV_Est	 *)	pSheet->GetParent();
	CEstDemoDoc *pDocument 	= (CEstDemoDoc *)	pEst->GetDocument();

	if (!pDocument)
		return NULL;
	CEstimate *pEstimate = pDocument->m_pEstimate;
	return pEstimate;
	}


BOOL CDV_EstPage1::OnInitDialog() 
	{
	CDynaPropPage::OnInitDialog();

	/*--- Populate Controls ---*/
	CEstimate *pEst = GetEstimate();
	if (!pEst)
		return TRUE;

	GetDlgItem (IDC_ESTIMATE_ID			)->SetWindowText (pEst->m_sEstimateID  );
	GetDlgItem (IDC_ESTIMATE_NAME			)->SetWindowText (pEst->m_sEstimateName);
	GetDlgItem (IDC_ESTIMATE_DESCRIPTION)->SetWindowText (pEst->m_sDescription );
	GetDlgItem (IDC_ESTIMATE_WORKTYPE	)->SetWindowText (pEst->m_sWorkType    );
	GetDlgItem (IDC_ESTIMATE_HIGHWAYTYPE)->SetWindowText (pEst->m_sHighwayType );
	GetDlgItem (IDC_ESTIMATE_COUNTY		)->SetWindowText (pEst->m_sCounty      );
	GetDlgItem (IDC_ESTIMATE_COST			)->SetWindowText (NumStr(pEst->m_fEstimateCost));
	GetDlgItem (IDC_ESTIMATE_CONTINGENCY)->SetWindowText (NumStr(pEst->m_fContingency ));
	GetDlgItem (IDC_ESTIMATE_TOTAL		)->SetWindowText (NumStr(pEst->m_fTotal       ));
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
	}

void CDV_EstPage1::OnKillFocusSetData() 
	{
	CEstimate *pEst = GetEstimate();
	if (!pEst)
		return;

	CString s;
	GetDlgItem (IDC_ESTIMATE_ID			)->GetWindowText (pEst->m_sEstimateID  );
	GetDlgItem (IDC_ESTIMATE_NAME			)->GetWindowText (pEst->m_sEstimateName);
	GetDlgItem (IDC_ESTIMATE_DESCRIPTION)->GetWindowText (pEst->m_sDescription );
	GetDlgItem (IDC_ESTIMATE_WORKTYPE	)->GetWindowText (pEst->m_sWorkType    );
	GetDlgItem (IDC_ESTIMATE_HIGHWAYTYPE)->GetWindowText (pEst->m_sHighwayType );
	GetDlgItem (IDC_ESTIMATE_COUNTY		)->GetWindowText (pEst->m_sCounty      );
	GetDlgItem (IDC_ESTIMATE_COST			)->GetWindowText (s); pEst->m_fEstimateCost = atof(s);
	GetDlgItem (IDC_ESTIMATE_CONTINGENCY)->GetWindowText (s); pEst->m_fContingency  = atof(s);
	GetDlgItem (IDC_ESTIMATE_TOTAL		)->GetWindowText (s); pEst->m_fTotal        = atof(s);
	}
