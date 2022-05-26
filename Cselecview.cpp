// Cselecview.cpp: 实现文件
//

#include "pch.h"
#include "SalaSystem.h"
#include "Cselecview.h"


#include "MainFrm.h"


#include"Judgeuser.h"
// Cselecview

IMPLEMENT_DYNCREATE(Cselecview, CTreeView)

Cselecview::Cselecview()
{

}

Cselecview::~Cselecview()
{
}

BEGIN_MESSAGE_MAP(Cselecview, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &Cselecview::OnTvnSelchanged)

	ON_WM_NCHITTEST()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// Cselecview 诊断

#ifdef _DEBUG
void Cselecview::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void Cselecview::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// Cselecview 消息处理程序


void Cselecview::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	int flag = out_judge();
	//初始化
	if (flag == 1)
	{
		m_treeCral = &GetTreeCtrl();

		//添加节点


		m_treeCral->InsertItem(TEXT("个人信息"), 0, 0, NULL);
		m_treeCral->InsertItem(TEXT("销售信息"), 0, 0, NULL);
		m_treeCral->InsertItem(TEXT("库存信息"), 0, 0, NULL);
		m_treeCral->InsertItem(TEXT("库存添加"), 0, 0, NULL);
		m_treeCral->InsertItem(TEXT("售卖产品"), 0, 0, NULL);
	}
	else
	{
		m_treeCral = &GetTreeCtrl();

		//添加节点

		//m_treeCral->InsertItem(TEXT("购物车"), 0, 0, NULL);
		m_treeCral->InsertItem(TEXT("个人信息"), 0, 0, NULL);
		m_treeCral->InsertItem(TEXT("库存信息"), 0, 0, NULL);
		m_treeCral->InsertItem(TEXT("售卖产品"), 0, 0, NULL);
	}
	


	// TODO: 在此添加专用代码和/或调用基类

	CString sPath = _T("./land.jpg");
	CImage img;
	img.Load(sPath);
	HBITMAP hbmp = img.Detach();
	CBitmap bmp;
	bmp.Attach(hbmp);
	m_bgBrush.CreatePatternBrush(&bmp);
}


void Cselecview::OnTvnSelchanged(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	HTREEITEM item = m_treeCral->GetSelectedItem();

	CString str = m_treeCral->GetItemText(item);

	//MessageBox(str);
	if (str == TEXT("个人信息"))
	{
		
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(),N_A,(WPARAM)N_A, (LPARAM)0);
	}
	else if (str == TEXT("库存添加"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), N_B, (WPARAM)N_B, (LPARAM)0);
	}
	else if (str == TEXT("售卖产品"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), N_C, (WPARAM)N_C, (LPARAM)0);
	}
	else if (str == TEXT("库存信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), N_D, (WPARAM)N_D, (LPARAM)0);
	}
	else if (str == TEXT("销售信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), N_E, (WPARAM)N_E, (LPARAM)0);
	}

}



LRESULT Cselecview::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CTreeView::OnNcHitTest(point);
}


HBRUSH Cselecview::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CTreeView::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd == this)
	{
		return m_bgBrush;
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
