#pragma once
#include <afxcmn.h>
class CSort : public CListCtrl
{
public:
	CSort(void);

	BOOL m_fAsc;		//是否顺序排序
	int m_nSortedCol;	//当前排序的列


	~CSort(void);
};

