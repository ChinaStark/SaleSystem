#pragma once



// Cinfo 窗体视图

class Cinfo : public CFormView
{
	DECLARE_DYNCREATE(Cinfo)

protected:
	Cinfo();           // 动态创建所使用的受保护的构造函数
	virtual ~Cinfo();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_info };
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
	CListCtrl m_list;
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnInitialUpdate();//使用了虚函数
	CStatic m_time;
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	CBrush m_bgBrush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnNcHitTest(CPoint point);
};


