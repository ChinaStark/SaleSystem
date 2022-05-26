// Cdisplay.cpp: 实现文件
//

#include "pch.h"
#include "SalaSystem.h"
#include "Cdisplay.h"


// Cdisplay

IMPLEMENT_DYNCREATE(Cdisplay, CFormView)

Cdisplay::Cdisplay()
	: CFormView(IDD_Cdisplay)
{

}

Cdisplay::~Cdisplay()
{
}

void Cdisplay::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cdisplay, CFormView)
END_MESSAGE_MAP()


// Cdisplay 诊断

#ifdef _DEBUG
void Cdisplay::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void Cdisplay::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// Cdisplay 消息处理程序
