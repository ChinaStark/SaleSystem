#pragma once



// CNULL 窗体视图

class CNULL : public CFormView
{
	DECLARE_DYNCREATE(CNULL)

protected:
	CNULL();           // 动态创建所使用的受保护的构造函数
	virtual ~CNULL();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_NULL };
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
	afx_msg void OnBnClickedOk();
	CListCtrl M_list;
	CComboBox M_combo;
	CString m_position;
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnInitialUpdate();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();

	CBrush m_bgBrush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnNcHitTest(CPoint point);
};


