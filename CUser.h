#pragma once



// CUser 窗体视图

class CUser : public CFormView
{
	DECLARE_DYNCREATE(CUser)

protected:
	CUser();           // 动态创建所使用的受保护的构造函数
	virtual ~CUser();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_USER };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString m_user;
	CString m_mima;
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButton1();
	CString G_zh;
	CString G_mima;
	afx_msg void OnBnClickedButton2();
	CString m_name;
	//int m_salary;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	CString m_time;
	afx_msg void OnStnClickedItime(UINT_PTR nIDEvent);
	CStatic m_time1;
	afx_msg void OnStnClickedCancel();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	CBrush m_bgBrush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnNcHitTest(CPoint point);
};


