// TV_EstPage.cpp : implementation file
//

#include "stdafx.h"
#include "DynaDialog.h"
#include "EstDemoDoc.h"
#include "EstDemo.h"
#include "ResizingPropSheet.h"
#include "DV_Est.h"
#include "TV_EstPage.h"
#include "TV_CatPage.h"

#include "TV_Sheet.h"
#include "MainFrm.h"
#include "DV_Est.h"
#include "DV_Group.h"
#include "DV_Item.h"
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
// CTV_EstPage property page

//IMPLEMENT_DYNCREATE(CTV_EstPage, CPropertyPage)

CTV_EstPage::CTV_EstPage(LONG* pPaneType, CSplitterWnd** ppSplitter) 
	: CPropertyPage(CTV_EstPage::IDD), 
	m_pPaneType(pPaneType),
	m_ppSplitter(ppSplitter)
{
	//{{AFX_DATA_INIT(CTV_EstPage)
	//}}AFX_DATA_INIT

	m_imageList.Create (IDB_TREELIST, 16, 0, RGB(0,0,255));
}

CTV_EstPage::~CTV_EstPage()
{
}

void CTV_EstPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTV_EstPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTV_EstPage, CPropertyPage)
	//{{AFX_MSG_MAP(CTV_EstPage)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnSelchanged)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTV_EstPage message handlers

// -------------------- CTV_EstPage ----------------------------------

// --- OnSize() -----------------------------------------------------
// 
void CTV_EstPage::OnSize(UINT nType, int cx, int cy) 
{
#if SHEET_DEBUG > 0
	TRACE("CTV_EstPage::OnSize(cx:%d, cy:%d)\n", cx, cy);
#endif

	CPropertyPage::OnSize(nType, cx, cy);
	
	RECT rc;
	GetWindowRect (&rc);     
	ScreenToClient (&rc);     

	CWnd* pWnd = GetDlgItem(IDC_TREE1);
	if (pWnd)
		pWnd->MoveWindow (&rc);
	else
		TRACE("CTV_EstPage::OnSize(): pWnd = NULL\n");
}


// --- OnPaint() ----------------------------------------------------
// 
void CTV_EstPage::OnPaint( )
{
#if SHEET_DEBUG > 0
	TRACE("CTV_EstPage::OnPaint()\n");
#endif

//	Init();
	CPropertyPage::OnPaint();
}




// --- Init() -------------------------------------------------------
// 

static HTREEITEM  AddItem (CTreeCtrl* pTree, HTREEITEM h0, CString cs, int iDat)
	{
	HTREEITEM h1 = pTree->InsertItem(cs, 0, 1, h0, TVI_LAST);
	if (h1)
		pTree->SetItemData(h1, iDat);
	return h1;
	}

