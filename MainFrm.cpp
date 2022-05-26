
// MainFrm.cpp: CMainFrame 类的实现
//

#include "pch.h"
#include "framework.h"
#include "SalaSystem.h"

#include "MainFrm.h"


#include "Cdisplay.h"
#include "Cselecview.h"
#include "CUser.h"
#include"CSell.h"
#include"CSell_out.h"
#include "Cinfo.h"
#include "CNULL.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_MESSAGE(N_A, OnMyChange)
	ON_MESSAGE(N_B, OnMyChange)
	ON_MESSAGE(N_C, OnMyChange)
	ON_MESSAGE(N_D, OnMyChange)
	ON_MESSAGE(N_E, OnMyChange)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame() noexcept
{
	// TODO: 在此添加成员初始化代码
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	//设置窗口的位置和大小：CWnd::MoveWindow
	//0, 0, 起点坐标x和y
	//800, 500, 窗口宽度和高度
	MoveWindow(0, 0, 1200, 700);

	//将窗口移动到屏幕中央，CWnd::CenterWindow
	CenterWindow();

	SetTitle(TEXT("2021/11/23"));
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	m_splite.CreateStatic(this, 1,2);
	m_splite.CreateView(0, 0, RUNTIME_CLASS(Cselecview), CSize(100, 700), pContext);
	m_splite.CreateView(0,1, RUNTIME_CLASS(Cdisplay), CSize(900, 700), pContext);
	return TRUE;//自己拆分
}

LRESULT CMainFrame::OnMyChange(WPARAM wParam, LPARAM IParam)
{

	if (wParam == N_A)
	{
		CCreateContext Context;
		//MessageBox(TEXT("个人信息"));
		Context.m_pNewViewClass = RUNTIME_CLASS(CUser);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView*)m_splite.GetPane(0, 1);
		m_splite.DeleteView(0, 1);
		m_splite.CreateView(0, 1, RUNTIME_CLASS(CUser), CSize(900, 700), &Context);
		CUser* pNewView = (CUser*)m_splite.GetPane(0, 1);
		m_splite.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splite.SetActivePane(0, 1);

	}
	else if (wParam == N_B)
	{
		CCreateContext Context;
		//MessageBox(TEXT("个人信息"));
		Context.m_pNewViewClass = RUNTIME_CLASS(CSell);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView*)m_splite.GetPane(0, 1);
		m_splite.DeleteView(0, 1);
		m_splite.CreateView(0, 1, RUNTIME_CLASS(CSell), CSize(900, 700), &Context);
		CSell* pNewView = (CSell*)m_splite.GetPane(0, 1);
		m_splite.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splite.SetActivePane(0, 1);

	}
	else if (wParam == N_C)
	{
		CCreateContext Context;
		//MessageBox(TEXT("个人信息"));
		Context.m_pNewViewClass = RUNTIME_CLASS(CSell_out);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView*)m_splite.GetPane(0, 1);
		m_splite.DeleteView(0, 1);
		m_splite.CreateView(0, 1, RUNTIME_CLASS(CSell_out), CSize(900, 700), &Context);
		CSell_out* pNewView = (CSell_out*)m_splite.GetPane(0, 1);
		m_splite.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splite.SetActivePane(0, 1);
	}
	else if (wParam == N_D)
	{
		CCreateContext Context;
		//MessageBox(TEXT("个人信息"));
		Context.m_pNewViewClass = RUNTIME_CLASS(Cinfo);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView*)m_splite.GetPane(0, 1);
		m_splite.DeleteView(0, 1);
		m_splite.CreateView(0, 1, RUNTIME_CLASS(Cinfo), CSize(900, 700), &Context);
		Cinfo* pNewView = (Cinfo*)m_splite.GetPane(0, 1);
		m_splite.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splite.SetActivePane(0, 1);
	}
	else if (wParam == N_E)
	{
		CCreateContext Context;
		//MessageBox(TEXT("个人信息"));
		Context.m_pNewViewClass = RUNTIME_CLASS(CNULL);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView*)m_splite.GetPane(0, 1);
		m_splite.DeleteView(0, 1);
		m_splite.CreateView(0, 1, RUNTIME_CLASS(CNULL), CSize(900, 700), &Context);
		CNULL* pNewView = (CNULL*)m_splite.GetPane(0, 1);
		m_splite.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splite.SetActivePane(0, 1);
	}
	return 0;
}
