// FourBarView.cpp : implementation of the CFourBarView class
//

#include "stdafx.h"
#include "FourBar.h"

#include "FourBarDoc.h"
#include "FourBarView.h"
#include "FourBarDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFourBarView

IMPLEMENT_DYNCREATE(CFourBarView, CView)

BEGIN_MESSAGE_MAP(CFourBarView, CView)
//{{AFX_MSG_MAP(CFourBarView)
ON_WM_LBUTTONDOWN()
ON_WM_SHOWWINDOW()
ON_WM_CANCELMODE()
ON_COMMAND(ID_FourBar, OnFourBar)
	ON_COMMAND(ID_SIM, OnSim)
	ON_COMMAND(ID_STOP, OnStop)
	ON_WM_TIMER()
	ON_COMMAND(ID_SPEEDUP, OnSpeedup)
	ON_COMMAND(ID_SPEEDDOWN, OnSpeeddown)
	ON_COMMAND(ID_AID, OnAid)
	ON_COMMAND(ID_REVERSE, OnReverse)
	//}}AFX_MSG_MAP
// Standard printing commands
ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFourBarView construction/destruction

CFourBarView::CFourBarView()
{
	// TODO: add construction code here
	
}

CFourBarView::~CFourBarView()
{
}

BOOL CFourBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFourBarView drawing

void CFourBarView::OnDraw(CDC* pDC)
{
	CFourBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFourBarView printing

BOOL CFourBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	
	return DoPreparePrinting(pInfo);
}

void CFourBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFourBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFourBarView diagnostics

#ifdef _DEBUG
void CFourBarView::AssertValid() const
{
	CView::AssertValid();
}

void CFourBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFourBarDoc* CFourBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFourBarDoc)));
	return (CFourBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFourBarView message handlers

void CFourBarView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	static int PairNum;CPoint *param=new CPoint;
	CClientDC dc(this);
	if(PairNum<4){
		
		PairPos[PairNum]=point;
		PairNum++;
		dc.MoveTo(point);
		dc.Ellipse(point.x-2,point.y-2,point.x+2,point.y+2);
		if(PairNum==4){CalcRadius();speed=0.1;aidcircle=0;}
	}
	else{
	//	action();
	PairNum=0;
	}
	
	ReleaseDC(&dc);
	CView::OnLButtonDown(nFlags, point);
}



void CFourBarView::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CView::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
	
}

void CFourBarView::OnCancelMode() 
{
	CView::OnCancelMode();
	
	
}


void CFourBarView::action()
{
	int i=0,j=0;
	static int reverse=0;
	static int flag=0;
	static double theta=-1.5;
	
	double x1,y1,x2,y2,x3,y3,r2,r3,a,b,c,delta,d,x22,y22;
	
	Draw();
	CPoint PCOrigin=PairPos[2];
	
	PairPos[1].x=PairPos[0].x+r[1]*cos(theta);PairPos[1].y=PairPos[0].y+r[1]*sin(theta);
	if(PairPos[3].y==PairPos[1].y){
		if(reverse==0){theta-=speed;}else{theta+=speed;}
		PairPos[1].x=PairPos[0].x+r[1]*cos(theta);PairPos[1].y=PairPos[0].y+r[1]*sin(theta);
	}
		if(reverse==0){theta-=speed;}else{theta+=speed;}
	

		x1=PairPos[1].x;x2=PairPos[2].x;x3=PairPos[3].x;
		y1=PairPos[1].y;y2=PairPos[2].y;y3=PairPos[3].y;
		r2=r[2];r3=r[3];
		CClientDC dc(this);	
		ReleaseDC(&dc);Sleep(10);
	d=x3*x3+y3*y3-x1*x1-y1*y1;
a=1+((x1-x3)*(x1-x3))/((y1-y3)*(y1-y3));
b=(r2*r2-r3*r3)*(x1-x3)/(y3-y1)/(y3-y1)-2*x1-2*y1*(x1-x3)/(y3-y1)+4*(x1-x3)*d/(2*y3-2*y1)/(2*y3-2*y1);
c=x1*x1+y1*y1-2*y1*(r2*r2-r3*r3)/(2*y3-2*y1)+((r2*r2-r3*r3)/(2*y3-2*y1))*((r2*r2-r3*r3)/(2*y3-2*y1))-r2*r2+d*(d+2*r2*r2-2*r3*r3)/(2*y3-2*y1)/(2*y3-2*y1)-2*y1*d/(2*y3-2*y1);
delta=b*b-4*a*c;
if(delta<0||rev==1){
	if(reverse==0&&flag==1){reverse=1;}
	else {if(reverse==1&&flag==1){reverse=0;}}

		if(reverse==0){theta-=speed;}else{theta+=speed;}
		flag=0;
		rev=0;
}
else{
x2=(-b+sqrt(delta))/2/a;
y2=(r2*r2-r3*r3+d+2*x2*x1-2*x2*x3)/(2*y3-2*y1);
x22=(-b-sqrt(delta))/2/a;
y22=(r2*r2-r3*r3+d+2*x22*x1-2*x22*x3)/(2*y3-2*y1);
flag=1;}
if((x22-PairPos[2].x)*(x22-PairPos[2].x)+(y22-PairPos[2].y)*(y22-PairPos[2].y)>(x2-PairPos[2].x)*(x2-PairPos[2].x)+(y2-PairPos[2].y)*(y2-PairPos[2].y)){


	PairPos[2].x=x2;PairPos[2].y=y2;}else{


	PairPos[2].x=x22;PairPos[2].y=y22;}
		/*PairPos[2].x=PCOrigin.x-r[2];	
		
		for(i=0;i<300;i++){
			PairPos[2].x+=1;PairPos[2].y=PCOrigin.y-r[2];
			for(j=0;j<300;j++){PairPos[2].y+=1;
			if(((sqrt((PairPos[2].x-PairPos[1].x)*(PairPos[2].x-PairPos[1].x)+(PairPos[2].y-PairPos[1].y)*(PairPos[2].y-PairPos[1].y))-r[2])*(sqrt((PairPos[2].x-PairPos[1].x)*(PairPos[2].x-PairPos[1].x)+(PairPos[2].y-PairPos[1].y)*(PairPos[2].y-PairPos[1].y))-r[2])<1)
				&&((sqrt((PairPos[3].x-PairPos[2].x)*(PairPos[3].x-PairPos[2].x)+(PairPos[3].y-PairPos[2].y)*(PairPos[3].y-PairPos[2].y))-r[3])*(sqrt((PairPos[3].x-PairPos[2].x)*(PairPos[3].x-PairPos[2].x)+(PairPos[3].y-PairPos[2].y)*(PairPos[3].y-PairPos[2].y))-r[3])<1)){flag=1;break;}
			}if(flag==1)break;
	}
	if(reverse==0&&PairPos[2].x>200||PairPos[2].y>200)
		{
		reverse=1;
		
		}*/
Draw();
	
}

