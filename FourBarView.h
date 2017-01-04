// FourBarView.h : interface of the CFourBarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FOURBARVIEW_H__175186B0_76C0_4362_A168_D85C752F82DD__INCLUDED_)
#define AFX_FOURBARVIEW_H__175186B0_76C0_4362_A168_D85C752F82DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <Math.h>
class CFourBarView : public CView
{
protected: // create from serialization only
	CFourBarView();
	DECLARE_DYNCREATE(CFourBarView)

// Attributes
public:
	CFourBarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFourBarView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	bool rev;
	bool aidcircle;
	double speed;
	int count;
	void CalcRadius();
	
	void Draw();
	double r[4];
void action();
	CPoint PairPos[4];
	
	
	virtual ~CFourBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFourBarView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnCancelMode();
	afx_msg void OnFourBar();
	afx_msg void OnSim();
	afx_msg void OnStop();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSpeedup();
	afx_msg void OnSpeeddown();
	afx_msg void OnAid();
	afx_msg void OnReverse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FourBarView.cpp
inline CFourBarDoc* CFourBarView::GetDocument()
   { return (CFourBarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOURBARVIEW_H__175186B0_76C0_4362_A168_D85C752F82DD__INCLUDED_)
