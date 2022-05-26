#pragma once



// CSell 窗体视图

class CSell : public CFormView
{
	DECLARE_DYNCREATE(CSell)

protected:
	CSell();           // 动态创建所使用的受保护的构造函数
	virtual ~CSell();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_SELL };
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
private:
	CComboBox m_combo;
public:
	double m_price;
private:
	int m_total;
public:
	int m_num;
	CString m_nama;
	int m_price2;
	int m_num2;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit3();
	CStatic m_time;
	afx_msg void OnStnClickedCancel();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnEnChangeEdit4();

	CBrush  m_bgBrush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnNcHitTest(CPoint point);
};


