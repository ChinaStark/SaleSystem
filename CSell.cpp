// CSell.cpp: 实现文件
//

#include "pch.h"
#include "SalaSystem.h"
#include "CSell.h"


#include "Cfile.h"



// CSell

IMPLEMENT_DYNCREATE(CSell, CFormView)

CSell::CSell()
	: CFormView(DIALOG_SELL)
	, m_nama(_T(""))
	
{

}

CSell::~CSell()
{
}

void CSell::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_price);
	DDX_Text(pDX, IDC_EDIT2, m_total);
	DDX_Text(pDX, IDC_EDIT3, m_num);
	DDX_Text(pDX, IDC_EDIT4, m_nama);
	DDX_Text(pDX, IDC_EDIT5, m_price2);
	DDX_Text(pDX, IDC_EDIT6, m_num2);
	DDX_Control(pDX, IDCANCEL, m_time);
}

BEGIN_MESSAGE_MAP(CSell, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSell::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSell::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CSell::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CSell::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &CSell::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT3, &CSell::OnEnChangeEdit3)
	ON_STN_CLICKED(IDCANCEL, &CSell::OnStnClickedCancel)
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_EDIT4, &CSell::OnEnChangeEdit4)
	ON_WM_CTLCOLOR()
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// CSell 诊断

#ifdef _DEBUG
void CSell::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSell::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSell 消息处理程序


void CSell::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码;
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
			m_price  = it->price;
			m_total = it->num;
			UpdateData(FALSE);	//变量的值马上同步到控件上
		}

	}
}


void CSell::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码


	UpdateData(TRUE);
	m_num = 0;
	m_combo.SetCurSel(0);	///默认选中第一个商品
	OnCbnSelchangeCombo1();

	UpdateData(FALSE);
}


void CSell::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);	//取出控件中的值到变量里面去
	// 购买功能的实现
	if (m_num2 <= 0)
	{
		MessageBox(TEXT("添加个数不能小于等于0"));
		return;
	}
	if (m_price2 <= 0)
	{
		MessageBox(TEXT("添加商品单价不能小于等于0"));
		return;
	}
	if (m_nama.IsEmpty() || m_nama.GetLength() > 8)
	{
		MessageBox(TEXT("添加商品名为空或者长度大于8个字符"));
		return;
	}

	Cfile file;
	file.ReadDocline();
	file.Addline(m_nama, m_num2, m_price2);
	file.WirteDocline();
	MessageBox(TEXT("添加成功！"));

	//同步到左侧的商品名称下拉列表中
	m_combo.InsertString(0, m_nama);
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();

	//清空输入的内容
	m_nama.Empty();
	m_price2 = 0;
	m_num2 = 0;
	UpdateData(FALSE);
}


void CSell::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码


}


void CSell::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	CString sPath = _T("./land1.jpg");
	CImage img;
	img.Load(sPath);
	HBITMAP hbmp = img.Detach();
	CBitmap bmp;
	bmp.Attach(hbmp);
	m_bgBrush.CreatePatternBrush(&bmp);

	SetTimer(10000, 1000, NULL);
	// TODO: 在此添加专用代码和/或调用基类
	//初始化商品名称列表下拉框
	Cfile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		////m_combo = it->name;
		//////char * ---> CString
		m_combo.AddString(it->name);
		m_price = it->price;
	}
	UpdateData(FALSE);
	m_combo.SetCurSel(0);	///默认选中第一个商品
	OnCbnSelchangeCombo1(); //初始化默认选中的第一个商品的单价
}


void CSell::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);	//取出控件中的值到变量里面去
	// 购买功能的实现
	if (m_num <= 0)
	{
		MessageBox(TEXT("添加个数不能小于等于0"));
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
			//
			it->num = it->num + m_num;
			m_total = it->num;
			MessageBox(_T("添加成功！"));
			file.WirteDocline();
		}
	}

	//清空数据
	m_num = 0;
	UpdateData(FALSE);
}


void CSell::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CSell::OnStnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码

}


void CSell::OnTimer(UINT_PTR nIDEvent)
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


void CSell::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


HBRUSH CSell::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


LRESULT CSell::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CFormView::OnNcHitTest(point);
}
