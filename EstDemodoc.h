// EstDemoDoc.h : interface of the CEstDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPSHEET1DOC_H__B7ABA5B7_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_)
#define AFX_PROPSHEET1DOC_H__B7ABA5B7_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//
//
//
class CPriceBasis
	{
	CString 	  m_sPriceBasisID;
	// whatever
	};
typedef CList<CPriceBasis*,CPriceBasis*&> CPriceList;

//
//
//
class CItem
	{
public:
	CItem ();
	~CItem ();

	CString 	  m_sLineNumber;
	CString 	  m_sItemNumber;
	CString 	  m_sAltCode;
	CString 	  m_sUnit;
	CString 	  m_sDescription;
	CString 	  m_sSupplimentalDesc;
	double     m_fQuantity;
	double     m_fUnitPrice;
	double     m_fExtension;
	DWORD		  m_dwFlags;

	CPriceList m_cPriceList;
	};
typedef CList<CItem*,CItem*&> CItemList;

//
//
//
class CGroup
	{
public:
	CGroup();
	~CGroup();

	CString	  m_sGroupID;
	CString	  m_sGroupName;
	CString	  m_sDescription;
	double     m_fTotal;

	CItemList  m_cItemList;
	DWORD		  m_dwFlags;
	};
typedef CList<CGroup*,CGroup*&> CGroupList;

//
//
//
class CEstimate
	{
public:
	CEstimate();
	~CEstimate();

	CString	  m_sEstimateID;
	CString	  m_sEstimateName;
	CString	  m_sDescription;
	CString	  m_sWorkType;
	CString	  m_sHighwayType;
	CString	  m_sCounty;
	CString	  m_sEstimatedBy;
	CString	  m_sCheckedBy;
	CString	  m_sApprovedBy;
	CString	  m_sNotes;
	CTime		  m_dDate;
	CTime		  m_dEstimatedDate;
	CTime		  m_dCheckedDate;
	CTime		  m_dApprovedDate;
	double     m_fEstimateCost;
	double     m_fContingency;
	double     m_fTotal;
	DWORD		  m_dwFlags;

	CGroupList m_cGroupList;
	};


class CEstDemoDoc : public CDocument
{
protected: // create from serialization only
	CEstDemoDoc();
	DECLARE_DYNCREATE(CEstDemoDoc)

// Attributes
public:
	CEstimate *m_pEstimate;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEstDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEstDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEstDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPSHEET1DOC_H__B7ABA5B7_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_)
