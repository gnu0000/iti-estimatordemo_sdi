// PropSheet.cpp : implementation file
//

#include "stdafx.h"
#include "DynaDialog.h"
#include "EstDemoDoc.h"
#include "EstDemo.h"
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
// CTV_CatPage property page

//IMPLEMENT_DYNCREATE(CTV_CatPage, CPropertyPage)

CTV_CatPage::CTV_CatPage(LONG* pPaneType, CSplitterWnd** ppSplitter)
	:	CPropertyPage(CTV_CatPage::IDD),
		m_pPaneType(pPaneType),
		m_ppSplitter(ppSplitter)
{
	//{{AFX_DATA_INIT(CTV_CatPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_imageList.Create (IDB_TREELIST, 16, 0, RGB(0,0,255));
}

CTV_CatPage::~CTV_CatPage()
{
}

void CTV_CatPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTV_CatPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTV_CatPage, CPropertyPage)
	//{{AFX_MSG_MAP(CTV_CatPage)
	ON_WM_SIZE()
	ON_NOTIFY(TVN_SELCHANGED, IDC_CAT_TREE, OnSelchanged)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTV_CatPage message handlers
// ------------------------- CTV_CatPage -----------------------------


// --- OnSize() -----------------------------------------------------
// 
void CTV_CatPage::OnSize(UINT nType, int cx, int cy) 
{
	CPropertyPage::OnSize(nType, cx, cy);
	
	RECT rc;
	GetWindowRect (&rc);     
	ScreenToClient (&rc);     

	CWnd* pWnd = GetDlgItem(IDC_CAT_TREE);
	if (pWnd)
		pWnd->MoveWindow (&rc);
	else
		TRACE("CTV_CatPage::OnSize(): pWnd = NULL\n");
}

// --- OnSelchanged() -----------------------------------------------
// 
void CTV_CatPage::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	
	LONG lNewType = (LONG) pNMTreeView->itemNew.lParam;

	SwitchView (lNewType);
	
	*pResult = 0;
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


