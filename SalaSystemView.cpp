
// SalaSystemView.cpp: CSalaSystemView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SalaSystem.h"
#endif

#include "SalaSystemDoc.h"
#include "SalaSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSalaSystemView

IMPLEMENT_DYNCREATE(CSalaSystemView, CView)

BEGIN_MESSAGE_MAP(CSalaSystemView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSalaSystemView 构造/析构

CSalaSystemView::CSalaSystemView() noexcept
{
	// TODO: 在此处添加构造代码

}

CSalaSystemView::~CSalaSystemView()
{
}

BOOL CSalaSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSalaSystemView 绘图

void CSalaSystemView::OnDraw(CDC* /*pDC*/)
{
	CSalaSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CSalaSystemView 打印

BOOL CSalaSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSalaSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSalaSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CSalaSystemView 诊断

#ifdef _DEBUG
void CSalaSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CSalaSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSalaSystemDoc* CSalaSystemView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSalaSystemDoc)));
	return (CSalaSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CSalaSystemView 消息处理程序
