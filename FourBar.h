// FourBar.h : main header file for the FOURBAR application
//

#if !defined(AFX_FOURBAR_H__B120B97F_04B9_4991_9814_5FF5E8C8D5DC__INCLUDED_)
#define AFX_FOURBAR_H__B120B97F_04B9_4991_9814_5FF5E8C8D5DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFourBarApp:
// See FourBar.cpp for the implementation of this class
//

class CFourBarApp : public CWinApp
{
public:
	
	CFourBarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFourBarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFourBarApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOURBAR_H__B120B97F_04B9_4991_9814_5FF5E8C8D5DC__INCLUDED_)
