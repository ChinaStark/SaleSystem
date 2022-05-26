#pragma once

// Clogin 对话框

class Clogin : public CDialogEx
{
	DECLARE_DYNAMIC(Clogin)

public:
	Clogin(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Clogin();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString C_zh;
	afx_msg void OnEnChangeEdit2();
	CString C_mima;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual void OnOK();
	afx_msg void OnClose();
	afx_msg void OnEnChangeEdit1();
	virtual BOOL OnInitDialog();

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStnClickedCancel();
	CStatic m_time;
	CBrush m_bgBrush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnNcHitTest(CPoint point);
};
