// FourBarDoc.h : interface of the CFourBarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FOURBARDOC_H__EC58C339_BAA8_418C_A28E_59C65E8481CD__INCLUDED_)
#define AFX_FOURBARDOC_H__EC58C339_BAA8_418C_A28E_59C65E8481CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFourBarDoc : public CDocument
{
protected: // create from serialization only
	CFourBarDoc();
	DECLARE_DYNCREATE(CFourBarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFourBarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFourBarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFourBarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOURBARDOC_H__EC58C339_BAA8_418C_A28E_59C65E8481CD__INCLUDED_)