void CTV_CatPage::Init()
{
	if (!m_hWnd)
		return;
	CTreeCtrl* pTree = (CTreeCtrl*) GetDlgItem(IDC_CAT_TREE);
	if (!pTree)
		return;		

	HTREEITEM h0, h1, h2;
	h0 = AddItem (pTree, TVI_ROOT, "Catalog Metric.cat",		10);
	h1 = AddItem (pTree, h0,       "Std Item Catalog",   		11);

	h2 = AddItem (pTree, h1, "000-00005 Design (NFA CDOT)",  20);

	AddItem (pTree, h2, "Cost Sheet 2100678",        4);
	AddItem (pTree, h2, "Ref Price 201-00000",       5);
	AddItem (pTree, h2, "Bid Average 201-00000",     6);
	AddItem (pTree, h2, "Bid Regression 201-00000",  7);

	AddItem (pTree, h1, "000-00010 Design (Fed Aid CDOT)",  20);
	AddItem (pTree, h1, "000-00020 Design (Consultant)",  20);
	AddItem (pTree, h1, "000-00030 Const Engineering (Consultant)",  20);
	AddItem (pTree, h1, "000-00035 Const Engineering (NFA)",  20);
	AddItem (pTree, h1, "000-00050 Indirect Costs (CE Only)",  20);
	AddItem (pTree, h1, "000-00070 Obsolete-Use 700-70035 11/97",  20);
	AddItem (pTree, h1, "103-03000 Project Commitment Amount",  20);
	AddItem (pTree, h1, "201-00000 Clear and Grub",  20);
	AddItem (pTree, h1, "201-00001 Clear and Grub",  20);
	AddItem (pTree, h1, "201-00002 Clearing",  20);
	AddItem (pTree, h1, "202-00000 Rem Str and Obstructions",  20);
	AddItem (pTree, h1, "202-00001 Rem Structure",  20);
	AddItem (pTree, h1, "202-00002 Rem of Structure (Spec)",  20);
	AddItem (pTree, h1, "202-00005 Rem Temporary Supports",  20);
	AddItem (pTree, h1, "202-00006 Rem Temporary Supports",  20);
	AddItem (pTree, h1, "202-00009 Tree Trimming",  20);
	AddItem (pTree, h1, "202-00010 Rem Tree",  20);
	AddItem (pTree, h1, "202-00011 Tree Trimming",  20);
	AddItem (pTree, h1, "202-00012 Rem Tree Stump",  20);
	AddItem (pTree, h1, "202-00014 Brush Clearing",  20);
	AddItem (pTree, h1, "202-00015 Rem Headwall",  20);
	AddItem (pTree, h1, "202-00020 Rem CBC",  20);
	AddItem (pTree, h1, "202-00025 Rem Ditch Lining",  20);
	AddItem (pTree, h1, "202-00026 Rem S and D Pave",  20);
	AddItem (pTree, h1, "202-00027 Rem Riprap",  20);
	AddItem (pTree, h1, "202-00029 Rem Gabion",  20);
	AddItem (pTree, h1, "202-00030 Rem Water Service",  20);
	AddItem (pTree, h1, "202-00031 Rem of Fire Hydrant",  20);
	AddItem (pTree, h1, "202-00033 Rem Pipe",  20);
	AddItem (pTree, h1, "202-00035 Rem Pipe",  20);
	AddItem (pTree, h1, "202-00037 Rem of End Section",  20);
	AddItem (pTree, h1, "202-00038 Rem Structural Plate Pipe",  20);
	AddItem (pTree, h1, "202-00040 Rem Elec Conduit",  20);
	AddItem (pTree, h1, "202-00070 Rem Barricade",  20);
	AddItem (pTree, h1, "202-00080 Rem Guard Post",  20);
	AddItem (pTree, h1, "202-00090 Rem Delineator",  20);
	AddItem (pTree, h1, "202-00150 Rem Wall",  20);
	AddItem (pTree, h1, "202-00155 Rem Wall",  20);
	AddItem (pTree, h1, "202-00160 Rem Wall",  20);
	AddItem (pTree, h1, "202-00165 Rem Wall",  20);
	AddItem (pTree, h1, "202-00175 Rem Concrete",  20);
	AddItem (pTree, h1, "202-00190 Rem of Conc Median Cover",  20);
	AddItem (pTree, h1, "202-00195 Rem of Median Cover",  20);
	AddItem (pTree, h1, "202-00200 Rem Sidewalk",  20);
	AddItem (pTree, h1, "202-00201 Rem Curb",  20);
	AddItem (pTree, h1, "202-00202 Rem Gutter",  20);
	AddItem (pTree, h1, "202-00203 Rem Curb and Gutter",  20);
	AddItem (pTree, h1, "202-00204 Rem CG and Sidewalk",  20);
	AddItem (pTree, h1, "202-00205 Rem Wheel Stop",  20);
	AddItem (pTree, h1, "202-00210 Rem Conc Pavement",  20);
	AddItem (pTree, h1, "202-00215 Rem Conc Pvmt (Planing)",  20);
	AddItem (pTree, h1, "202-00220 Rem Asphalt Mat",  20);
	AddItem (pTree, h1, "202-00226 Rem of Asph Mat (Special)",  20);
	AddItem (pTree, h1, "202-00240 Rem Asphalt Mat (Planing)",  20);
	AddItem (pTree, h1, "202-00245 Rem Asphalt Mat (Planing)",  20);
	AddItem (pTree, h1, "202-00246 Rem Asphalt Mat (Planing)(Spec)",  20);
	AddItem (pTree, h1, "202-00247 Rem Asphalt Mat (Planing)",  20);
	AddItem (pTree, h1, "202-00250 Rem Pavement Marking",  20);
	AddItem (pTree, h1, "202-00400 Rem Bridge",  20);
	AddItem (pTree, h1, "202-00410 Rem Mat From Br",  20);
	AddItem (pTree, h1, "202-00425 Rem Bridge Railing",  20);
	AddItem (pTree, h1, "202-00450 Rem Port Present Str (1)",  20);
	AddItem (pTree, h1, "202-00454 Rem Port Present Str (2A)",  20);
	AddItem (pTree, h1, "202-00456 Rem Port Present Str (2B)",  20);
	AddItem (pTree, h1, "202-00460 Rem Port Present Str (3)",  20);
	AddItem (pTree, h1, "202-00462 Rem Port Present Str (3A)",  20);
	AddItem (pTree, h1, "202-00466 Rem Port Present Str (4)",  20);
	AddItem (pTree, h1, "202-00480 Rem Port Present Str (Special)",  20);
	AddItem (pTree, h1, "202-00495 Rem Port Present Str",  20);
	AddItem (pTree, h1, "202-00500 Rem Port Present Str",  20);
	AddItem (pTree, h1, "202-00502 Rem Port Present Str",  20);
	AddItem (pTree, h1, "202-00503 Rem Port Present Str",  20);
	AddItem (pTree, h1, "202-00504 Rem Exp Device",  20);
	AddItem (pTree, h1, "202-00510 Rem Contraction Jt",  20);
	AddItem (pTree, h1, "202-00520 Rem of Exp Joint Matl",  20);
	AddItem (pTree, h1, "202-00600 Rem Railroad Appurtenances",  20);
	AddItem (pTree, h1, "202-00610 Rem of RR Track",  20);
	AddItem (pTree, h1, "202-00620 Rem of RR Crossover",  20);
	AddItem (pTree, h1, "202-00621 Rem of RR Turnout",  20);
	AddItem (pTree, h1, "202-00700 Rem Light Standard",  20);
	AddItem (pTree, h1, "202-00725 Rem Ex Lighting Sys",  20);
	AddItem (pTree, h1, "202-00750 Rem Luminaire",  20);
	AddItem (pTree, h1, "202-00800 Rem Overpass Mtd Sign Brkt",  20);
	AddItem (pTree, h1, "202-00805 Rem Overhead Sign Str",  20);
	AddItem (pTree, h1, "202-00810 Rem Ground Sign",  20);
	AddItem (pTree, h1, "202-00815 Rem of Sign (Special)",  20);
	AddItem (pTree, h1, "202-00821 Rem Sign Panel",  20);
	AddItem (pTree, h1, "202-00825 Rem Flashing Beacon",  20);
	AddItem (pTree, h1, "202-00828 Rem Traf Sig Equipment",  20);
	AddItem (pTree, h1, "202-00830 Rem Traf Sig Face",  20);
	AddItem (pTree, h1, "202-00831 Rem Traf Sig Head",  20);
	AddItem (pTree, h1, "202-00840 Rem Traf Sig Pole",  20);
	AddItem (pTree, h1, "202-00842 Rem Mast Arm",  20);
	AddItem (pTree, h1, "202-00845 Rem Traf Sig Controller",  20);
	AddItem (pTree, h1, "202-00848 Rem Traf Sig Control+Cab",  20);
	AddItem (pTree, h1, "202-00855 Rem Traf Sig Control Cab",  20);
	AddItem (pTree, h1, "202-00858 Rem Pedestal Pole",  20);
	AddItem (pTree, h1, "202-00860 Rem Ped Push Button",  20);
	AddItem (pTree, h1, "202-00870 Rem Coordination Unit",  20);
	AddItem (pTree, h1, "202-00873 Rem Tone Decoder",  20);
	AddItem (pTree, h1, "202-00880 Rem Sig Veh Detector Amp",  20);
	AddItem (pTree, h1, "202-00882 Rem Detector (Magnetic)",  20);
	AddItem (pTree, h1, "202-00890 Rem Span Wire Cable",  20);
	AddItem (pTree, h1, "202-00895 Rem of Impact Attenuator",  20);
	AddItem (pTree, h1, "202-00900 Rem Conc Footing",  20);
	AddItem (pTree, h1, "202-01000 Rem Fence",  20);
	AddItem (pTree, h1, "202-01020 Rem Sound Barrier Fence",  20);
	AddItem (pTree, h1, "202-01030 Rem of Road Closure Gate",  20);
	AddItem (pTree, h1, "202-01110 Rem Gdrail Ty 1",  20);
	AddItem (pTree, h1, "202-01130 Rem Gdrail Ty 3",  20);
	AddItem (pTree, h1, "202-01135 Rem Gdrail Thrie Beam",  20);
	AddItem (pTree, h1, "202-01140 Rem Gdrail Ty 4",  20);
	AddItem (pTree, h1, "202-01150 Rem Gdrail Ty 5",  20);
	AddItem (pTree, h1, "202-01300 Rem End Anchorage",  20);
	AddItem (pTree, h1, "202-01400 Removal of Cattle Guard",  20);
	AddItem (pTree, h1, "202-04000 Plug Structure",  20);
	AddItem (pTree, h1, "202-04001 Plug Culvert",  20);
	AddItem (pTree, h1, "202-04002 Clean Culvert",  20);
	AddItem (pTree, h1, "202-04005 Clean Valve Box",  20);
	AddItem (pTree, h1, "202-04040 Clean Box Girder",  20);
	AddItem (pTree, h1, "202-04100 Abandon Well",  20);
	AddItem (pTree, h1, "202-04200 Plug Storage Tank",  20);
	AddItem (pTree, h1, "202-05000 Transverse Grooving",  20);
	AddItem (pTree, h1, "202-05002 Sawing Concrete (50 mm)",  20);
	AddItem (pTree, h1, "202-05004 Sawing Concrete (100 mm)",  20);
	AddItem (pTree, h1, "202-05006 Sawing Concrete (150 mm)",  20);
	AddItem (pTree, h1, "202-05008 Sawing Concrete (200 mm)",  20);
	AddItem (pTree, h1, "202-05010 Sawing Concrete (250 mm)",  20);
	AddItem (pTree, h1, "202-05011 Sawing Concrete (270 mm)",  20);
	AddItem (pTree, h1, "202-05026 Sawing Asphalt Mat (150 mm)",  20);
	AddItem (pTree, h1, "202-05100 Sandblasting Reinf Steel",  20);
	AddItem (pTree, h1, "202-05150 Sandblasting",  20);
	AddItem (pTree, h1, "202-05300 Rem and Disposal of Paint",  20);
	AddItem (pTree, h1, "202-06000 Rem Detour",  20);
	AddItem (pTree, h1, "202-06500 Rem of Restraining Bar",  20);
	AddItem (pTree, h1, "202-06510 Rem Inspection Car Rail",  20);
	AddItem (pTree, h1, "202-06520 Rem of Existing Wall Panel",  20);
	AddItem (pTree, h1, "202-06530 Clean Drain Pipe (Spec)",  20);
	AddItem (pTree, h1, "202-07000 Oblit Old Road",  20);
	AddItem (pTree, h1, "203-00000 Uncl Excav",  20);
	AddItem (pTree, h1, "203-00010 Uncl Excav (CIP)",  20);
	AddItem (pTree, h1, "203-00012 Uncl Excav (CIP) (Spec)",  20);
	AddItem (pTree, h1, "203-00040 Uncl Excav (Spec)",  20);
	AddItem (pTree, h1, "203-00060 Emb Matl (CIP)",  20);
	AddItem (pTree, h1, "203-00061 Emb Matl (CIP)",  20);
	AddItem (pTree, h1, "203-00062 Emb Matl (CIP) (Spec)",  20);
	AddItem (pTree, h1, "203-00100 Muck Excav",  20);
	AddItem (pTree, h1, "203-00200 Borrow",  20);
	AddItem (pTree, h1, "203-00210 Borrow (CIP)",  20);
	AddItem (pTree, h1, "203-00400 Rock Excav",  20);
	AddItem (pTree, h1, "203-00440 Rock Excav (Spec)",  20);
	AddItem (pTree, h1, "203-00500 Rock Fill",  20);
	AddItem (pTree, h1, "203-00590 Rock Placement",  20);
	AddItem (pTree, h1, "203-00595 Rock Scaling",  20);
	AddItem (pTree, h1, "203-00600 Stripping",  20);
	AddItem (pTree, h1, "203-00700 Reclaim Pit",  20);
	AddItem (pTree, h1, "203-00710 Clay Plating (CIP)",  20);
	AddItem (pTree, h1, "203-00810 Sawdust Fill (CIP)",  20);
	AddItem (pTree, h1, "203-00840 Polystyrene Fill",  20);
	AddItem (pTree, h1, "203-00850 Polystyrene Fill (CIP)",  20);
	AddItem (pTree, h1, "203-00900 Contaminated Soil Excav",  20);
	AddItem (pTree, h1, "203-00910 Contam Soil Excav & Disposal",  20);
	AddItem (pTree, h1, "203-01020 Compaction (AASHTO T 99)",  20);
	AddItem (pTree, h1, "203-01030 Compaction (AASHTO T 180)",  20);
	AddItem (pTree, h1, "203-01100 Proof Rolling",  20);
	AddItem (pTree, h1, "203-01120 Vibratory Rolling",  20);
	AddItem (pTree, h1, "203-01140 Rolling",  20);
	AddItem (pTree, h1, "203-01500 Blading",  20);
	AddItem (pTree, h1, "203-01510 Backhoe",  20);
	AddItem (pTree, h1, "203-01515 Backhoe (Landscaping)",  20);
	AddItem (pTree, h1, "203-01520 Backhoe (Spec)",  20);
	AddItem (pTree, h1, "203-01548 Pump",  20);
	AddItem (pTree, h1, "203-01549 Pump",  20);
	AddItem (pTree, h1, "203-01550 Dozing",  20);
	AddItem (pTree, h1, "203-01551 Dozing (Heavy)",  20);
	AddItem (pTree, h1, "203-01555 Dozing (Landscaping)",  20);
	AddItem (pTree, h1, "203-01580 Truck",  20);
	AddItem (pTree, h1, "203-01582 Truck (Dump)",  20);
	AddItem (pTree, h1, "203-01583 Truck (Tractor)",  20);
	AddItem (pTree, h1, "203-01590 Front End Loader (Rubber)",  20);
	AddItem (pTree, h1, "203-01591 Front End Loader (Crawler)",  20);
	AddItem (pTree, h1, "203-01592 Front End Loader (Special)",  20);
	AddItem (pTree, h1, "203-01594 Combination Loader",  20);
	AddItem (pTree, h1, "203-01596 Potholing W/ Surveying",  20);
	AddItem (pTree, h1, "203-01597 Potholing",  20);
	AddItem (pTree, h1, "203-01600 Crane (Crawler)",  20);
	AddItem (pTree, h1, "203-01610 Crane (Rubber Tired)",  20);
	AddItem (pTree, h1, "203-01615 Crane (Scaling)",  20);
	AddItem (pTree, h1, "203-01620 Sweeping",  20);
	AddItem (pTree, h1, "203-01625 Hydraulic Excavator Scaling",  20);
	AddItem (pTree, h1, "203-02000 Drill and Blast",  20);
	AddItem (pTree, h1, "203-02060 Presplitting",  20);
	AddItem (pTree, h1, "203-02300 Rock Scaler",  20);
	AddItem (pTree, h1, "203-02310 Scaler Foreman",  20);
	AddItem (pTree, h1, "203-02312 Hand Scaling",  20);
	AddItem (pTree, h1, "203-02315 Mechanized Scaling",  20);
	AddItem (pTree, h1, "203-02320 Blaster",  20);
	AddItem (pTree, h1, "203-02330 Laborer",  20);
	AddItem (pTree, h1, "206-00000 Str Excav",  20);
	AddItem (pTree, h1, "206-00010 Str Excav (Spec)",  20);
	AddItem (pTree, h1, "206-00050 Str Bkfl (Spec)",  20);
	AddItem (pTree, h1, "206-00060 Str Bkfl (Spec) (Flow-Fill)",  20);
	AddItem (pTree, h1, "206-00065 Str Bkfl (Flow-Fill)",  20);
	AddItem (pTree, h1, "206-00100 Str Bkfl (CL 1)",  20);
	AddItem (pTree, h1, "206-00200 Str Bkfl (CL 2)",  20);
	AddItem (pTree, h1, "206-00360 Mechanical Reinforcement of Soil",  20);
	AddItem (pTree, h1, "206-00505 Filter Matl (Spec)",  20);
	AddItem (pTree, h1, "206-00510 Filter Matl (CL A)",  20);
	AddItem (pTree, h1, "206-00520 Filter Matl (CL B)",  20);
	AddItem (pTree, h1, "206-00530 Filter Matl (CL C)",  20);
	AddItem (pTree, h1, "206-01000 Bed Course Matl",  20);
	AddItem (pTree, h1, "206-01001 Bed Course Matl (Spec)",  20);
	AddItem (pTree, h1, "206-01010 Bed Course Matl",  20);
	AddItem (pTree, h1, "206-01500 Cofferdam",  20);
	AddItem (pTree, h1, "206-01600 Temp Excav Support",  20);
	AddItem (pTree, h1, "206-01701 Temp Excav Support (A 1)",  20);
	AddItem (pTree, h1, "206-01702 Temp Excav Support (A 2)",  20);
	AddItem (pTree, h1, "206-01703 Temp Excav Support (A 3)",  20);
	AddItem (pTree, h1, "206-01750 Shoring",  20);
	AddItem (pTree, h1, "207-00205 Topsoil",  20);
	AddItem (pTree, h1, "207-00210 Stockpile Topsoil",  20);
	AddItem (pTree, h1, "207-00305 Wetland Topsoil",  20);
	AddItem (pTree, h1, "207-00310 Stockpile Wetland Topsoil",  20);
	AddItem (pTree, h1, "207-00405 Topsoil (Spec)",  20);
	AddItem (pTree, h1, "207-01110 Planter Soil Mix",  20);
	AddItem (pTree, h1, "208-00001 Silt Dike",  20);
	AddItem (pTree, h1, "208-00005 Erosion Log",  20);
	AddItem (pTree, h1, "208-00006 Erosion Log (Special)",  20);
	AddItem (pTree, h1, "208-00010 Erosion Bales",  20);
	AddItem (pTree, h1, "208-00011 Erosion Bales (Weed Free)",  20);
	AddItem (pTree, h1, "208-00015 Sand Bag",  20);
	AddItem (pTree, h1, "208-00020 Silt Fence",  20);
	AddItem (pTree, h1, "208-00030 Sediment Basin",  20);
	AddItem (pTree, h1, "208-00033 Sediment Trap",  20);
	AddItem (pTree, h1, "208-00040 Check Dam",  20);
	AddItem (pTree, h1, "208-00050 Storm Drain Inlet Protection",  20);
	AddItem (pTree, h1, "208-00060 Temporary Slope Drain",  20);
	AddItem (pTree, h1, "208-00070 Stabilized Construction Entrance",  20);
	AddItem (pTree, h1, "208-00100 Sediment Removal and Disposal",  20);
	AddItem (pTree, h1, "208-00110 Sediment Removal and Disposal",  20);
	AddItem (pTree, h1, "208-00200 Erosion Control Supervisor",  20);
	AddItem (pTree, h1, "208-00205 Erosion Control Supervisor",  20);
	AddItem (pTree, h1, "208-00300 Temporary Berms",  20);
	AddItem (pTree, h1, "209-00000 Water",  20);
	AddItem (pTree, h1, "209-00050 Water",  20);
	AddItem (pTree, h1, "209-00100 Water (Landscaping)",  20);
	AddItem (pTree, h1, "209-00600 Dust Palliative (Mg Cl)",  20);
	AddItem (pTree, h1, "209-00601 Dust Palliative (Mg Cl)",  20);
	AddItem (pTree, h1, "210-00001 Res Structure",  20);
	AddItem (pTree, h1, "210-00007 Res Wheel Stop",  20);
	AddItem (pTree, h1, "210-00010 Res Mailbox Str",  20);
	AddItem (pTree, h1, "210-00011 Res Mailbox Str (Ty 1)",  20);
	AddItem (pTree, h1, "210-00012 Res Mailbox Str (Ty 2)",  20);
	AddItem (pTree, h1, "210-00013 Res Mailbox Str (Ty 3)",  20);
	AddItem (pTree, h1, "210-00014 Res Mailbox Str (Ty 4)",  20);
	AddItem (pTree, h1, "210-00015 Res End Section",  20);
	AddItem (pTree, h1, "210-00030 Res Water Service",  20);
	AddItem (pTree, h1, "210-00035 Res Water Meter",  20);
	AddItem (pTree, h1, "210-00040 Res Water Line",  20);
	AddItem (pTree, h1, "210-00050 Res Fire Hydrant",  20);
	AddItem (pTree, h1, "210-00060 Res Marker",  20);
	AddItem (pTree, h1, "210-00065 Res Monument (Ty 3A)",  20);
	AddItem (pTree, h1, "210-00070 Res Barricade",  20);
	AddItem (pTree, h1, "210-00090 Res Delineator",  20);
	AddItem (pTree, h1, "210-00100 Res Trash Guard",  20);
	AddItem (pTree, h1, "210-00400 Res Expan Device",  20);
	AddItem (pTree, h1, "210-00410 Modify Bridge Expan Device",  20);
	AddItem (pTree, h1, "210-00420 Res Timbers",  20);
	AddItem (pTree, h1, "210-00425 Res Bridge Railing",  20);
	AddItem (pTree, h1, "210-00427 Res Pipe Handrailing",  20);
	AddItem (pTree, h1, "210-00440 Repair Curb",  20);
	AddItem (pTree, h1, "210-00450 Repair Overhead Sign Stru",  20);
	AddItem (pTree, h1, "210-00472 Res Metal Panels",  20);
	AddItem (pTree, h1, "210-00473 Res TV Cameras",  20);
	AddItem (pTree, h1, "210-00474 Res Traf Contr Signal Head",  20);
	AddItem (pTree, h1, "210-00480 Pier Restoration",  20);
	AddItem (pTree, h1, "210-00500 Reb Port Present Str",  20);
	AddItem (pTree, h1, "210-00510 Reb Port Present Str",  20);
	AddItem (pTree, h1, "210-00650 Reb Timber Deck",  20);
	AddItem (pTree, h1, "210-00750 Res Light Standard",  20);
	AddItem (pTree, h1, "210-00755 Res Light Standard Steel",  20);
	AddItem (pTree, h1, "210-00760 Res Luminaire",  20);
	AddItem (pTree, h1, "210-00805 Res Overhead Sign Str",  20);
	AddItem (pTree, h1, "210-00810 Res Ground Sign",  20);
	AddItem (pTree, h1, "210-00815 Res Sign Panel",  20);
	AddItem (pTree, h1, "210-00820 Res Var Mesg Sign",  20);
	AddItem (pTree, h1, "210-00825 Res Flashing Beacon",  20);
	AddItem (pTree, h1, "210-00830 Res Traf Sig Face",  20);
	AddItem (pTree, h1, "210-00831 Res Traf Sig Head",  20);
	AddItem (pTree, h1, "210-00840 Res Traf Sig Pole",  20);
	AddItem (pTree, h1, "210-00842 Res Traf Sig Mast Arm",  20);
	AddItem (pTree, h1, "210-00845 Res Traf Sig Cntrlr",  20);
	AddItem (pTree, h1, "210-00848 Res Traf Sig Control+Cab",  20);
	AddItem (pTree, h1, "210-00855 Res Traf Sig Control Cab",  20);
	AddItem (pTree, h1, "210-00858 Res Pedestal Pole",  20);
	AddItem (pTree, h1, "210-00860 Res Ped Push Button",  20);
	AddItem (pTree, h1, "210-00865 Res Ped Sig Head",  20);
	AddItem (pTree, h1, "210-00866 Res Fire Preempt Unit+Timer",  20);
	AddItem (pTree, h1, "210-00867 Res Fire Preempt Unit",  20);
	AddItem (pTree, h1, "210-00870 Res Coordination Unit",  20);
	AddItem (pTree, h1, "210-00873 Res Tone Decoder",  20);
	AddItem (pTree, h1, "210-00875 Res Surface Cond Analyser",  20);
	AddItem (pTree, h1, "210-00880 Res Sig Veh Detector Amp",  20);
	AddItem (pTree, h1, "210-00882 Res Detector",  20);
	AddItem (pTree, h1, "210-00885 Res Loop Detector (Micro Type)",  20);
	AddItem (pTree, h1, "210-00900 Res Traffic Counter (Temp)",  20);
	AddItem (pTree, h1, "210-00910 Res Traffic Counter (Perm)",  20);
	AddItem (pTree, h1, "210-01000 Res Fence",  20);
	AddItem (pTree, h1, "210-01001 Modify Fence",  20);
	AddItem (pTree, h1, "210-01005 Res Fence Post",  20);
	AddItem (pTree, h1, "210-01010 Res Gate Post",  20);
	AddItem (pTree, h1, "210-01011 Res Gate",  20);
	AddItem (pTree, h1, "210-01025 Res Snow Fence",  20);
	AddItem (pTree, h1, "210-01050 Res C L Fence",  20);
	AddItem (pTree, h1, "210-01130 Res Gdrail Ty 3",  20);
	AddItem (pTree, h1, "210-01135 Res Gdrail Thrie Beam",  20);
	AddItem (pTree, h1, "210-01140 Res Gdrail Ty 4",  20);
	AddItem (pTree, h1, "210-01150 Res Gdrail Ty 5",  20);
	AddItem (pTree, h1, "210-01160 Res Gdrail Ty 6",  20);
	AddItem (pTree, h1, "210-01200 Res End Anchorage",  20);
	AddItem (pTree, h1, "210-01300 Res Impact Attenuator",  20);
	AddItem (pTree, h1, "210-01700 Res Sprinkler Head",  20);
	AddItem (pTree, h1, "210-01710 Res Valve",  20);
	AddItem (pTree, h1, "210-01720 Res Air Vent",  20);
	AddItem (pTree, h1, "210-01730 Res Parshall Flume",  20);
	AddItem (pTree, h1, "210-01996 Relay Pipe (20 mm)",  20);
	AddItem (pTree, h1, "210-02002 Relay Pipe (50 mm)",  20);
	AddItem (pTree, h1, "210-02003 Relay Pipe (75 mm)",  20);
	AddItem (pTree, h1, "210-02004 Relay Pipe (100 mm)",  20);
	AddItem (pTree, h1, "210-02006 Relay Pipe (150 mm)",  20);
	AddItem (pTree, h1, "210-02008 Relay Pipe (200 mm)",  20);
	AddItem (pTree, h1, "210-02009 Relay Pipe (225 mm)",  20);
	AddItem (pTree, h1, "210-02010 Relay Pipe (250 mm)",  20);
	AddItem (pTree, h1, "210-02012 Relay Pipe (300 mm)",  20);
	AddItem (pTree, h1, "210-02015 Relay Pipe (375 mm)",  20);
	AddItem (pTree, h1, "210-02016 Relay Pipe (400 mm)",  20);
	AddItem (pTree, h1, "210-02018 Relay Pipe (450 mm)",  20);
	AddItem (pTree, h1, "210-02021 Relay Pipe (525 mm)",  20);
	AddItem (pTree, h1, "210-02024 Relay Pipe (600 mm)",  20);
	AddItem (pTree, h1, "210-02027 Relay Pipe (700 mm)",  20);
	AddItem (pTree, h1, "210-02030 Relay Pipe (750 mm)",  20);
	AddItem (pTree, h1, "210-02036 Relay Pipe (900 mm)",  20);
	AddItem (pTree, h1, "210-02042 Relay Pipe (1050 mm)",  20);
	AddItem (pTree, h1, "210-02048 Relay Pipe (1200 mm)",  20);
	AddItem (pTree, h1, "210-02054 Relay Pipe (1350 mm)",  20);
	AddItem (pTree, h1, "210-02060 Relay Pipe (1500 mm)",  20);
	AddItem (pTree, h1, "210-02066 Relay Pipe (1650 mm)",  20);
	AddItem (pTree, h1, "210-02072 Relay Pipe (1800 mm)",  20);
	AddItem (pTree, h1, "210-02078 Relay Pipe (1950 mm)",  20);
	AddItem (pTree, h1, "210-02084 Relay Pipe (2100 mm)",  20);
	AddItem (pTree, h1, "210-02136 Relay Arch Pipe (900 mm)",  20);
	AddItem (pTree, h1, "210-02510 Relay Sprinkler System",  20);
	AddItem (pTree, h1, "210-02800 Relay Sidewalk",  20);
	AddItem (pTree, h1, "210-02900 Relay Riprap",  20);
	AddItem (pTree, h1, "210-03100 Replace Conc Pvmt",  20);
	AddItem (pTree, h1, "210-04000 Adj Structure",  20);
	AddItem (pTree, h1, "210-04010 Adj Manhole",  20);
	AddItem (pTree, h1, "210-04011 Adj Manhole (spec)",  20);
	AddItem (pTree, h1, "210-04015 Modify Manhole",  20);
	AddItem (pTree, h1, "210-04016 Modify Manhole (Spec)",  20);
	AddItem (pTree, h1, "210-04020 Modify Inlet",  20);
	AddItem (pTree, h1, "210-04025 Modify Structure",  20);
	AddItem (pTree, h1, "210-04030 Modify Guardrail",  20);
	AddItem (pTree, h1, "210-04050 Adj Valve Box",  20);
	AddItem (pTree, h1, "210-04051 Adj Valve Box (Spec)",  20);
	AddItem (pTree, h1, "210-04200 Adj Gdrail",  20);
	AddItem (pTree, h1, "210-04500 Relocate Building",  20);
	AddItem (pTree, h1, "211-00000 Tunnel Excav",  20);
	AddItem (pTree, h1, "211-00005 Tunnel Excav (H)",  20);
	AddItem (pTree, h1, "211-00100 Drilling Hole",  20);
	AddItem (pTree, h1, "211-00105 25 mm Drilled Hole",  20);
	AddItem (pTree, h1, "211-00116 50 mm Drilled Hole",  20);
	AddItem (pTree, h1, "211-00124 75 mm Drilled Hole",  20);
	AddItem (pTree, h1, "211-00136 100 mm Drilled Hole",  20);
	AddItem (pTree, h1, "211-00148 150 mm Drilled Hole",  20);
	AddItem (pTree, h1, "211-00212 38 mm Core Drilled Hole",  20);
	AddItem (pTree, h1, "211-00224 75 mm Core Drilled Hole",  20);
	AddItem (pTree, h1, "211-01008 Rock Bolt (25 mm)",  20);
	AddItem (pTree, h1, "211-01016 Rock Bolt (50 mm)",  20);
	AddItem (pTree, h1, "211-01024 Rock Bolt (75 mm)",  20);
	AddItem (pTree, h1, "211-01100 Rock Reinf (Bolts)",  20);
	AddItem (pTree, h1, "211-01110 Rock Reinf (Dowels)",  20);
	AddItem (pTree, h1, "211-01115 Rock Reinf (No.10)",  20);
	AddItem (pTree, h1, "211-01120 Rock Reinf (Spiles)",  20);
	AddItem (pTree, h1, "211-01130 Auxil Anchor Dowel",  20);
	AddItem (pTree, h1, "211-01150 Rock Reinf Tests",  20);
	AddItem (pTree, h1, "211-01160 Trial Pull Test",  20);
	AddItem (pTree, h1, "211-01200 Rock Anchor",  20);
	AddItem (pTree, h1, "211-01300 Rock Anchor",  20);
	AddItem (pTree, h1, "211-01409 Rock Anchor (3 m)",  20);
	AddItem (pTree, h1, "211-01455 Rock Tiedown Anchor (Cem Gr)",  20);
	AddItem (pTree, h1, "211-01456 Rock Tiedown Anchor (Cem Gr)",  20);
	AddItem (pTree, h1, "211-01511 Rock Reinf (R G No.30) RB",  20);
	AddItem (pTree, h1, "211-02012 Soil Anchor (31 mm)",  20);
	AddItem (pTree, h1, "211-02116 Rock Dowel",  20);
	AddItem (pTree, h1, "211-02205 Buttress Berm Grouting",  20);
	AddItem (pTree, h1, "211-02210 Pre Grouting",  20);
	AddItem (pTree, h1, "211-02220 Re-Grouting",  20);
	AddItem (pTree, h1, "211-02230 Grout Conn",  20);
	AddItem (pTree, h1, "211-02232 Grout Conn (Pre-Grout)",  20);
	AddItem (pTree, h1, "211-02233 Grout Conn (Contact Grout)",  20);
	AddItem (pTree, h1, "211-02240 Contact Grouting",  20);
	AddItem (pTree, h1, "211-02250 Steel Pipe For Grouting",  20);
	AddItem (pTree, h1, "211-02260 Chemical Grout",  20);
	AddItem (pTree, h1, "211-02270 Cement Grout",  20);
	AddItem (pTree, h1, "211-02275 Cement Grout",  20);
	AddItem (pTree, h1, "211-02280 Type A Grout",  20);
	AddItem (pTree, h1, "211-02290 Type B Grout",  20);
	AddItem (pTree, h1, "211-03001 Dewatering Special",  20);
	AddItem (pTree, h1, "211-03005 Dewatering",  20);
	AddItem (pTree, h1, "212-00005 Seeding (Native)",  20);
	AddItem (pTree, h1, "212-00006 Seeding (Native)",  20);
	AddItem (pTree, h1, "212-00007 Seeding (Native) (Hydraulic)",  20);
	AddItem (pTree, h1, "212-00009 Seeding (Temporary)",  20);
	AddItem (pTree, h1, "212-00011 Seeding (Lawn)",  20);
	AddItem (pTree, h1, "212-00015 Seeding (Forbs)",  20);
	AddItem (pTree, h1, "212-00020 Seeding (Forbs)",  20);
	AddItem (pTree, h1, "212-00025 Seeding (Shrubs)",  20);
	AddItem (pTree, h1, "212-00027 Seeding (Trees)",  20);
	AddItem (pTree, h1, "212-00028 Seeding (Wetlands)",  20);
	AddItem (pTree, h1, "212-00040 Soil Preparation (Lawn)",  20);
	AddItem (pTree, h1, "212-00047 Soil Preparation (Spec)",  20);
	AddItem (pTree, h1, "212-00048 Soil Preparation (Spec)",  20);
	AddItem (pTree, h1, "212-00050 Sod",  20);
	AddItem (pTree, h1, "212-00055 Sod (Buffalograss)",  20);
	AddItem (pTree, h1, "212-00900 Compost",  20);
	AddItem (pTree, h1, "212-01200 Landscape Restoration",  20);
	AddItem (pTree, h1, "213-00000 Mulching",  20);
	AddItem (pTree, h1, "213-00001 Mulching",  20);
	AddItem (pTree, h1, "213-00002 Mulching (Weed Free Hay)",  20);
	AddItem (pTree, h1, "213-00003 Mulching (Weed Free)",  20);
	AddItem (pTree, h1, "213-00004 Mulching (Weed Free Straw)",  20);
	AddItem (pTree, h1, "213-00005 Mulching (Decorative)",  20);
	AddItem (pTree, h1, "213-00006 Mulching (Weed Free)",  20);
	AddItem (pTree, h1, "213-00008 Mulching (Wood Chip)",  20);
	AddItem (pTree, h1, "213-00011 Mulching (Hydraulic)",  20);
	AddItem (pTree, h1, "213-00061 Mulch Tackifier",  20);
	AddItem (pTree, h1, "213-00070 Landscape Weed Barr Fabric",  20);
	AddItem (pTree, h1, "213-00100 Soil Binder",  20);
	AddItem (pTree, h1, "213-00150 Bonded Fiber Matrix",  20);
	AddItem (pTree, h1, "213-00212 300 mm Root Barrier",  20);
	AddItem (pTree, h1, "213-00218 450 mm Root Barrier",  20);
	AddItem (pTree, h1, "213-00300 Conc Landscape Border",  20);
	AddItem (pTree, h1, "213-00400 Inst Landscape Border",  20);
	AddItem (pTree, h1, "213-00440 Landscape Border (3x100 mm)",  20);
	AddItem (pTree, h1, "213-00460 Landscape Border (5x100 mm)",  20);
	AddItem (pTree, h1, "213-00462 Landscape Border (5x138 mm)",  20);
	AddItem (pTree, h1, "213-00468 Landscape Border (5x250 mm)",  20);
	AddItem (pTree, h1, "213-00470 Landscape Border (6x125 mm)",  20);
	AddItem (pTree, h1, "213-00500 Tree Grate",  20);
	AddItem (pTree, h1, "213-00510 Inst Tree Grate",  20);
	AddItem (pTree, h1, "213-00550 Tree Ring",  20);
	AddItem (pTree, h1, "213-00600 Landscape Log",  20);
	AddItem (pTree, h1, "213-00610 Landscape Log",  20);
	AddItem (pTree, h1, "213-00700 Landscape Boulder",  20);
	AddItem (pTree, h1, "213-00705 Landscape Boulder (Special)",  20);
	AddItem (pTree, h1, "214-00000 Landscape Maintenance",  20);
	AddItem (pTree, h1, "214-00155 Plant (B and B)",  20);
	AddItem (pTree, h1, "214-00160 Furn Plant (B and B)",  20);
	AddItem (pTree, h1, "214-00161 Inst Plant (B and B)",  20);
	AddItem (pTree, h1, "214-00201 Deciduous Tree (Tubeling)",  20);
	AddItem (pTree, h1, "214-00210 Deciduous Tree (25 mm C)",  20);
	AddItem (pTree, h1, "214-00215 Deciduous Tree (38 mm C)",  20);
	AddItem (pTree, h1, "214-00217 Furn Decid Tree (38 mm C)",  20);
	AddItem (pTree, h1, "214-00220 Deciduous Tree (50 mm C)",  20);
	AddItem (pTree, h1, "214-00222 Furn Decid Tree (50 mm C)",  20);
	AddItem (pTree, h1, "214-00225 Deciduous Tree (63 mm C)",  20);
	AddItem (pTree, h1, "214-00227 Furn Deciduous Tree (63 mm C)",  20);
	AddItem (pTree, h1, "214-00230 Deciduous Tree (75 mm C)",  20);
	AddItem (pTree, h1, "214-00235 Deciduous Tree (88 mm C)",  20);
	AddItem (pTree, h1, "214-00240 Deciduous Tree (100 mm C)",  20);
	AddItem (pTree, h1, "214-00260 Deciduous Tree (1.8 m)",  20);
	AddItem (pTree, h1, "214-00262 Furn Decid Tree (1.8 m)",  20);
	AddItem (pTree, h1, "214-00280 Deciduous Tree (2.4 m)",  20);
	AddItem (pTree, h1, "214-00282 Furn Decid Tree (2.4 m)",  20);
	AddItem (pTree, h1, "214-00301 Deciduous Shrub (Tubeling)",  20);
	AddItem (pTree, h1, "214-00310 Deciduous Shrub (No. 1)",  20);
	AddItem (pTree, h1, "214-00330 Deciduous Shrub (No. 3)",  20);
	AddItem (pTree, h1, "214-00350 Deciduous Shrub (No. 5)",  20);
	AddItem (pTree, h1, "214-00365 Furn Plant (63 mm C)",  20);
	AddItem (pTree, h1, "214-00370 Deciduous Shrub (No. 7)",  20);
	AddItem (pTree, h1, "214-00410 Evergreen Tree (No. 1)",  20);
	AddItem (pTree, h1, "214-00450 Evergreen Tree (No. 5)",  20);
	AddItem (pTree, h1, "214-00455 Install Evergreen Tree (No. 7)",  20);
	AddItem (pTree, h1, "214-00470 Evergreen Tree (No. 7)",  20);
	AddItem (pTree, h1, "214-00502 Evergreen Tree (0.6 m)(B-B)",  20);
	AddItem (pTree, h1, "214-00504 Evergreen Tree (1.2 m)(B-B)",  20);
	AddItem (pTree, h1, "214-00505 Furn Evergreen Tree (1.2 m)",  20);
	AddItem (pTree, h1, "214-00506 Evergreen Tree (1.8 m)(B-B)",  20);
	AddItem (pTree, h1, "214-00507 Furn Evergreen Tree (1.8 m)(B-B)",  20);
	AddItem (pTree, h1, "214-00508 Evergreen Tree (2.4 m)(B-B)",  20);
	AddItem (pTree, h1, "214-00509 Furn Evergreen Tree (2.4 m)(B-B)",  20);
	AddItem (pTree, h1, "214-00510 Evergreen Tree (3 m)(B-B)",  20);
	AddItem (pTree, h1, "214-00511 Furn Evergreen Tree (3 m)(B-B)",  20);
	AddItem (pTree, h1, "214-00512 Evergreen Tree (3.6 m)(B-B)",  20);
	AddItem (pTree, h1, "214-00514 Evergreen Tree (4.2 m)(B-B)",  20);
	AddItem (pTree, h1, "214-00601 Evergreen Shrub (Tubeling)",  20);
	AddItem (pTree, h1, "214-00610 Evergreen Shrub (No. 1)",  20);
	AddItem (pTree, h1, "214-00630 Evergreen Shrub (No. 3)",  20);
	AddItem (pTree, h1, "214-00650 Evergreen Shrub (No. 5)",  20);
	AddItem (pTree, h1, "214-00670 Evergreen Shrub (No. 7)",  20);
	AddItem (pTree, h1, "214-00701 Brdlf Evrgrn Shrub (Tubeling)",  20);
	AddItem (pTree, h1, "214-00710 Brdlf Evrgrn Shrub (No. 1)",  20);
	AddItem (pTree, h1, "214-00730 Brdlf Evrgrn Shrub (No. 3)",  20);
	AddItem (pTree, h1, "214-00750 Brdlf Evrgrn Shrub (No. 5)",  20);
	AddItem (pTree, h1, "214-00770 Brdlf Evrgrn Shrub (No. 7)",  20);
	AddItem (pTree, h1, "214-00801 Gr Cover Vines (Tubeling)",  20);
	AddItem (pTree, h1, "214-00805 Gr Cover Vines (56 mm Pot)",  20);
	AddItem (pTree, h1, "214-00810 Gr Cover Vines (No. 1)",  20);
	AddItem (pTree, h1, "214-00850 Gr Cover Vines (No. 5)",  20);
	AddItem (pTree, h1, "214-00901 Perennials (Tubeling)",  20);
	AddItem (pTree, h1, "214-00905 Perennials (56 mm Pot)",  20);
	AddItem (pTree, h1, "214-00908 Perennials (No. 0.25)",  20);
	AddItem (pTree, h1, "214-00910 Perennials (No. 1)",  20);
	AddItem (pTree, h1, "214-00950 Perennials (No. 5)",  20);
	AddItem (pTree, h1, "214-01000 Bulb",  20);
	AddItem (pTree, h1, "214-01010 Brush Layer Cutting",  20);
	AddItem (pTree, h1, "214-01011 Brush Layer Cutting",  20);
	AddItem (pTree, h1, "214-01015 Willow Cuttings",  20);
	AddItem (pTree, h1, "214-01020 Hedge Layer Plant",  20);
	AddItem (pTree, h1, "214-01025 Dormant Log Cutting",  20);
	AddItem (pTree, h1, "214-01030 Wattle",  20);
	AddItem (pTree, h1, "214-01140 Plant Shade Shelter",  20);
	AddItem (pTree, h1, "214-01200 Plant (Tubeling)",  20);
	AddItem (pTree, h1, "214-01210 Furn Plant (Tubeling)",  20);
	AddItem (pTree, h1, "214-01215 Inst Plant (Tubeling)",  20);
	AddItem (pTree, h1, "214-01220 Furn Plant (Bareroot)",  20);
	AddItem (pTree, h1, "214-01225 Inst Plant (Bareroot)",  20);
	AddItem (pTree, h1, "214-01230 Furn Plant (56 mm Pot)",  20);
	AddItem (pTree, h1, "214-01235 Inst Plant (56 mm Pot)",  20);
	AddItem (pTree, h1, "214-01310 Furn Plant (No. 1)",  20);
	AddItem (pTree, h1, "214-01315 Inst Plant (No. 1)",  20);
	AddItem (pTree, h1, "214-01350 Furn Plant (No. 5)",  20);
	AddItem (pTree, h1, "214-01355 Inst Plant (No. 5)",  20);
	AddItem (pTree, h1, "214-01370 Furn Plant (No. 7)",  20);
	AddItem (pTree, h1, "214-01375 Inst Plant (No. 7)",  20);
	AddItem (pTree, h1, "215-00000 Transplant Shrub",  20);
	AddItem (pTree, h1, "215-00001 Transplant Shrub",  20);
	AddItem (pTree, h1, "215-00010 Transplant Tree",  20);
	AddItem (pTree, h1, "215-00030 Transplant Tree (38-75 mm C)",  20);
	AddItem (pTree, h1, "215-00060 Transplant Tree (75-150 mm C)",  20);
	AddItem (pTree, h1, "215-00100 Transplant Tree (+150 mm C)",  20);
	AddItem (pTree, h1, "215-00200 Transplant Tree (B-B)",  20);
	AddItem (pTree, h1, "215-00500 Transplant Seedling",  20);
	AddItem (pTree, h1, "215-00600 Transplant Plug",  20);
	AddItem (pTree, h1, "216-00013 Mulch Netting (Plastic)",  20);
	AddItem (pTree, h1, "216-00015 Soil Reten Blanket (Excel)",  20);
	AddItem (pTree, h1, "216-00025 Soil Reten Blanket (Jute)",  20);
	AddItem (pTree, h1, "216-00030 Soil Reten Blanket (Spec)",  20);
	AddItem (pTree, h1, "216-00035 Soil Reten Blanket (Plastic)",  20);
	AddItem (pTree, h1, "216-00050 Soil Reten Grid",  20);
	AddItem (pTree, h1, "216-00060 Soil Reten System",  20);
	AddItem (pTree, h1, "216-00070 Geocell Confinement Sys",  20);
	AddItem (pTree, h1, "217-00000 Herbicide Treatment",  20);
	AddItem (pTree, h1, "217-00010 Pre-Emergent Herbicide",  20);
	AddItem (pTree, h1, "217-00020 Herbicide Treatment",  20);
	AddItem (pTree, h1, "217-00100 Root Control Fabric",  20);
	AddItem (pTree, h1, "250-00010 Envir Health/Safety Mngmt",  20);
	AddItem (pTree, h1, "250-00050 Monitoring Technician",  20);
	AddItem (pTree, h1, "250-00100 Environmental Health and Safety",  20);
	AddItem (pTree, h1, "250-00110 Health and Safety Officer",  20);
	AddItem (pTree, h1, "250-00120 Material Sampling and Delivery",  20);
	AddItem (pTree, h1, "250-00200 Material Handling (Stockpile)",  20);
	AddItem (pTree, h1, "250-00210 Solid Waste Disposal",  20);
	AddItem (pTree, h1, "250-00220 Hazardous Waste Disposal",  20);
	AddItem (pTree, h1, "250-00300 Water Treatment System",  20);
	AddItem (pTree, h1, "250-00310 Water Treatment",  20);
	AddItem (pTree, h1, "251-00000 Paint Testing and Analysis Mngmt",  20);
	AddItem (pTree, h1, "251-00010 Paint Rem and Disposal Mngmt",  20);
	AddItem (pTree, h1, "252-00010 Fug Petro Health/Safety Mngmt",  20);
	AddItem (pTree, h1, "253-00010 Asbestos Contain Matl Mngmt",  20);
	AddItem (pTree, h1, "255-00010 Paint Str Comp Rem/Disp Mngmt",  20);
	AddItem (pTree, h1, "301-06000 PMBB (CL 6)",  20);
	AddItem (pTree, h1, "301-06020 PMBB (CL 6) (Asph)",  20);
	AddItem (pTree, h1, "301-10020 PATB (Asph)",  20);
	AddItem (pTree, h1, "304-01000 ABC (CL 1)",  20);
	AddItem (pTree, h1, "304-01005 ABC (CL 1)",  20);
	AddItem (pTree, h1, "304-02000 ABC (CL 2)",  20);
	AddItem (pTree, h1, "304-02005 ABC (CL 2)",  20);
	AddItem (pTree, h1, "304-03000 ABC (CL 3)",  20);
	AddItem (pTree, h1, "304-03005 ABC (CL 3)",  20);
	AddItem (pTree, h1, "304-04000 ABC (CL 4)",  20);
	AddItem (pTree, h1, "304-05000 ABC (CL 5)",  20);
	AddItem (pTree, h1, "304-06000 ABC (CL 6)",  20);
	AddItem (pTree, h1, "304-06001 ABC (CL 6) (C)",  20);
	AddItem (pTree, h1, "304-06004 ABC (CL 6)",  20);
	AddItem (pTree, h1, "304-06007 ABC (CL 6)",  20);
	AddItem (pTree, h1, "304-06008 ABC (CL 6) (Spec)",  20);
	AddItem (pTree, h1, "304-06009 ABC (CL 6) (Spec)",  20);
	AddItem (pTree, h1, "304-07000 ABC (CL 7)",  20);
	AddItem (pTree, h1, "304-07009 ABC (CL 7) (Spec)",  20);
	AddItem (pTree, h1, "304-09000 ABC (Spec)",  20);
	AddItem (pTree, h1, "304-09014 ABC (Spec)",  20);
	AddItem (pTree, h1, "304-09020 ABC (Permeable)",  20);
	AddItem (pTree, h1, "304-09055 ABC (Blotter)",  20);
	AddItem (pTree, h1, "304-09200 Stockpile ABC (Spec)",  20);
	AddItem (pTree, h1, "304-09220 Stockpile ABC (Spec)",  20);
	AddItem (pTree, h1, "306-00000 Reconditioning",  20);
	AddItem (pTree, h1, "306-01000 Reconditioning",  20);
	AddItem (pTree, h1, "307-00000 Hydrated Lime",  20);
	AddItem (pTree, h1, "307-00200 Lime Tr Subgrade",  20);
	AddItem (pTree, h1, "307-00206 Lime Tr Subgrade (150 mm)",  20);
	AddItem (pTree, h1, "307-00208 Lime Tr Subgrade (200 mm)",  20);
	AddItem (pTree, h1, "307-00209 Lime Tr Subgrade (225 mm)",  20);
	AddItem (pTree, h1, "307-00210 Lime Tr Subgrade (250 mm)",  20);
	AddItem (pTree, h1, "307-00212 Lime Tr Subgrade (300 mm)",  20);
	AddItem (pTree, h1, "307-00250 Fly Ash Tr Subgrade",  20);
	AddItem (pTree, h1, "308-00001 Portland Cement",  20);
	AddItem (pTree, h1, "308-00100 Cement Tr Base",  20);
	AddItem (pTree, h1, "308-00500 Fiber Reinf Soilcrete",  20);
	AddItem (pTree, h1, "308-09000 Lean Concrete",  20);
	AddItem (pTree, h1, "309-10600 Lean Concrete Base (150 mm)",  20);
	AddItem (pTree, h1, "310-00400 Asphalt Mat For Base Course",  20);
	AddItem (pTree, h1, "403-00720 HBP (Patching) (Asph)",  20);
	AddItem (pTree, h1, "403-00721 HBP (Patching) (Asph)",  20);
	AddItem (pTree, h1, "403-01000 HBP (Asph) (3 Yr Warranty)",  20);
	AddItem (pTree, h1, "403-01010 HBP (Asph) (5 Yr Warranty)",  20);
	AddItem (pTree, h1, "403-01020 HBP (Asph) (10 Yr Warranty)",  20);
	AddItem (pTree, h1, "403-03000 HBP (Gr C)",  20);
	AddItem (pTree, h1, "403-03020 HBP (Gr C) (Asph)",  20);
	AddItem (pTree, h1, "403-03024 HBP (Gr C) (Asph) (R)",  20);
	AddItem (pTree, h1, "403-03026 HBP (Gr C) (Asph) (P)",  20);
	AddItem (pTree, h1, "403-03027 HBP (Gr C) (Asph-HL) (P)",  20);
	AddItem (pTree, h1, "403-03569 HBP (Gr C) (Asph) (Spec)",  20);
	AddItem (pTree, h1, "403-03570 HBP (Gr C) (Asph) (Spec)",  20);
	AddItem (pTree, h1, "403-03571 HBP (Gr C) (Asph) (R) (Spec)",  20);
	AddItem (pTree, h1, "403-03610 HBP (Gr CX)",  20);
	AddItem (pTree, h1, "403-03620 HBP (Gr CX) (Asph)",  20);
	AddItem (pTree, h1, "403-03622 HBP (Gr CX) (Asph-HL)",  20);
	AddItem (pTree, h1, "403-03624 HBP (Gr CX) (Asph) (R)",  20);
	AddItem (pTree, h1, "403-03626 HBP (Gr CX) (Asph) (P)",  20);
	AddItem (pTree, h1, "403-03670 HBP (Gr CX) (Asph) (Spec)",  20);
	AddItem (pTree, h1, "403-06020 HBP (Gr F) (Asph)",  20);
	AddItem (pTree, h1, "403-06570 HBP (Gr F) (Asph) (Spec)",  20);
	AddItem (pTree, h1, "403-07010 HBP (Gr G)",  20);
	AddItem (pTree, h1, "403-07020 HBP (Gr G) (Asph)",  20);
	AddItem (pTree, h1, "403-09110 SMA",  20);
	AddItem (pTree, h1, "403-09120 SMA (Vesto Plast) (Asph)",  20);
	AddItem (pTree, h1, "403-09121 SMA (Fibers) (Asph)",  20);
	AddItem (pTree, h1, "403-09126 SMA (Asph) (P)",  20);
	AddItem (pTree, h1, "403-09500 Furnish HBP",  20);
	AddItem (pTree, h1, "403-09600 HBP (Bond Breaker)",  20);
	AddItem (pTree, h1, "403-10000 Longitudinal Joint Test",  20);
	AddItem (pTree, h1, "403-11020 HBP (Gr C) (Asph) (Rumac)",  20);
	AddItem (pTree, h1, "403-11121 HBP (Gr C) (Asph) (Rumac) (1% Crm)",  20);
	AddItem (pTree, h1, "403-11122 HBP (Gr C) (Asph) (Rumac) (2% Crm)",  20);
	AddItem (pTree, h1, "403-11123 HBP (Gr C) (Asph) (Rumac) (3% Crm)",  20);
	AddItem (pTree, h1, "403-11300 HBP (Gr C) (C 170)",  20);
	AddItem (pTree, h1, "403-11320 HBP (Gr C) (Asph) (C 170)",  20);
	AddItem (pTree, h1, "403-11324 HBP (Gr C) (Asph) (R) (C 170)",  20);
	AddItem (pTree, h1, "403-11326 HBP (Gr C) (Asph) (P) (C 170)",  20);
	AddItem (pTree, h1, "403-11370 HBP (Gr C) (Asph) (Spec) (C 170)",  20);
	AddItem (pTree, h1, "403-11400 HBP (Gr CX) (C 170)",  20);
	AddItem (pTree, h1, "403-11420 HBP (Gr CX) (Asph) (C 170)",  20);
	AddItem (pTree, h1, "403-11424 HBP (Gr CX) (Asph) (R) (C 170)",  20);
	AddItem (pTree, h1, "403-11426 HBP (Gr CX) (Asph) (P) (C 170)",  20);
	AddItem (pTree, h1, "403-11470 HBP (Gr CX) (Asph) (Spec) (C 170)",  20);
	AddItem (pTree, h1, "403-12300 HBP (Gr C) (C 340)",  20);
	AddItem (pTree, h1, "403-12320 HBP (Gr C) (Asph) (C 340)",  20);
	AddItem (pTree, h1, "403-12324 HBP (Gr C) (Asph) (R) (C 340)",  20);
	AddItem (pTree, h1, "403-12326 HBP (Gr C) (Asph) (P) (C 340)",  20);
	AddItem (pTree, h1, "403-12370 HBP (Gr C) (Asph) (Spec) (C 340)",  20);
	AddItem (pTree, h1, "403-12371 HBP (Gr C) (Asph) (R) (Spec) (C 340)",  20);
	AddItem (pTree, h1, "403-12400 HBP (Gr CX) (C 340)",  20);
	AddItem (pTree, h1, "403-12420 HBP (Gr CX) (Asph) (C 340)",  20);
	AddItem (pTree, h1, "403-12424 HBP (Gr CX) (Asph) (R) (C 340)",  20);
	AddItem (pTree, h1, "403-12426 HBP (Gr CX) (Asph) (P) (C 340)",  20);
	AddItem (pTree, h1, "403-12470 HBP (Gr CX) (Asph) (Spec) (C 340)",  20);
	AddItem (pTree, h1, "403-12520 HBP (Gr Fines) (Asph) (C 340)",  20);
	AddItem (pTree, h1, "403-13300 HBP (Gr C) (Asph) (C 520)",  20);
	AddItem (pTree, h1, "403-13301 HBP (Gr C) (C 520)",  20);
	AddItem (pTree, h1, "403-13320 HBP (Gr C) (Asph) (C 520)",  20);
	AddItem (pTree, h1, "403-13321 HBP (Gr C) (Asph) (C 520)",  20);
	AddItem (pTree, h1, "403-13324 HBP (Gr C) (Asph) (R) (C 520)",  20);
	AddItem (pTree, h1, "403-13326 HBP (Gr C) (Asph) (P) (C 520)",  20);
	AddItem (pTree, h1, "403-13342 HBP (Gr C) (Asph) (C 520) (PG 64-28)",  20);
	AddItem (pTree, h1, "403-13344 HBP (Gr C) (Asph) (C 520) (PG 70-34)",  20);
	AddItem (pTree, h1, "403-13370 HBP (Gr C) (Asph) (Spec)",  20);
	AddItem (pTree, h1, "403-13371 HBP (Gr C) (Asph) (R) (S) (C 520)",  20);
	AddItem (pTree, h1, "403-13400 HBP (Gr CX) (C 520)",  20);
	AddItem (pTree, h1, "403-13420 HBP (Gr CX) (Asph) (C 520)",  20);
	AddItem (pTree, h1, "403-13424 HBP (Gr CX) (Asph) (R) (C 520)",  20);
	AddItem (pTree, h1, "403-13426 HBP (Gr CX) (Asph) (P) (C 520)",  20);
	AddItem (pTree, h1, "403-13470 HBP (Gr CX) (Asph) (Spec) (C 520)",  20);
	AddItem (pTree, h1, "403-14300 HBP (Gr C) (C 690)",  20);
	AddItem (pTree, h1, "403-14320 HBP (Gr C) (Asph) (C 690)",  20);
	AddItem (pTree, h1, "403-14324 HBP (Gr C) (Asph) (R) (C 690)",  20);
	AddItem (pTree, h1, "403-14326 HBP (Gr C) (Asph) (P) (C 690)",  20);
	AddItem (pTree, h1, "403-14342 HBP (Gr C) (Asph) (C 690) (PG 64-28)",  20);
	AddItem (pTree, h1, "403-14344 HBP (Gr C) (Asph) (C 690) (PG 70-34)",  20);
	AddItem (pTree, h1, "403-14370 HBP (Gr C) (Asph) (Spec) (C 690)",  20);
	AddItem (pTree, h1, "403-14371 HBP (Gr C) (Asph) (R) (Spec) (C 690)",  20);
	AddItem (pTree, h1, "403-14400 HBP (Gr CX) (C 690)",  20);
	AddItem (pTree, h1, "403-14420 HBP (Gr CX) (Asph) (C 690)",  20);
	AddItem (pTree, h1, "403-14424 HBP (Gr CX) (Asph) (P) (C 690)",  20);
	AddItem (pTree, h1, "403-14426 HBP (Gr CX) (Asph) (P) (C 690)",  20);
	AddItem (pTree, h1, "403-14470 HBP (Gr CX) (Asph) (Spec) (C 690)",  20);
	AddItem (pTree, h1, "403-15300 HBP (Gr C) (C 860)",  20);
	AddItem (pTree, h1, "403-15320 HBP (Gr C) (Asph) (C 860)",  20);
	AddItem (pTree, h1, "403-15321 HBP (Gr C) (Asph) (C 860)",  20);
	AddItem (pTree, h1, "403-15324 HBP (Gr C) (Asph) (R) (C 860)",  20);
	AddItem (pTree, h1, "403-15326 HBP (Gr C) (Asph) (P) (C 860)",  20);
	AddItem (pTree, h1, "403-15370 HBP (Gr C) (Asph) (Spec) (C 860)",  20);
	AddItem (pTree, h1, "403-15400 HBP (Gr CX) (C 860)",  20);
	AddItem (pTree, h1, "403-15420 HBP (Gr CX) (Asph) (C 860)",  20);
	AddItem (pTree, h1, "403-22320 HBP (Gr SP 19) (Asph) (76)",  20);
	AddItem (pTree, h1, "403-22445 HBP (Gr SP 12.5) (Asph) (76) (PG 76-28)",  20);
	AddItem (pTree, h1, "403-23320 HBP (Gr SP 19) (Asph) (86)",  20);
	AddItem (pTree, h1, "403-24400 HBP (Gr SP 12.5) (96)",  20);
	AddItem (pTree, h1, "403-25320 HBP (Gr SP 19) (Asph) (109)",  20);
	AddItem (pTree, h1, "403-25342 HBP (Gr SP 19) (Asph) (109) (PG 64-28)",  20);
	AddItem (pTree, h1, "403-25344 HBP (Gr SP 19) (Asph) (109) (PG 70-34)",  20);
	AddItem (pTree, h1, "403-31300 HBP (Gr S) (68)",  20);
	AddItem (pTree, h1, "403-31341 HBP (Gr S) (Asph) (68) (PG 58-40)",  20);
	AddItem (pTree, h1, "403-31351 HPB (Gr S) (Asph) (68) (PG 58-28)",  20);
	AddItem (pTree, h1, "403-31400 HBP (Gr SX) (68)",  20);
	AddItem (pTree, h1, "403-31453 HBP (Gr SX) (Asph) (68) (PG 58-22)",  20);
	AddItem (pTree, h1, "403-32254 HBP (Gr SG) (Asph) (76) (PG 64-22)",  20);
	AddItem (pTree, h1, "403-32300 HBP (Gr S) (76)",  20);
	AddItem (pTree, h1, "403-32324 HBP (Gr S) (Asph) (76) (AC-20R)",  20);
	AddItem (pTree, h1, "403-32341 HBP (Gr S) (Asph) (76) (PG 58-40)",  20);
	AddItem (pTree, h1, "403-32342 HBP (Gr S) (Asph) (76) (PG 64-28)",  20);
	AddItem (pTree, h1, "403-32352 HBP (Gr S) (Asph) (76) (PG 58-28)",  20);
	AddItem (pTree, h1, "403-32353 HBP (Gr S) (Asph) (76) (PG 58-22)",  20);
	AddItem (pTree, h1, "403-32354 HBP (Gr S) (Asph) (76) (PG 64-22)",  20);
	AddItem (pTree, h1, "403-32400 HBP (Gr SX) (76)",  20);
	AddItem (pTree, h1, "403-32424 HBP (Gr SX) (Asph) (AC-20R)",  20);
	AddItem (pTree, h1, "403-32446 HBP (Gr SX) (Asph) (76) (PG 64-22)",  20);
	AddItem (pTree, h1, "403-32453 HBP (Gr SX) (Asph) (76) (PG 58-22)",  20);
	AddItem (pTree, h1, "403-32545 HBP(Gr Sand Anti Frac) (Asph) (PG 76-28",  20);
	AddItem (pTree, h1, "403-33254 HBP (Gr SG) (Asph) (86) (PG 64-22)",  20);
	AddItem (pTree, h1, "403-33324 HBP (Gr S) (Asph) (86) (AC-20R)",  20);
	AddItem (pTree, h1, "403-33341 HBP (Gr S) (Asph) (86) (PG 58-40)",  20);
	AddItem (pTree, h1, "403-33342 HBP (Gr S) (Asph) (86) (PG 64-28)",  20);
	AddItem (pTree, h1, "403-33344 HBP (Gr S) (Asph) (86) (PG 70-34)",  20);
	AddItem (pTree, h1, "403-33345 HBP (Gr S) (Asph) (86) (PG 76-28)",  20);
	AddItem (pTree, h1, "403-33352 HBP (Gr S) (Asph) (86) (PG 58-28)",  20);
	AddItem (pTree, h1, "403-33353 HBP (Gr S) (Asph) (86) (PG 58-22)",  20);
	AddItem (pTree, h1, "403-33354 HBP (Gr S) (Asph) (86) (PG 64-22)",  20);
	AddItem (pTree, h1, "403-33400 HBP (Gr SX) (86)",  20);
	AddItem (pTree, h1, "403-33441 HBP (Gr SX) (Asph) (86) (PG 58-40)",  20);
	AddItem (pTree, h1, "403-33444 HBP (Gr SX) (Asph) (86) (PG 70-34)",  20);
	AddItem (pTree, h1, "403-33451 HBP (Gr SX) (Asph) (86) (PG 52-28)",  20);
	AddItem (pTree, h1, "403-33452 HBP (Gr SX) (Asph) (86) (PG 58-28)",  20);
	AddItem (pTree, h1, "403-33453 HBP (Gr SX) (Asph) (86) (PG 58-22)",  20);
	AddItem (pTree, h1, "403-33641 HBP (Gr S-Fines) (Asph) (86) (PG 58-40)",  20);
	AddItem (pTree, h1, "403-33652 HBP (Gr S-Fines) (Asph) (86) (PG 58-28)",  20);
	AddItem (pTree, h1, "403-34253 HBP (Gr SG) (Asph) (96) (PG 58-22)",  20);
	AddItem (pTree, h1, "403-34254 HBP (Gr SG) (Asph) (96) (PG 64-22)",  20);
	AddItem (pTree, h1, "403-34324 HBP (Gr S) (Asph) (96) (AC-20R)",  20);
	AddItem (pTree, h1, "403-34341 HBP (Gr S) (Asph) (96) (PG 58-40)",  20);
	AddItem (pTree, h1, "403-34342 HBP (Gr S) (Asph) (96) (PG 64-28)",  20);
	AddItem (pTree, h1, "403-34344 HBP (Gr S) (Asph) (96) (PG 70-34)",  20);
	AddItem (pTree, h1, "403-34345 HBP (Gr S) (Asph) (96) (PG 76-28)",  20);
	AddItem (pTree, h1, "403-34352 HBP (Gr S) (Asph) (96) (PG 58-28)",  20);
	AddItem (pTree, h1, "403-34353 HBP (Gr S) (Asph) (96) (PG 58-22)",  20);
	AddItem (pTree, h1, "403-34354 HBP (Gr S) (Asph) (96) (PG 64-22)",  20);
	AddItem (pTree, h1, "403-34400 HBP (Gr SX) (96)",  20);
	AddItem (pTree, h1, "403-34441 HBP (Gr SX) (Asph) (96) (PG 58-40)",  20);
	AddItem (pTree, h1, "403-34444 HBP (Gr SX) (Asph) (96) (PG 70-34)",  20);
	AddItem (pTree, h1, "403-34452 HBP (Gr SX) (Asph) (96) (PG 58-28)",  20);
	AddItem (pTree, h1, "403-34453 HBP (Gr SX) (Asph) (96) (PG 58-22)",  20);
	AddItem (pTree, h1, "403-34454 HBP (Gr SX) (Asph) (96) (PG 64-22)",  20);
	AddItem (pTree, h1, "403-34652 HBP (Gr S-Fines) (Asph) (96) (PG 58-28)",  20);
	AddItem (pTree, h1, "403-35300 HBP (Gr S) (109)",  20);
	AddItem (pTree, h1, "403-35324 HBP (Gr S) (Asph) (109) (AC-20R)",  20);
	AddItem (pTree, h1, "403-35342 HBP (Gr S) (Asph) (109) (PG 64-28)",  20);
	AddItem (pTree, h1, "403-35344 HBP (Gr S) (Asph) (109) (PG 70-34)",  20);
	AddItem (pTree, h1, "403-35345 HBP (Gr S) (Asph) (109) (PG 76-28)",  20);
	AddItem (pTree, h1, "403-35353 HBP (Gr S) (Asph) (109) (PG 58-22)",  20);
	AddItem (pTree, h1, "403-35354 HBP (Gr S) (Asph) (109) (PG 64-22)",  20);
	AddItem (pTree, h1, "403-35400 HBP (Gr SX) (109)",  20);
	AddItem (pTree, h1, "403-35445 HBP (Gr SX) (Asph) (109) (PG 76-28)",  20);
	AddItem (pTree, h1, "403-35452 HBP (Gr SX) (Asph) (109) (PG 58-28)",  20);
	AddItem (pTree, h1, "403-37354 HBP (Gr S) (Asph) (96) (PG 64-22)",  20);
	AddItem (pTree, h1, "403-37545 HBP (Gr SAF) (Asph) (50) (PG 76-28)",  20);
	AddItem (pTree, h1, "403-91401 HBP (Gr SX) (68) (Spec)",  20);
	AddItem (pTree, h1, "403-92441 HBP (Gr SX) (76) (PG 58-40) (Spec)",  20);
	AddItem (pTree, h1, "403-95353 HBP (Gr S) (Asph) (109) (PG 58-22)(Spec)",  20);
	AddItem (pTree, h1, "405-00000 Heating and Scarifying",  20);
	AddItem (pTree, h1, "405-00100 Heating and Remixing Treatment",  20);
	AddItem (pTree, h1, "405-00300 Heating and Repaving Treatment",  20);
	AddItem (pTree, h1, "406-09500 Cold Bitum Pvmt (Recycle)",  20);
	AddItem (pTree, h1, "406-09505 Cold Bitum Pvmt (Recycle)(Spec)",  20);
	AddItem (pTree, h1, "406-09530 Repair of Cold Bitum Pvmt (Recycle)",  20);
	AddItem (pTree, h1, "407-03000 Blotter Material",  20);
	AddItem (pTree, h1, "407-04000 Coal-Tar Seal/Rejuvinator (Airport)",  20);
	AddItem (pTree, h1, "407-09000 Crackfiller (Application)",  20);
	AddItem (pTree, h1, "408-01000 Hot Joint-Crack Sealant",  20);
	AddItem (pTree, h1, "408-01100 Crack Sealant (Polyurthn)",  20);
	AddItem (pTree, h1, "408-01200 Cold Joint-Crack Sealant",  20);
	AddItem (pTree, h1, "408-01300 HBP Mix Crack Sealant",  20);
	AddItem (pTree, h1, "408-01400 Crack Sealant (Special)",  20);
	AddItem (pTree, h1, "408-02000 Injection Holes",  20);
	AddItem (pTree, h1, "409-00110 Stockpile CC Matl",  20);
	AddItem (pTree, h1, "409-01010 CC Matl (Ty I)",  20);
	AddItem (pTree, h1, "409-01015 CC Matl (Ty I)",  20);
	AddItem (pTree, h1, "409-01020 CC Matl (Ty I) (Lightweight)",  20);
	AddItem (pTree, h1, "409-02010 CC Matl (Ty II)",  20);
	AddItem (pTree, h1, "409-02015 CC Matl (Ty II)",  20);
	AddItem (pTree, h1, "409-02020 CC Matl (Ty II) (Lightweight)",  20);
	AddItem (pTree, h1, "409-02025 CC Matl (Ty II) (Lightweight)",  20);
	AddItem (pTree, h1, "409-02050 CC Matl (Ty II) (Special)",  20);
	AddItem (pTree, h1, "409-03010 CC Matl (Ty III)",  20);
	AddItem (pTree, h1, "409-03050 Place CC Matl",  20);
	AddItem (pTree, h1, "409-03060 Furn CC Matl",  20);
	AddItem (pTree, h1, "409-04010 CC Matl (Ty IV)",  20);
	AddItem (pTree, h1, "409-04050 CC Matl (Spec)",  20);

	h1 = AddItem (pTree, h0,       "Cost Sheet Catalog", 		12);
	h1 = AddItem (pTree, h0,       "Bid History Catalog", 	13);
	h1 = AddItem (pTree, h0,       "Reference Price Catalog",14);
	h1 = AddItem (pTree, h0,       "Materials Catalog", 		15);
	h1 = AddItem (pTree, h0,       "Equipment Catalog", 		16);
	h1 = AddItem (pTree, h0,       "Labor Catalog", 			17);
	h1 = AddItem (pTree, h0,       "User Catalog", 				18);
	h1 = AddItem (pTree, h0,       "Code Table Catalogs",    19);
	AddItem (pTree, h1, "County Catalog ",  190);
	AddItem (pTree, h1, "Unit Catalog",  191);
	AddItem (pTree, h1, "Work Type Catalog",  192);
	AddItem (pTree, h1, "Highway Type Catalog",  193);
}


