// CNULL.cpp: 实现文件
//

#include "pch.h"
#include "SalaSystem.h"
#include "CNULL.h"



#include "Cfile.h"


// CNULL
double a = 0.1;
IMPLEMENT_DYNCREATE(CNULL, CFormView)

CNULL::CNULL()
	: CFormView(DIALOG_NULL)
	, m_position(_T(""))
{

}

CNULL::~CNULL()
{
}

void CNULL::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, M_list);
	DDX_Control(pDX, IDC_COMBO1, M_combo);
	DDX_Text(pDX, IDC_EDIT1, m_position);
}

BEGIN_MESSAGE_MAP(CNULL, CFormView)
	ON_BN_CLICKED(IDOK, &CNULL::OnBnClickedOk)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CNULL::OnLvnItemchangedList1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CNULL::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CNULL::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CNULL::OnEnChangeEdit1)
	ON_WM_CTLCOLOR()
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// CNULL 诊断

#ifdef _DEBUG
void CNULL::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CNULL::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CNULL 消息处理程序


void CNULL::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CNULL::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CNULL::OnInitialUpdate()
{
	
	CFormView::OnInitialUpdate();


	CString sPath = _T("./land1.jpg");
	CImage img;
	img.Load(sPath);
	HBITMAP hbmp = img.Detach();
	CBitmap bmp;
	bmp.Attach(hbmp);
	m_bgBrush.CreatePatternBrush(&bmp);


	M_list.SetExtendedStyle(M_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//初始化表头
	int id = 1;
	CString field[] = { TEXT("员工ID"),TEXT("销售额"),TEXT("提成"),TEXT("工资")};
	// TODO: 在此添加专用代码和/或调用基类

	
	for (int i = 0; i < sizeof(field) / sizeof(field[0]); ++i)
	{
		M_list.InsertColumn(i, field[i], LVCFMT_CENTER, 90);
	}
	Cfile file;
	file.read();
	CString str;
	
	int i = 0;
	for (list<money>::iterator it = file.m.begin(); it != file.m.end(); it++)
	{
		
		M_list.InsertItem(i, it->name);
		int column = 1;
		str.Format(TEXT("%d"), it->money_s);
		M_list.SetItemText(i, column++, str);
		str.Format(TEXT("%0.2f"), a* (double(it->money_s))/10000);
		M_list.SetItemText(i, column++, str);
		str.Format(TEXT("%0.3f"), (a * (double(it->money_s)) / 10000) + 15);
		M_list.SetItemText(i, column++, str);

		M_list.SetItemData(i, i);//用于存储排序关键字
		i++;
	}

	Cfile file2;
	file2.ReadDocline();
	for (list<money>::iterator it = file.m.begin(); it != file.m.end(); it++)
	{
		M_combo.AddString(it->name);
	}
	M_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();	//更新第一个商品里面的数据（单价）

}


void CNULL::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

	int index = M_combo.GetCurSel();
	//根据索引获取到具体的内容
	CString name;
	M_combo.GetLBText(index, name);

	//根据商品的名称，获取到商品的单价和库存，并且显示到控件中去
	Cfile file;
	file.ReadLogin();
	CString tr = TEXT("管理员");
	CString tr1 = TEXT("销售员");

	for (list<l_user>::iterator it = file.l_ls.begin(); it != file.l_ls.end(); it++)
	{
		if (it->name == name)
		{
			if (it->control == 1)
			{
				m_position = tr;
			}
			else
			{
				m_position = tr1;
			}
			UpdateData(FALSE);	//变量的值马上同步到控件上
		}
	}
}


void CNULL::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	CString tr = TEXT("管理员");
	int index = M_combo.GetCurSel();
	//根据索引获取到具体的内容
	CString name;
	M_combo.GetLBText(index, name);
	Cfile file;
	file.ReadLogin();

	for (list<l_user>::iterator it = file.l_ls.begin(); it != file.l_ls.end(); it++)
	{
		if (it->name == name)
		{
			it->control = 1;
			UpdateData(FALSE);	//变量的值马上同步到控件上
		}
	}
	file.WritePwd();
	MessageBox(TEXT("修改成功！！！"));
	m_position = tr;
	UpdateData(FALSE);
}


void CNULL::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


HBRUSH CNULL::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


LRESULT CNULL::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CFormView::OnNcHitTest(point);
}
