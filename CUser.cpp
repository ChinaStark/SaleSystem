// CUser.cpp: 实现文件
//

#include "pch.h"
#include "SalaSystem.h"
#include "CUser.h"
#include"Cfile.h"
#include "Judgeuser.h"

#include "Clogin.h"
#include "employee.h"
#include"manager.h"
// CUser

IMPLEMENT_DYNCREATE(CUser, CFormView)

CUser::CUser()
	: CFormView(DIALOG_USER)
	, m_user(_T(""))
	, G_zh(_T(""))
	, G_mima(_T(""))
	, m_name(_T(""))
	//, m_salary()
	, m_time(_T(""))
{

}

CUser::~CUser()
{
}

void CUser::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, G_zh);
	DDX_Text(pDX, IDC_EDIT3, G_mima);
	DDX_Text(pDX, IDC_EDIT4, m_name);
	//DDX_Text(pDX, IDC_EDIT5, m_salary);

	DDX_Control(pDX, IDCANCEL, m_time1);
}

BEGIN_MESSAGE_MAP(CUser, CFormView)
	ON_EN_CHANGE(IDC_EDIT1, &CUser::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CUser::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUser::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT4, &CUser::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CUser::OnEnChangeEdit5)
	
	ON_STN_CLICKED(IDCANCEL, &CUser::OnStnClickedCancel)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// CUser 诊断

#ifdef _DEBUG
void CUser::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUser::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUser 消息处理程序


void CUser::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}



void CUser::OnInitialUpdate()
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
	employee e1;
	manager   m1;
	int aa = out_judge();
	if (aa == 1)
	{
		
		m1.flag = 1;
		m1.name = out_cstr_name();
		m1.salary = 20;//万
		m1.win = 30;//万
	}
	else
	{
		
		e1.flag = 0;
		e1.name = out_cstr_name();
		e1.salary = 15;
		e1.sale = 0;
	}
	
	
	if (aa ==2)
	{
		
		m_name = TEXT("销售员");
		//m_salary = e1.salary + e1.sale;
		
	}
	else
	{
		
		m_name = TEXT("管理员");
		//m_salary = m1.salary + m1.win;
		
		UpdateData(FALSE);
	}
	m_user = out_cstr_name();	//用户名
	UpdateData(FALSE); //内容更新到对应的控件

	// TODO: 在此添加专用代码和/或调用基类
}


void CUser::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (G_mima.IsEmpty() || G_zh.IsEmpty())
	{
		MessageBox(TEXT("密码或姓名不能为空！"));
		return;
	}
	if (m_user == G_zh & m_mima == G_mima)
	{
		MessageBox(TEXT("新旧密码,新旧账号一致！"));
		return;
	}
	if (m_user == G_zh)
	{
		MessageBox(TEXT("新密码旧密码一致！"));
		return;
	}
	if (m_mima == G_mima)
	{
		MessageBox(TEXT("新密码旧密码一致！"));
		return;
	}
	
	UpdateData(TRUE);
	Cfile G;

	G.ReadLogin();
	for (list<l_user>::iterator it = G.l_ls.begin(); it != G.l_ls.end(); it++)
	{
		if (it->name == out_cstr_name())
		{
			it->name = G_zh;
			it->l_pwd = G_mima;
			set_judge(it->id, G_zh);
			MessageBox(TEXT("修改成功！！！"));
		}
	}
	G.WritePwd();
	CUser::OnInitialUpdate();
	UpdateData(TRUE);
	G_mima = "";
	G_zh = "";
	UpdateData(FALSE);
}


void CUser::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	G_mima.Empty();
	G_zh.Empty();
	
	UpdateData(FALSE);
}


void CUser::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码


}


void CUser::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}





void CUser::OnStnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码

}


void CUser::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 10000)
	{
		CTime now = CTime::GetCurrentTime();
		CString str = now.Format(_T("%Y-%m-%d %H:%M:%S"));
		m_time1.SetWindowText(str);


	}
	CFormView::OnTimer(nIDEvent);
}


HBRUSH CUser::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd == this)
	{
		return   m_bgBrush;
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


LRESULT CUser::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CFormView::OnNcHitTest(point);
}
