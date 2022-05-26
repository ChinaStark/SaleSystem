// Clogin.cpp: 实现文件
//

#include "pch.h"
#include "SalaSystem.h"
#include "Clogin.h"
#include "afxdialogex.h"

#include"Judgeuser.h"
#include"Cfile.h"

// Clogin 对话框

IMPLEMENT_DYNAMIC(Clogin, CDialogEx)

Clogin::Clogin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DIALOG_LOGIN, pParent)
	, C_zh(_T(""))
	, C_mima(_T(""))
{

}

Clogin::~Clogin()
{
}

void Clogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, C_zh);
	DDX_Text(pDX, IDC_EDIT2, C_mima);
	DDX_Control(pDX, IDCANCEL, m_time);
}


BEGIN_MESSAGE_MAP(Clogin, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &Clogin::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &Clogin::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Clogin::OnBnClickedButton2)
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_EDIT1, &Clogin::OnEnChangeEdit1)
	 
	ON_WM_TIMER()
	ON_STN_CLICKED(IDCANCEL, &Clogin::OnStnClickedCancel)
	ON_WM_CTLCOLOR()
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// Clogin 消息处理程序


void Clogin::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Clogin::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Cfile zhuce;
	
	zhuce.ReadLogin();
	zhuce.a1.id = ++zhuce.l_num;
	zhuce.a1.control = 0;
	UpdateData();
	zhuce.a1.name = C_zh;
	zhuce.a1.l_pwd = C_mima;
	for (list<l_user>::iterator it = zhuce.l_ls.begin(); it != zhuce.l_ls.end(); it++)
	{
		if (it->name == C_zh)
		{
			MessageBox(TEXT("账号存在！！！"));
			return;
		}

	}
	zhuce.resiger();
	MessageBox(TEXT("注册成功"));

}


void Clogin::OnBnClickedButton2()
{

	
	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData(TRUE);
	if (C_zh.IsEmpty() || C_mima.IsEmpty())
	{
		MessageBox(TEXT("密码不能为空！"));
		return;
	}
	Cfile file;
	file.ReadLogin(); //读取用户信息
	int falg = 0;
	//std::string L_m_pwd(CW2A(m_pwd.GetString()));
	//std::string L_m_user(CW2A(m_user.GetString()));
	for (list<l_user>::iterator it = file.l_ls.begin(); it != file.l_ls.end(); it++)
	{
		if ((it->name == C_zh) && (it->l_pwd == C_mima))
		{
			falg = 1;
			set_judge(it->control, it->name);
			break;
		}
		else
		{
			falg = 0;
		}
		//m_combo.AddString((CString)it->name.c_str());

	}
	if (falg == 1)
	{
		//关闭当前对话框
		CDialog::OnCancel();
	}
	else
	{
		MessageBox(TEXT("用户名或密码不存在"));
	}

}


void Clogin::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void Clogin::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CDialogEx::OnClose();
	exit(0);
}


void Clogin::OnEnChangeEdit1()
{

	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


BOOL Clogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetTimer(10000, 1000, NULL);
	// TODO:  在此添加额外的初始化

	Cfile A;
	//A.ReadLogin(C_zh, C_mima);

	CString sPath = _T("./land.jpg");
	CImage img;
	img.Load(sPath);
	HBITMAP hbmp = img.Detach();
	CBitmap bmp;
	bmp.Attach(hbmp);
	m_bgBrush.CreatePatternBrush(&bmp);




	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Clogin::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 10000)
	{
		CTime now = CTime::GetCurrentTime();
		CString str = now.Format(_T("%Y-%m-%d %H:%M:%S"));
		m_time.SetWindowText(str);


	}
	CDialogEx::OnTimer(nIDEvent);
}


void Clogin::OnStnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
}


HBRUSH Clogin::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	if (pWnd == this)
	{
		return m_bgBrush;
	}
	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


LRESULT Clogin::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CDialogEx::OnNcHitTest(point);
}