// --- OnInitDialog() -----------------------------------------------
// 
BOOL CTV_CatPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	Init();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


// --- SwitchView() -------------------------------------------------
// 
void CTV_CatPage::SwitchView(LONG lNewType)
{
	CMainFrame* pFrmWnd = (CMainFrame*) GetParentFrame();
	if (pFrmWnd == NULL)
		return;

	if ((*m_pPaneType != 1) && (*m_pPaneType != 2) && (*m_pPaneType != 3))
		pFrmWnd->m_wndSplitter.DeleteView(0,1);
	*m_pPaneType = lNewType;

	delete *m_ppSplitter;
	(*m_ppSplitter) = NULL;

	switch(*m_pPaneType)
	{
	case 1:
		// Estimation ---
		{
			*m_ppSplitter = new CSplitterWnd;
			(*m_ppSplitter)->CreateStatic(&(pFrmWnd->m_wndSplitter), 2, 1, 
											  WS_CHILD | WS_VISIBLE | WS_BORDER,
											  pFrmWnd->m_wndSplitter.IdFromRowCol(0, 1));
//			(*m_ppSplitter)->CreateView(0, 0, RUNTIME_CLASS(CEstimateView), CSize(0, 190), NULL);
			(*m_ppSplitter)->CreateView(0, 0, RUNTIME_CLASS(CDV_Est), CSize(0, 190), NULL);

			(*m_ppSplitter)->CreateView(1, 0, RUNTIME_CLASS(CLV_GroupList), CSize(0, 0), NULL);

			(*m_ppSplitter)->RecalcLayout();

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
			(*m_ppSplitter)->CreateView(0, 0, RUNTIME_CLASS(CDV_Group), CSize(0, 160), NULL);
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
			(*m_ppSplitter)->CreateView(0, 0, RUNTIME_CLASS(CDV_Group), CSize(0, 160), NULL);
			(*m_ppSplitter)->CreateView(1, 0, RUNTIME_CLASS(CLV_CostList), CSize(0, 0), NULL);

			(*m_ppSplitter)->RecalcLayout();

			CLV_ItemList* pList = (CLV_ItemList*) (*m_ppSplitter)->GetPane(1, 0);
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


// ------------------------ CTV_Sheet ------------------------------

