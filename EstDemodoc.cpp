// EstDemoDoc.cpp : implementation of the CEstDemoDoc class
//

#include "stdafx.h"
#include "EstDemo.h"

#include "EstDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////

CItem::CItem()
	{
	}

CItem::~CItem()
	{
	}

CGroup::CGroup()
	{
	}

CGroup::~CGroup()
	{
	}

CEstimate::CEstimate()
	{
	}

CEstimate::~CEstimate()
	{
	}

/////////////////////////////////////////////////////////////////////////////
// CEstDemoDoc

IMPLEMENT_DYNCREATE(CEstDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CEstDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CEstDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEstDemoDoc construction/destruction

CEstDemoDoc::CEstDemoDoc()
	{
	// TODO: add one-time construction code here

	m_pEstimate = NULL;
	}

CEstDemoDoc::~CEstDemoDoc()
{
}

BOOL CEstDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	if (m_pEstimate)
		delete m_pEstimate;

	m_pEstimate = new CEstimate;


	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEstDemoDoc serialization

void CEstDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEstDemoDoc diagnostics

#ifdef _DEBUG
void CEstDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEstDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEstDemoDoc commands
