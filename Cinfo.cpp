// Cinfo.cpp: 实现文件
//

#include "pch.h"
#include "SalaSystem.h"
#include "Cinfo.h"

#include "Cfile.h"

// Cinfo

IMPLEMENT_DYNCREATE(Cinfo, CFormView)

Cinfo::Cinfo()
	: CFormView(DIALOG_info)
{

}

Cinfo::~Cinfo()
{
}

void Cinfo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDCANCEL, m_time);
}

BEGIN_MESSAGE_MAP(Cinfo, CFormView)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &Cinfo::OnLvnItemchangedList1)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// Cinfo 诊断

#ifdef _DEBUG
void Cinfo::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void Cinfo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

 
// Cinfo 消息处理程序


void Cinfo::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void Cinfo::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	CString sPath = _T("./land.jpg");
	CImage img;
	img.Load(sPath);
	HBITMAP hbmp = img.Detach();
	CBitmap bmp;
	bmp.Attach(hbmp);
	m_bgBrush.CreatePatternBrush(&bmp);

	SetTimer(10000, 1000, NULL);
	// TODO: 在此添加专用代码和/或调用基类
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//初始化表头
	CString field[] = { TEXT("商品ID"),TEXT("商品名称"),TEXT("商品单价"),TEXT("商品库存") };

	for (int i = 0; i < sizeof(field) / sizeof(field[0]); ++i)
	{
		m_list.InsertColumn(i, field[i], LVCFMT_CENTER, 90);
	}

	Cfile file;
	file.ReadDocline();	//读取商品信息
	// 添加数据
	int i = 0;
	CString str;
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		str.Format(TEXT("%d"), it->id);
		m_list.InsertItem(i, str);
		int column = 1;
		m_list.SetItemText(i, column++, it->name);
		str.Format(TEXT("%d"), it->price);
		m_list.SetItemText(i, column++, str);
		str.Format(TEXT("%d"), it->num);
		m_list.SetItemText(i, column++, str);

		m_list.SetItemData(i, i);//用于存储排序关键字
		i++;
	}
}


void Cinfo::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 10000)
	{
		CTime now = CTime::GetCurrentTime();
		CString str = now.Format(_T("%Y-%m-%d %H:%M:%S"));
		m_time.SetWindowText(str);


	}

	CFormView::OnTimer(nIDEvent);
}


HBRUSH Cinfo::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd == this)
	{
		return m_bgBrush;
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


LRESULT Cinfo::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CFormView::OnNcHitTest(point);
}
