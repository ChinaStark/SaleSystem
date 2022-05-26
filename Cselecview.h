#pragma once
#include "afxcview.h"

// Cselecview 视图

class Cselecview : public CTreeView
{
	DECLARE_DYNCREATE(Cselecview)

protected:
	Cselecview();           // 动态创建所使用的受保护的构造函数
	virtual ~Cselecview();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl* m_treeCral;
	virtual void OnInitialUpdate();
	afx_msg void OnTvnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);

	CBrush m_bgBrush;

	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};


