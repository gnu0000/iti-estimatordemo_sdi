// EstDemoView.cpp : implementation of the CEstDemoView class
//

#include "stdafx.h"
#include "EstDemo.h"

#include "EstDemoDoc.h"
#include "EstDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEstDemoView

IMPLEMENT_DYNCREATE(CEstDemoView, CView)

BEGIN_MESSAGE_MAP(CEstDemoView, CView)
	//{{AFX_MSG_MAP(CEstDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEstDemoView construction/destruction

CEstDemoView::CEstDemoView()
{
	// TODO: add construction code here

}

CEstDemoView::~CEstDemoView()
{
}

BOOL CEstDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEstDemoView drawing

void CEstDemoView::OnDraw(CDC* pDC)
{
	CEstDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEstDemoView printing

BOOL CEstDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEstDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEstDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEstDemoView diagnostics

#ifdef _DEBUG
void CEstDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CEstDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEstDemoDoc* CEstDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEstDemoDoc)));
	return (CEstDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEstDemoView message handlers
