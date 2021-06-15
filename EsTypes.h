// EsTypes.h
// Holds information about the tree node



#ifndef TREE_DATA_H
#define TREE_DATA_H


#include <afxwin.h>



struct CNodeData
{
	typedef enum	{TreeNodeEstimate, TreeNodeGroup, TreeNodeItem}	TreeNodeType;
		
	TreeNodeType		m_type;	

};



class CEstimateItem
{

};

typedef CList<CEstimateItem*, CEstimateItem*>	ItemList;



class CEstimateGroup
{
	ItemList		m_itemList;

	CString		m_strName;
};

typedef CList<CEstimateGroup*, CEstimateGroup*>	GroupList;



class CEstimate
{
public:
	CString		m_strName;
	CString		m_strEstimator;
	CString		m_strContractNumber;
	CString		m_strCounty;
	double		m_dTotal;

	GroupList	m_groupList;
};









// Do not write anything after this line ----------------------------
#endif	// TREE_DATA_H