void CTV_EstPage::Init()
{
	if (!m_hWnd)
		return;
	CTreeCtrl* pTree = (CTreeCtrl*) GetDlgItem(IDC_TREE1);
	if (!pTree)
		return;		

	HTREEITEM h0, h1, h2;
	h0 = AddItem (pTree, TVI_ROOT, "Estimate: BRG0013A",	       	1);
	h1 = AddItem (pTree, h0,       "Group 0001 General Excavation",2);

	h2 = AddItem (pTree, h1, "201-00000 Clear and Grub",  3);

	AddItem (pTree, h2, "Cost Sheet 2100678",        4);
	AddItem (pTree, h2, "Ref Price 201-00000",       5);
	AddItem (pTree, h2, "Bid Average 201-00000",     6);
	AddItem (pTree, h2, "Bid Regression 201-00000",  7);

	AddItem (pTree, h1, "202-00450 Rem Port Present Str (1)",  3);
	AddItem (pTree, h1, "202-00454 Rem Port Present Str (2A)",  3);
	AddItem (pTree, h1, "202-00456 Rem Port Present Str (2B)",  3);
	AddItem (pTree, h1, "202-00873 Rem Tone Decoder",  3);
	AddItem (pTree, h1, "202-00880 Rem Sig Veh Detector Amp",  3);
	AddItem (pTree, h1, "202-00882 Rem Detector (Magnetic)",  3);
	AddItem (pTree, h1, "202-06530 Clean Drain Pipe (Spec)",  3);
	AddItem (pTree, h1, "202-07000 Oblit Old Road",  3);
	AddItem (pTree, h1, "203-00000 Uncl Excav",  3);
	AddItem (pTree, h1, "203-02310 Scaler Foreman",  3);
	AddItem (pTree, h1, "203-02312 Hand Scaling",  3);
	AddItem (pTree, h1, "203-02315 Mechanized Scaling",  3);
	AddItem (pTree, h1, "208-00020 Silt Fence",  3);
	AddItem (pTree, h1, "208-00030 Sediment Basin",  3);
	AddItem (pTree, h1, "208-00033 Sediment Trap",  3);
	AddItem (pTree, h1, "210-00427 Res Pipe Handrailing",  3);
	AddItem (pTree, h1, "210-00440 Repair Curb",  3);
	AddItem (pTree, h1, "210-00450 Repair Overhead Sign Stru",  3);

	h1 = AddItem (pTree, h0,       "Group 0002 Road Work",2);

	AddItem (pTree, h1, "403-09500 Furnish HBP",  3);
	AddItem (pTree, h1, "403-09600 HBP (Bond Breaker)",  3);
	AddItem (pTree, h1, "403-11121 HBP (Gr C) (Asph) (Rumac) (1% Crm)",  3);
	AddItem (pTree, h1, "403-11123 HBP (Gr C) (Asph) (Rumac) (3% Crm)",  3);
	AddItem (pTree, h1, "403-11320 HBP (Gr C) (Asph) (C 170)",  3);
	AddItem (pTree, h1, "403-11326 HBP (Gr C) (Asph) (P) (C 170)",  3);
	AddItem (pTree, h1, "403-11400 HBP (Gr CX) (C 170)",  3);
	AddItem (pTree, h1, "403-11470 HBP (Gr CX) (Asph) (Spec) (C 170)",  3);
	AddItem (pTree, h1, "403-12300 HBP (Gr C) (C 340)",  3);
	AddItem (pTree, h1, "403-12326 HBP (Gr C) (Asph) (P) (C 340)",  3);
	AddItem (pTree, h1, "403-12370 HBP (Gr C) (Asph) (Spec) (C 340)",  3);


	h1 = AddItem (pTree, h0,       "Group 0003 Bridge Work",2);
	AddItem (pTree, h1, "403-32354 HBP (Gr S) (Asph) (76) (PG 64-22)",  3);
	AddItem (pTree, h1, "403-32400 HBP (Gr SX) (76)",  3);
	AddItem (pTree, h1, "403-32424 HBP (Gr SX) (Asph) (AC-20R)",  3);
	AddItem (pTree, h1, "403-33341 HBP (Gr S) (Asph) (86) (PG 58-40)",  3);
	AddItem (pTree, h1, "403-33342 HBP (Gr S) (Asph) (86) (PG 64-28)",  3);
	AddItem (pTree, h1, "403-33452 HBP (Gr SX) (Asph) (86) (PG 58-28)",  3);
	AddItem (pTree, h1, "403-33453 HBP (Gr SX) (Asph) (86) (PG 58-22)",  3);
	AddItem (pTree, h1, "403-33641 HBP (Gr S-Fines) (Asph) (86) (PG 58-40)",  3);

	h1 = AddItem (pTree, h0,       "Group 0004 Miscellaneous",2);
	AddItem (pTree, h1, "407-04000 Coal-Tar Seal/Rejuvinator (Airport)",  3);
	AddItem (pTree, h1, "407-09000 Crackfiller (Application)",  3);
	AddItem (pTree, h1, "408-01000 Hot Joint-Crack Sealant",  3);
	AddItem (pTree, h1, "408-01400 Crack Sealant (Special)",  3);
	AddItem (pTree, h1, "408-02000 Injection Holes",  3);
	AddItem (pTree, h1, "409-01010 CC Matl (Ty I)",  3);
	AddItem (pTree, h1, "409-01020 CC Matl (Ty I) (Lightweight)",  3);
	AddItem (pTree, h1, "409-02050 CC Matl (Ty II) (Special)",  3);
	AddItem (pTree, h1, "409-04050 CC Matl (Spec)",  3);
}


BOOL CTV_EstPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	Init();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


// --- OnSelchanged() -----------------------------------------------
// 
void CTV_EstPage::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	
	LONG lNewType = (LONG) pNMTreeView->itemNew.lParam;

	SwitchView (lNewType);

	*pResult = 0;
}


