// FKDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FK.h"
#include "FKDlg.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define TIMER_START 1
#define KEY_MESSAGE 2
#define WIDTH 21
#define H 10	
#define S 20
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
////////////////////////////
    
    
	CDC *mdc=new CDC;
	CDC *mdc2=new CDC;
	int BLANK[20][10];
//	RECT re;
/////////////////////////
class F
{
public:
	int x,y,max,now;
	DWORD color;
	int shape[4][4][4];
	void changeshape()
	{
		if(now>=max)
			now=0;
		  else now++;
		if(shape[now]==NULL)
			now--;
		
	}
}fknow,fknext,fkempty;
//////////////////////////////////////////////
F fk[7]=
{
	{
	    0,0,1,0,BIT1,
		{
			{
				{1,0,0,0},
				{1,0,0,0},
				{1,0,0,0},
				{1,0,0,0}
			},
			{
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
		    NULL,NULL
		}
		////////////////////////////////以上为长条初始化;
	},
/////////////////////////////////////////////////////////

	{
	    0,0,0,0,BIT2,
		{
			{
				{1,1,0,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			NULL,NULL,NULL
		}
		////////////////////////////////以上为方块初始化;
	},
///////////////////////////////////////////////////////////

	{
	    0,0,3,0,BIT3,
		{
			{
				{0,1,0,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,1,0,0},
				{1,1,0,0},
				{0,1,0,0},
				{0,0,0,0}
			},
			{
				{1,1,1,0},
				{0,1,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{1,0,0,0},
				{1,1,0,0},
				{1,0,0,0},
				{0,0,0,0}
			}
		}
		////////////////////////////////以上为三角初始化;
	},

///////////////////////////////////////////////////////////

	{
	    0,0,1,0,BIT4,
		{
			{
				{0,1,0,0},
				{1,1,0,0},
				{1,0,0,0},
				{0,0,0,0}
			},
			{
				{1,1,0,0},
				{0,1,1,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			NULL,NULL
		}
		////////////////////////////////以上为梯形1初始化;
	},

///////////////////////////////////////////////////////////

	{
	    0,0,1,0,BIT4,
		{
			{
				{1,0,0,0},
				{1,1,0,0},
				{0,1,0,0},
				{0,0,0,0}
			},
			{
				{0,1,1,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			NULL,NULL
		}
		////////////////////////////////以上为梯形2初始化;
	},


///////////////////////////////////////////////////////////

	{
	    0,0,3,0,BIT5,
		{
			{
				{1,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,0,0,0}
			},
			{
				{1,1,1,0},
				{1,0,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{1,0,0,0},
				{1,0,0,0},
				{1,1,0,0},
				{0,0,0,0}
			},
			{
				{0,0,1,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0}
			}
		}
		////////////////////////////////以上为尺形1初始化;
	},



		///////////////////////////////////////////////////////////

	{
	    0,0,3,0,BIT5,
		{
			{
				{1,1,0,0},
				{1,0,0,0},
				{1,0,0,0},
				{0,0,0,0}
			},
			{
				{1,0,0,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,1,0,0},
				{0,1,0,0},
				{1,1,0,0},
				{0,0,0,0}
			},
			{
				{1,1,1,0},
				{0,0,1,0},
				{0,0,0,0},
				{0,0,0,0}
			}
		}
		////////////////////////////////以上为尺形2初始化;
	}
////////////////////////////////////////////////
};


/////////

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
    
// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
    
	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFKDlg dialog

CFKDlg::CFKDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFKDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFKDlg)
	m_speed = 0;
	m_score = 0;
	bStart = false;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFKDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFKDlg)
	DDX_Control(pDX, IDC_NEXT, m_next);
	DDX_Control(pDX, IDC_PIC, m_pic);
	DDX_Text(pDX, IDC_EDIT1, m_speed);
	DDV_MinMaxInt(pDX, m_speed, 1, 10);
	DDX_Text(pDX, IDC_EDIT2, m_score);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFKDlg, CDialog)
	//{{AFX_MSG_MAP(CFKDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFKDlg message handlers
	
//////////////////


BOOL CFKDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	/////////////////////////////////安装皮肤插件
       CClientDC dc(CWnd::GetDlgItem(IDC_PIC));
	   mdc->CreateCompatibleDC(&dc);
	   mdc2->CreateCompatibleDC(&dc);//////初始化画板
	   ///////////////////
	   m_pic.MoveWindow(25,25,WIDTH*H,WIDTH*S,true);
       m_next.MoveWindow(260,45,WIDTH*4,WIDTH*4,true);
	  // m_pic.GetClientRect(&re);
//初始化方块
	//INT_START();

	 
	/////////////////////////////////////////
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFKDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFKDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
        
	/////////////////////////////////////////////
	    
	//////////////////////////////////////////////
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFKDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFKDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
//	ExitSkin();//释放皮肤插件
	KillTimer(TIMER_START);
	bStart = false;
	////////////////////////////
	
	if (mdc)  delete mdc;
	if (mdc2) delete mdc2;
	/////释放指针
 	CDialog::OnClose();
}

void CFKDlg::OnStart() 
{ 
	  GetDlgItem(IDC_START)->EnableWindow(false);//make the button "Start" Disabled;
	  GetDlgItem(IDC_PAUSE)->EnableWindow(true);//make the button "Pause" abled;
	  GetDlgItem(IDC_STOP)->EnableWindow(true);//make the button "Stop" abled;
	  INT_START();////初始化
	  SetTimer(TIMER_START,(int)(fabs(m_speed-9)*100),NULL);
	  bStart = true;
	  this->SetFocus();
}

void CFKDlg::OnStop() 
{

      GetDlgItem(IDC_START)->EnableWindow(true);//make the button "Start" abled;
	  GetDlgItem(IDC_PAUSE)->EnableWindow(false);//make the button "Pause" disabled;
	  GetDlgItem(IDC_STOP)->EnableWindow(false);//make the button "Stop" disabled;
	  GetDlgItem(IDC_PAUSE)->SetWindowText(_T("Pause"));
	  KillTimer(TIMER_START);////Stop the timer;
	  bStart = false;
	  for(int i =0;i<20;i++)
		for(int k =0;k <10;k++)
			 BLANK[i][k]=0;//初始化画板
		///////////////
	  fknow=fkempty;
	  fknext=fkempty;//
	  m_score=0;
	  m_speed=0;
	  ////////////////初始化各个变量
	  DRAW();
	  
}

void CFKDlg::OnPause() 
{
	//  GetDlgItem(IDC_STOP)->SetWindowText(_T("Continue"));
       
	   CString str;
       GetDlgItem(IDC_PAUSE)->GetWindowText(str);////////////////得到按钮现在的状态
       if(str=="Pause")
	   {                  
		       GetDlgItem(IDC_PAUSE)->SetWindowText(_T("Continue"));
			   KillTimer(TIMER_START);
	           bStart = false;
			   
	   }
	   else
	   {
			   GetDlgItem(IDC_PAUSE)->SetWindowText(_T("Pause")); 	   
			   SetTimer(TIMER_START,(int)(fabs(m_speed-9)*100),NULL);////setup the timer;
	           bStart = true;
			   this->SetFocus();
			   ::SetFocus(GetDlgItem(IDC_PIC)->m_hWnd);////让“暂停”按钮失去焦点
	   };
	   


}


void CFKDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
	case TIMER_START:
		if (DOWN((fknow.x),(fknow.y+1))==true)
				        fknow.y++;//////方块自动向下
		DRAW();
		break;
	};
	DRAW();////////////////////////画屏
	CDialog::OnTimer(nIDEvent);
}


///////////////////////////Those the Code
void CFKDlg::DRAW()
{ 
	  CBitmap *tempbitmap=new CBitmap;
	  CClientDC dc(CWnd::GetDlgItem(IDC_PIC));
	  tempbitmap->CreateCompatibleBitmap(&dc,WIDTH*H,WIDTH*S);////////创建一个空白图片
 	  mdc->SelectObject(tempbitmap);///////////////选择图片
	  mdc->BitBlt(0,0,WIDTH*H,WIDTH*S,mdc2,0,0,BLACKNESS);//////////画上黑色背景
	  for(int i=0;i<4;i++)
		  for(int k =0;k<4;k++)
		  {
			  if(fknow.shape[fknow.now][i][k]==1)
			  {
				  CBitmap *temp=new CBitmap;
				  temp->LoadBitmap(fknow.color);				
				  mdc2->SelectObject(temp);
                  mdc->BitBlt((fknow.x+k)*WIDTH,(fknow.y+i)*WIDTH,WIDTH,WIDTH,mdc2,0,0,SRCCOPY);				   
				  delete temp;//////////////////////////////画出现在正在下落的方块
			  }
		  }
	for(int m=0;m<20;m++)
		for(int n=0;n<10;n++) 
		{
			if(BLANK[m][n]==1)
			  {
				  CBitmap *temp=new CBitmap;
				  temp->LoadBitmap(BIT3);				
				  mdc2->SelectObject(temp);
                  mdc->BitBlt(n*WIDTH,m*WIDTH,WIDTH,WIDTH,mdc2,0,0,SRCCOPY);				   
				  delete temp;//////画出已经堆积下来的方块
			  }
		}
	dc.BitBlt(0,0,WIDTH*H,WIDTH*S,mdc,0,0,SRCCOPY);//////////把MDC画到屏幕上
	if(tempbitmap) delete tempbitmap;
}
bool CFKDlg::DOWN(int nX,int nY)
{
	
    if(nX<0)
	{
 		return false;///////////////判断是否走出左边
	}
	  else 
	  {
		  for(int i =3;i>=0;i--)
			  for(int k =0;k<4;k++)
			  {
				  if(fknow.shape[fknow.now][k][i]==1  && nX+i+1>10)
					  return false;/////////////判断是否走出右边
			  };
		
		  for(int m =0;m<4;m++)
			  for(int n =0;n<4;n++)
			  {
				  if(fknow.shape[fknow.now ][m][n]==1  && nY+m+1>20)/////////判断是否到达底部
				  {
					  for(int z =0;z<4;z++)
			             for(int u =0;u<4;u++)
						 {
					      	BLANK[fknow.y+z][fknow.x+u]+=fknow.shape[fknow.now ][z][u];////////把下落的方块的数据给画布
						 };
				      fknow=fknext;////让NEXT变成下落的方块
			     	  srand(time(0));
	                  fknext=fk[rand()%7];///////让NEXT随机产生一个新的
			          if(fknext.max >0)
					        fknext.now =rand()%fknext.max;
					  fknow.x =H/2-1;
					  XC();////////////////判断是否需要消层
					  DRAWNEXT();///////////////////////////////把下一个要落下的方块画在屏幕上
					  return false;
				  };
			  };
	  };


	  /////////////////////////
	  if(nX!=fknow.x)
	  {
            for(int i=0;i<4;i++)
		       for(int k=0;k<4;k++)
			   {
		             if((BLANK[nY+i][nX+k]+fknow.shape[fknow.now][i][k])==2)
				            return false;
			   };
		///产生碰撞效果
	  }
	  ////////////////////////////
	for(int i=0;i<4;i++)
		for(int k=0;k<4;k++)
		{
		    if((BLANK[nY+i][nX+k]+fknow.shape[fknow.now][i][k])==2)////////////////判断是否已经和别的方块撞在一起
			{
				if((nY-1)<=0)
				{
                      
		              CFKDlg::OnStop();
					  MessageBox("Sorry You Lost!");
			          return false;/////////////////////如果下落的方块已经触顶了，那么就输了
				};
				for(int m =0;m<4;m++)
			        for(int n =0;n<4;n++)
					{
						BLANK[fknow.y+m][fknow.x+n]+=fknow.shape[fknow.now][m][n];////////把下落的方块的数据给画布
					};
				fknow=fknext;////让NEXT变成下落的方块
				srand(time(0));
	            fknext=fk[rand()%7];///////让NEXT随机产生一个新的
			    if(fknext.max >0)
					fknext.now =rand()%fknext.max;
	            fknow.x =H/2-1;
				XC();////////////////判断是否需要消层
			    DRAWNEXT();///////////////////////////////把下一个要落下的方块画在屏幕上
				return false;
			}
		};
	
    return true;
}

void CFKDlg::XC()
{
     for(int i =19;i>=0;i--)
	 {
		 int count=0;
		 for(int k =0;k<10;k++)
		 {
			 if(BLANK[i][k]==1)
                  count++;
		 };
		 if(count==10)//////////////判断是否要消层
		 {
			 for(int m=i;m>0;m--)
				 for(int n=0;n<10;n++)
					 BLANK[m][n]=BLANK[m-1][n];//////////消层，并使个面的下移
			 for(int z=0;z<10;z++)
				 BLANK[0][z]=0;////////////使第一行变空
			 i++;//////////////////回到前一行检查，以判断刚刚下来的一层是否需要消去
			 m_score+=10;
			 this->SetFocus();
			 switch (m_score)
			 {
			 case 150:
				 m_speed++;
				 SetTimer(TIMER_START,(int)(fabs(m_speed-9)*100),NULL);
				 break;
			 case 400:
				 m_speed++;
				 SetTimer(TIMER_START,(int)(fabs(m_speed-9)*100),NULL);
				 break;
			 case 800:
				 m_speed++;
				 SetTimer(TIMER_START,(int)(fabs(m_speed-9)*100),NULL);
				 break;
				 
			 case 1500:
				 m_speed++;
				 SetTimer(TIMER_START,(int)(fabs(m_speed-9)*100),NULL);
				 break;
				 
			 case 3000:
				 m_speed++;
				 SetTimer(TIMER_START,(int)(fabs(m_speed-9)*100),NULL);
				 break;
				 
			 case 4900:
				 m_speed++;
				 SetTimer(TIMER_START,(int)(fabs(m_speed-9)*100),NULL);
				 break;
				 
			 case 6700:
				 m_speed++;
				 SetTimer(TIMER_START,(int)(fabs(m_speed-9)*100),NULL);
				 break;
				 
			 case 10000:
				 m_speed++;
				 SetTimer(TIMER_START,(int)(fabs(m_speed-9)*100),NULL);
				 break;
			                  //////////////// 以上是不同的分数就有不同的速度
			 case 20000:
				 MessageBox("You Win!");
				 CFKDlg::OnStop();/////////////过两万分就赢了
				 break;

			 }
		 }
	 }
   
	UpdateData(false);
			 

}
void CFKDlg::INT_START()
{

	srand(time(0));
    fknow=fk[rand()%7];
	fknext=fk[rand()%7];
	fknow.x =H/2-1;
	if(fknow.max >0)
          fknow.now =rand()%fknow.max;
	for(int i =0;i<20;i++)
		for(int k =0;k <10;k++)
			 BLANK[i][k]=0;
    DRAWNEXT();/////////////////////初始化各个变量

}


void CFKDlg::DRAWNEXT()
{
		CClientDC dc(CWnd::GetDlgItem(IDC_NEXT));
    CBitmap *temp=new CBitmap;
	CBitmap  *temp2=new CBitmap;
	CDC *tempDC=new CDC;
	temp->LoadBitmap(fknext.color);				
	temp2->CreateCompatibleBitmap(&dc,WIDTH*4,WIDTH*4);
	mdc2->SelectObject(temp);
    tempDC->CreateCompatibleDC(&dc);
	tempDC->SelectObject(temp2);
	for(int i =0;i<4;i++)
		for(int k =0;k<4;k++)
		{
			if(fknext.shape[fknext.now][i][k]==1)
                   tempDC->BitBlt(k*WIDTH,i*WIDTH,WIDTH,WIDTH,mdc2,0,0,SRCCOPY);
		}
	dc.BitBlt(0,0,4*WIDTH,4*WIDTH,tempDC,0,0,SRCCOPY);
	delete temp;
	delete temp2;
	delete tempDC;///////////////////////将下一个方块画出来
}



BOOL CFKDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	if (pMsg->message == WM_KEYDOWN)
	{
		if (bStart)
		{	
			switch(pMsg->wParam)
			{
			case VK_LEFT:
				{
					if (DOWN((fknow.x-1),(fknow.y))==true)
						fknow.x--;//////方块向左移动
					DRAW();
					return true;
					break;
				}
			case VK_RIGHT:
				{
					if (DOWN((fknow.x+1),(fknow.y))==true)
						fknow.x++;//////向右移动
					DRAW();
					return true;
					break;
				}
			case VK_DOWN:
				{
					if (DOWN((fknow.x),(fknow.y+1))==true)
						fknow.y++;/////向下移动
					DRAW();
					return true;
					break;
				}
			case VK_UP:
				{
					int tempint;
					tempint=fknow.now;
					fknow.changeshape();//////方块变形
					if(DOWN(fknow.x,fknow.y)==false)
						fknow.now =tempint;///变形不成功时，变为原来的样子
					else
						DRAW();
					DRAW();
					break;
				}
			case VK_SPACE:
				{
					while(DOWN(fknow.x,fknow.y+1)==true)
					{
						fknow.y++;
					};///////////方块直接到底部
					DRAW();
					return true;
					break;
				}
				
			}

		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}