void CFourBarView::OnFourBar() 
{
	CFourBarDlg dlg;	dlg.m_r1=r[1];dlg.m_r2=r[2];dlg.m_r3=r[3];dlg.m_r0=r[0];
	dlg.m_ax=PairPos[0].x;
	dlg.m_ay=PairPos[0].y;
	dlg.m_bx=PairPos[1].x;
	dlg.m_by=PairPos[1].y;
	dlg.m_cx=PairPos[2].x;
	dlg.m_cy=PairPos[2].y;
	dlg.m_dx=PairPos[3].x;
	dlg.m_dy=PairPos[3].y;
	dlg.DoModal();
	r[1]=dlg.m_r1;r[2]=dlg.m_r2;r[3]=dlg.m_r3;r[0]=dlg.m_r0;
	Draw();
}

void CFourBarView::Draw()
{
	int i;	CClientDC dc(this);
	
	
	
	

	CPen pen4;
	pen4.CreatePen(0,1,RGB(255,0,0));
	CPen *PenOrigin=dc.SelectObject(&pen4);
	//CBrush *PBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));

	dc.Rectangle(-1000,-1000,1000,1000);
	
	
	dc.MoveTo(PairPos[0]);dc.Ellipse(PairPos[0].x-5,PairPos[0].y-5,PairPos[0].x+5,PairPos[0].y+5);
		dc.LineTo(PairPos[1]);
		dc.Ellipse(PairPos[1].x-2,PairPos[1].y-2,PairPos[1].x+2,PairPos[1].y+2);
	//	dc.SelectObject(PenOrigin);
		CPen pen0;
		pen0.CreatePen(0,1,RGB(0,0,0));
		dc.SelectObject(&pen0);
	//CBrush *PBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	
	for(i=2;i<4;i++){
		
		
		dc.LineTo(PairPos[i]);
		dc.Ellipse(PairPos[i].x-2,PairPos[i].y-2,PairPos[i].x+2,PairPos[i].y+2);
	}
	dc.Ellipse(PairPos[3].x-5,PairPos[3].y-5,PairPos[3].x+5,PairPos[3].y+5);
	
	
	
	



	if(1==aidcircle)	
	{
		double x1,y1,x2,y2,x3,y3,r2,r3;
		x1=PairPos[1].x;x2=PairPos[2].x;x3=PairPos[3].x;
		y1=PairPos[1].y;y2=PairPos[2].y;y3=PairPos[3].y;
		r2=r[2];r3=r[3];
		CBrush *PBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		dc.SelectObject(PBrush);
		dc.Ellipse(x1-r2,y1-r2,x1+r2,y1+r2);
		dc.Ellipse(x3-r3,y3-r3,x3+r3,y3+r3);
	}
		
	dc.SelectObject(PenOrigin);
	//Sleep(5);
	
	
	ReleaseDC(&dc);
}







void CFourBarView::OnSim() 
{

		SetTimer(1,1,NULL);
}

void CFourBarView::CalcRadius()
{int i;
	for(i=1;i<4;i++)
		r[i]=sqrt((PairPos[i].x-PairPos[i-1].x)*(PairPos[i].x-PairPos[i-1].x)+(PairPos[i].y-PairPos[i-1].y)*(PairPos[i].y-PairPos[i-1].y));
	r[0]=sqrt((PairPos[3].x-PairPos[0].x)*(PairPos[3].x-PairPos[0].x)+(PairPos[3].y-PairPos[0].y)*(PairPos[3].y-PairPos[0].y));

}

void CFourBarView::OnStop() 
{
KillTimer(1);
}

void CFourBarView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	action();
	CView::OnTimer(nIDEvent);
}



void CFourBarView::OnSpeedup() 
{
speed*=1.2;	
}

void CFourBarView::OnSpeeddown() 
{
	speed/=1.2;	
	
}

void CFourBarView::OnAid() 
{
	if(aidcircle==false){aidcircle=true;}else{aidcircle=false;}
}

void CFourBarView::OnReverse() 
{
	// TODO: Add your command handler code here
	rev=1;
}
