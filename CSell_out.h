#pragma once



// CSell_out 窗体视图

class CSell_out : public CFormView
{
	DECLARE_DYNCREATE(CSell_out)

protected:
	CSell_out();           // 动态创建所使用的受保护的构造函数
	virtual ~CSell_out();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_Sellout };
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
	CComboBox m_combo;
	afx_msg void OnCbnSelchangeCombo1();
	int  m_price;
	int  m_left;
	int  m_num;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual void OnInitialUpdate();
	afx_msg void OnEnChangeEdit4();
	CString m_win;
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedButton5();

	CBrush m_bgBrush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnNcHitTest(CPoint point);
};


