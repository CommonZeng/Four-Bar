#if !defined(AFX_FOURBARDLG_H__96493B12_0105_42C3_8960_73FA809EBBBB__INCLUDED_)
#define AFX_FOURBARDLG_H__96493B12_0105_42C3_8960_73FA809EBBBB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FourBarDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFourBarDlg dialog

class CFourBarDlg : public CDialog
{
// Construction
public:
	CFourBarDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFourBarDlg)
	enum { IDD = IDD_DIALOG1 };
	double	m_r1;
	double	m_r2;
	double	m_r3;
	double	m_r0;
	double	m_ax;
	double	m_cx;
	double	m_bx;
	double	m_dx;
	double	m_ay;
	double	m_by;
	double	m_cy;
	double	m_dy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFourBarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFourBarDlg)
	virtual void OnOK();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOURBARDLG_H__96493B12_0105_42C3_8960_73FA809EBBBB__INCLUDED_)
