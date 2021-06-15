// DynaDialog.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "DynaDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////

CDynaInfo::CDynaInfo ()
	{
	m_bInitialized = FALSE;
	}

CDynaInfo::~CDynaInfo ()
	{
	// free the map
	}


BOOL CDynaInfo::Init (CDialog *pDlg)
	{
	CWnd  *pDynaAreas[4];
	CRect cDynaRect[4], rAll, rCtl, rTmp;

	if (m_bInitialized)
		return TRUE;
	if (!pDlg || !pDlg->m_hWnd || !pDlg->GetWindow (GW_CHILD))
		return FALSE;

	for (int i=0; i<4; i++)
		{
		int iID =(i==0 ? IDC_MR :(i==1 ? IDC_SR :(i==2 ? IDC_MB : IDC_SB)));
		if (pDynaAreas[i] = pDlg->GetDlgItem (iID))
			pDynaAreas[i]->GetWindowRect (cDynaRect[i]);
		}

	/*--- define boundry of all the controls ---*/
	CWnd *pChild;
	for (pChild=pDlg->GetWindow (GW_CHILD); pChild; pChild=pChild->GetWindow (GW_HWNDNEXT))
		{
		pChild->GetWindowRect (rCtl);
		rAll |= rCtl;
		}
	pDlg->ScreenToClient (rAll);
	rAll.InflateRect (0, 0, rAll.left, rAll.top);

	/*--- save the original positions of moveable ctls ---*/
	int iDynaType;
	for (pChild=pDlg->GetWindow (GW_CHILD); pChild; pChild=pChild->GetWindow (GW_HWNDNEXT))
		{
		pChild->GetWindowRect (rCtl);
		iDynaType = 0;
	 	for (int i=0; i<4; i++)
			if (rTmp.IntersectRect (rCtl, cDynaRect[i]))
				iDynaType |= (i==0 ? DT_MOVER :(i==1 ? DT_SIZER :(i==2 ? DT_MOVEB : DT_SIZEB)));
		if (!iDynaType)
			continue;

		pDlg->ScreenToClient (rCtl);
		CCtlInfo *pCtlInfo = new CCtlInfo ();
		pCtlInfo->iDynaType = iDynaType;
		pCtlInfo->iXGap     = rAll.right-rCtl.right;
		pCtlInfo->iXMinPos  = rCtl.right;
		pCtlInfo->iYGap     = rAll.bottom-rCtl.bottom;
		pCtlInfo->iYMinPos  = rCtl.bottom;
		m_mapCtlInfo [pChild->m_hWnd] = pCtlInfo;
		}
	return m_bInitialized = TRUE;
	}


void CDynaInfo::Size (CDialog *pDlg)
	{
	CCtlInfo *pCtlInfo;
	CRect rCtl, rClient;

	if (!Init (pDlg))
		return;
	pDlg->GetClientRect (rClient);
	CWnd *pChild;
	for (pChild=pDlg->GetWindow (GW_CHILD); pChild; pChild=pChild->GetWindow (GW_HWNDNEXT))
		{
		if (!m_mapCtlInfo.Lookup (pChild->m_hWnd, pCtlInfo))
			continue;
		pChild->GetWindowRect (rCtl);
		pDlg->ScreenToClient (rCtl);
		pDlg->InvalidateRect (rCtl);
		if (pCtlInfo->iDynaType & DT_MOVER)
			rCtl += CPoint (max (pCtlInfo->iXMinPos, rClient.right - pCtlInfo->iXGap) - rCtl.right, 0);
		if (pCtlInfo->iDynaType & DT_SIZER)
			rCtl.right = max (pCtlInfo->iXMinPos, rClient.right - pCtlInfo->iXGap);
		if (pCtlInfo->iDynaType & DT_MOVEB)
			rCtl += CPoint (0, max (pCtlInfo->iYMinPos, rClient.bottom - pCtlInfo->iYGap) - rCtl.bottom);
		if (pCtlInfo->iDynaType & DT_SIZEB)
			rCtl.bottom = max (pCtlInfo->iYMinPos, rClient.bottom - pCtlInfo->iYGap);

		pChild->MoveWindow (rCtl);
		}
	}

/////////////////////////////////////////////////////////////////////////////
// CDynaDialog dialog

BEGIN_MESSAGE_MAP(CDynaDialog, CDialog)
	//{{AFX_MSG_MAP(CDynaDialog)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CDynaDialog::CDynaDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CDynaDialog::IDD, pParent)
	{
	//{{AFX_DATA_INIT(CDynaDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	}

// todo: what is the correct way to do this???
CDynaDialog::CDynaDialog(CWnd* pParent /*=NULL*/, UINT nIDTemplate)
	: CDialog(nIDTemplate, pParent)
	{
	}

void CDynaDialog::DoDataExchange(CDataExchange* pDX)
	{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDynaDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	}

void CDynaDialog::Size() 
	{
	m_cDynaInfo.Size (this);
	}


/////////////////////////////////////////////////////////////////////////////
// CDynaFormView

IMPLEMENT_DYNCREATE(CDynaFormView, CFormView)

BEGIN_MESSAGE_MAP(CDynaFormView, CFormView)
	//{{AFX_MSG_MAP(CDynaFormView)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



CDynaFormView::CDynaFormView()
	: CFormView((UINT)0)
	{
	//{{AFX_DATA_INIT(CDynaFormView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	}

CDynaFormView::CDynaFormView(UINT nIDTemplate)
	: CFormView(nIDTemplate)
	{
	}

CDynaFormView::~CDynaFormView()
	{
	}

void CDynaFormView::DoDataExchange(CDataExchange* pDX)
	{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDynaFormView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	}

#ifdef _DEBUG
void CDynaFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDynaFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

#define DYNA_

void CDynaFormView::OnInitialUpdate() 
	{
	CFormView::OnInitialUpdate();
//	m_cDynaInfo.Init ((CDialog *)this);
	}

void CDynaFormView::OnSize(UINT nType, int cx, int cy) 
	{
	CFormView::OnSize(nType, cx, cy);
	m_cDynaInfo.Size ((CDialog *)this);
	}


/////////////////////////////////////////////////////////////////////////////
// CDynaPropPage property page

IMPLEMENT_DYNCREATE(CDynaPropPage, CPropertyPage)

BEGIN_MESSAGE_MAP(CDynaPropPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDynaPropPage)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CDynaPropPage::CDynaPropPage() : CPropertyPage(CDynaPropPage::IDD)
	{
	//{{AFX_DATA_INIT(CDynaPropPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	}

CDynaPropPage::CDynaPropPage(UINT nIDTemplate) : CPropertyPage(nIDTemplate)
	{
	}


CDynaPropPage::~CDynaPropPage()
	{
	}

void CDynaPropPage::DoDataExchange(CDataExchange* pDX)
	{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDynaPropPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	}

BOOL CDynaPropPage::OnInitDialog() 
	{
	CPropertyPage::OnInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
	}

void CDynaPropPage::OnSize(UINT nType, int cx, int cy) 
	{
	CPropertyPage::OnSize(nType, cx, cy);
	m_cDynaInfo.Size (this);
	}
