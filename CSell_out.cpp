// CSell_out.cpp: 实现文件
//

#include "pch.h"
#include "SalaSystem.h"
#include "CSell_out.h"

#include "Cfile.h"
#include "CSell_out.h"


#include "Judgeuser.h"
// CSell_out

IMPLEMENT_DYNCREATE(CSell_out, CFormView)

CSell_out::CSell_out()
	: CFormView(DIALOG_Sellout)
	, m_price()
	, m_left()
{

}

CSell_out::~CSell_out()
{
}

void CSell_out::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_price);
	DDX_Text(pDX, IDC_EDIT2, m_left);
	DDX_Text(pDX, IDC_EDIT3, m_num);
	DDX_Text(pDX, IDC_EDIT5, m_win);
}

BEGIN_MESSAGE_MAP(CSell_out, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSell_out::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CSell_out::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSell_out::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT4, &CSell_out::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CSell_out::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON5, &CSell_out::OnBnClickedButton5)
	ON_WM_CTLCOLOR()
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// CSell_out 诊断

#ifdef _DEBUG
void CSell_out::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSell_out::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSell_out 消息处理程序

CString str;
int a = 0;
void CSell_out::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	//切换商品时，控件内容发生改变的时候被调用
	//先获取商品的名称
	int index = m_combo.GetCurSel();
	//根据索引获取到具体的内容
	CString name;
	m_combo.GetLBText(index, name);

	//根据商品的名称，获取到商品的单价和库存，并且显示到控件中去
	Cfile file;
	file.ReadDocline();

	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (it->name == name)
		{
			m_left = it->num;
			m_price = it->price;
			UpdateData(FALSE);	//变量的值马上同步到控件上
		}

	}


}

Cfile file;
void CSell_out::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString name;
	int index = m_combo.GetCurSel();
	m_combo.GetLBText(index, name);
	
	file.ReadDocline();
	UpdateData(TRUE);
	if (m_num <= 0)
	{
		MessageBox(TEXT("加购个数不能小于等于0"));
		return;
	}
	if (m_num > m_left)
	{
		MessageBox(TEXT("加购个数不能大于库存"));
		return;
	}
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if ( it->name == name)
		{
			//同步到库存控件上
			it->num = m_left - m_num;
			m_left = it->num;	//控件上的库存量
			//告诉用户具体的购买信息
			
			str.Format(_T("商品名：%s 购买数量：%d 单价：%d 总价：%d  \r\n"), name, m_num, m_price, m_price * m_num);
			m_win += str;
			a = 1;
			UpdateData(FALSE);
			
		}
	}
}
int c = 0;

void CSell_out::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	int total = 0;
	UpdateData(TRUE);
	// 购买功能的实现
	if (a == 1)
	{
		
		MessageBox(TEXT("购买成功！"));
		file.WirteDocline();
		a = 0;

		UpdateData();
		m_win = "";
		m_num = 0; 
		UpdateData(FALSE);
	}
	else if (a == 0)
	{
		if (m_num <= 0)
		{
			MessageBox(TEXT("购买个数不能小于等于0"));
			return;
		}
		if (m_num > m_left)
		{
			MessageBox(TEXT("购买个数不能大于库存"));
			return;
		}
		//购买
		//获取到具体的要购买的商品名称
		CString name;
		int index = m_combo.GetCurSel();
		m_combo.GetLBText(index, name);

		Cfile file;
		file.ReadDocline();
		for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
		{
			if (it->name == name)
			{
				//同步到库存控件上
				it->num = m_left - m_num;
				m_left = it->num;	//控件上的库存量
			}
		}
		file.WirteDocline();
		total += m_price * m_num;
		file.read();
		for (list<money>::iterator it = file.m.begin(); it != file.m.end(); it++)
		{
			if (out_cstr_name() == it->name)
			{
				//MessageBox(TEXT("购买"));
				it->money_s += total;
			}
		}
		c = 1;
		MessageBox(TEXT("购买成功！"));
		file.WirteDocline();
		file.mid();
		//清空数据
		
		
		m_num = 0;
		UpdateData(FALSE);
		UpdateData();
		m_win = "";
		UpdateData(FALSE);
	}
	
}


void CSell_out::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	CString sPath = _T("./land.jpg");
	CImage img;
	img.Load(sPath);
	HBITMAP hbmp = img.Detach();
	CBitmap bmp;
	bmp.Attach(hbmp);
	m_bgBrush.CreatePatternBrush(&bmp);

	Cfile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		////m_combo = it->name;
		//////char * ---> CString
		m_combo.AddString(it->name);
	}
	
	m_combo.SetCurSel(0);	///默认选中第一个商品
	OnCbnSelchangeCombo1();	//更新第一个商品里面的数据（单价，库存）

	// TODO: 在此添加专用代码和/或调用基类
}


void CSell_out::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CSell_out::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CSell_out::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (c == 0)
	{
		m_win = "";
		UpdateData(FALSE);
		Cfile file;
		file.ReadDocline();
		m_combo.ResetContent();//清空所有内容
		for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
		{
			//MessageBox(TEXT("成功！"));
			m_combo.AddString(it->name);
		}

		m_combo.SetCurSel(0);	///默认选中第一个商品
		OnCbnSelchangeCombo1();	//更新第一个商品里面的数据（单价，库存）
		a = 0;
	}
	else
	{
		m_win = "";
		UpdateData(FALSE);
		c = 0;
	}
	

}


HBRUSH CSell_out::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


LRESULT CSell_out::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CFormView::OnNcHitTest(point);
}
