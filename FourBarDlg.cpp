// FourBarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FourBar.h"
#include "FourBarDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFourBarDlg dialog


CFourBarDlg::CFourBarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFourBarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFourBarDlg)
	m_r1 = 0.0;
	m_r2 = 0.0;
	m_r3 = 0.0;
	m_r0 = 0.0;
	m_ax = 0.0;
	m_cx = 0.0;
	m_bx = 0.0;
	m_dx = 0.0;
	m_ay = 0.0;
	m_by = 0.0;
	m_cy = 0.0;
	m_dy = 0.0;
	//}}AFX_DATA_INIT
}


void CFourBarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFourBarDlg)
	DDX_Text(pDX, IDC_EDIT1, m_r1);
	DDX_Text(pDX, IDC_EDIT2, m_r2);
	DDX_Text(pDX, IDC_EDIT3, m_r3);
	DDX_Text(pDX, IDC_EDIT4, m_r0);
	DDX_Text(pDX, IDC_EDIT5, m_ax);
	DDX_Text(pDX, IDC_EDIT7, m_cx);
	DDX_Text(pDX, IDC_EDIT6, m_bx);
	DDX_Text(pDX, IDC_EDIT8, m_dx);
	DDX_Text(pDX, IDC_EDIT9, m_ay);
	DDX_Text(pDX, IDC_EDIT10, m_by);
	DDX_Text(pDX, IDC_EDIT11, m_cy);
	DDX_Text(pDX, IDC_EDIT12, m_dy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFourBarDlg, CDialog)
	//{{AFX_MSG_MAP(CFourBarDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFourBarDlg message handlers



void CFourBarDlg::OnOK() 
{
	UpdateData(TRUE);
	
	CDialog::OnOK();
}

void CFourBarDlg::OnButton1() 
{
	UpdateData();

}
