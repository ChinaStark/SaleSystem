#pragma once
#include <afxcmn.h>
class CSort : public CListCtrl
{
public:
	CSort(void);

	BOOL m_fAsc;		//�Ƿ�˳������
	int m_nSortedCol;	//��ǰ�������


	~CSort(void);
};