// --- SwitchView() -------------------------------------------------
// 
void CTV_EstPage::SwitchView(LONG lNewType)
{
	CMainFrame* pFrmWnd = (CMainFrame*) GetParentFrame();
	if (pFrmWnd == NULL)
		return;

	if ((*m_pPaneType != 1) && (*m_pPaneType != 2) && (*m_pPaneType != 3))
		pFrmWnd->m_wndSplitter.DeleteView(0,1);
	*m_pPaneType = lNewType;

	delete *m_ppSplitter;
	*m_ppSplitter = NULL;

	switch(*m_pPaneType)
	{
	case 1:
		// Estimation ---
		{
			*m_ppSplitter = new CSplitterWnd;
			(*m_ppSplitter)->CreateStatic(&(pFrmWnd->m_wndSplitter), 2, 1, 
											  WS_CHILD | WS_VISIBLE | WS_BORDER,
											  pFrmWnd->m_wndSplitter.IdFromRowCol(0, 1));
			(*m_ppSplitter)->CreateView(0, 0, RUNTIME_CLASS(CDV_Est), CSize(0, 230), NULL);
			(*m_ppSplitter)->CreateView(1, 0, RUNTIME_CLASS(CLV_GroupList), CSize(0, 0), NULL);


			/*--- Add CDV_Sheet to CDV_Est ---*/
			CDV_Est* pEstView = (CDV_Est*)((*m_ppSplitter)->GetPane(0,0));
 			CDV_Sheet *pEstViewSheet = new CDV_Sheet ("Est", pEstView, 0);
			pEstViewSheet->Create(pEstView, WS_CHILD | WS_VISIBLE, 0);

			(*m_ppSplitter)->RecalcLayout();

			/*--- init group list window ---*/
			CLV_GroupList* pList = (CLV_GroupList*) (*m_ppSplitter)->GetPane(1, 0);
			pList->Init();
		}
		break;
	case 2:
		// Group ---
		{
			*m_ppSplitter = new CSplitterWnd;
			(*m_ppSplitter)->CreateStatic(&(pFrmWnd->m_wndSplitter), 2, 1, 
											  WS_CHILD | WS_VISIBLE | WS_BORDER,
											  pFrmWnd->m_wndSplitter.IdFromRowCol(0, 1));
			(*m_ppSplitter)->CreateView(0, 0, RUNTIME_CLASS(CDV_Group), CSize(0, 110), NULL);
			(*m_ppSplitter)->CreateView(1, 0, RUNTIME_CLASS(CLV_ItemList), CSize(0, 0), NULL);

			(*m_ppSplitter)->RecalcLayout();

			CLV_ItemList* pList = (CLV_ItemList*) (*m_ppSplitter)->GetPane(1, 0);
			pList->Init();
		}
		break;
	case 3:
		// Item ---
		{
			*m_ppSplitter = new CSplitterWnd;
			(*m_ppSplitter)->CreateStatic(&(pFrmWnd->m_wndSplitter), 2, 1, 
											  WS_CHILD | WS_VISIBLE | WS_BORDER,
											  pFrmWnd->m_wndSplitter.IdFromRowCol(0, 1));
			(*m_ppSplitter)->CreateView(0, 0, RUNTIME_CLASS(CDV_Item), CSize(0, 195), NULL);
			(*m_ppSplitter)->CreateView(1, 0, RUNTIME_CLASS(CLV_CostList), CSize(0, 0), NULL);

			(*m_ppSplitter)->RecalcLayout();

			CLV_CostList* pList = (CLV_CostList*) (*m_ppSplitter)->GetPane(1, 0);
			pList->Init();
		}
		break;
	case 4:
		// Cost sheet ---
		pFrmWnd->m_wndSplitter.CreateView (0, 1, RUNTIME_CLASS(CDV_Blank), CSize(0, 0), NULL);
		break;
	default:
		pFrmWnd->m_wndSplitter.CreateView (0, 1, RUNTIME_CLASS(CDV_Blank), CSize(0, 0), NULL);
	}

	// TODO: first call to RecalcLayout disturbs size of tree. 
	static BOOL bFirst = TRUE;
	if (bFirst)
		bFirst = FALSE;
	else
		pFrmWnd->m_wndSplitter.RecalcLayout();
}



