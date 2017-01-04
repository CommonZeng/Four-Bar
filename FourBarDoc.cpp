// FourBarDoc.cpp : implementation of the CFourBarDoc class
//

#include "stdafx.h"
#include "FourBar.h"

#include "FourBarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFourBarDoc

IMPLEMENT_DYNCREATE(CFourBarDoc, CDocument)

BEGIN_MESSAGE_MAP(CFourBarDoc, CDocument)
	//{{AFX_MSG_MAP(CFourBarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFourBarDoc construction/destruction

CFourBarDoc::CFourBarDoc()
{
	// TODO: add one-time construction code here

}

CFourBarDoc::~CFourBarDoc()
{
}

BOOL CFourBarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFourBarDoc serialization

void CFourBarDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CFourBarDoc diagnostics

#ifdef _DEBUG
void CFourBarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFourBarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFourBarDoc commands
