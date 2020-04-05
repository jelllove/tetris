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
		////////////////////////////////����Ϊ������ʼ��;
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
		////////////////////////////////����Ϊ�����ʼ��;
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
		////////////////////////////////����Ϊ���ǳ�ʼ��;
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
		////////////////////////////////����Ϊ����1��ʼ��;
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
		////////////////////////////////����Ϊ����2��ʼ��;
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
		////////////////////////////////����Ϊ����1��ʼ��;
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
		////////////////////////////////����Ϊ����2��ʼ��;
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

	/////////////////////////////////��װƤ�����
       CClientDC dc(CWnd::GetDlgItem(IDC_PIC));
	   mdc->CreateCompatibleDC(&dc);
	   mdc2->CreateCompatibleDC(&dc);//////��ʼ������
	   ///////////////////
	   m_pic.MoveWindow(25,25,WIDTH*H,WIDTH*S,true);
       m_next.MoveWindow(260,45,WIDTH*4,WIDTH*4,true);
	  // m_pic.GetClientRect(&re);
//��ʼ������
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
//	ExitSkin();//�ͷ�Ƥ�����
	KillTimer(TIMER_START);
	bStart = false;
	////////////////////////////
	
	if (mdc)  delete mdc;
	if (mdc2) delete mdc2;
	/////�ͷ�ָ��
 	CDialog::OnClose();
}

void CFKDlg::OnStart() 
{ 
	  GetDlgItem(IDC_START)->EnableWindow(false);//make the button "Start" Disabled;
	  GetDlgItem(IDC_PAUSE)->EnableWindow(true);//make the button "Pause" abled;
	  GetDlgItem(IDC_STOP)->EnableWindow(true);//make the button "Stop" abled;
	  INT_START();////��ʼ��
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
			 BLANK[i][k]=0;//��ʼ������
		///////////////
	  fknow=fkempty;
	  fknext=fkempty;//
	  m_score=0;
	  m_speed=0;
	  ////////////////��ʼ����������
	  DRAW();
	  
}

void CFKDlg::OnPause() 
{
	//  GetDlgItem(IDC_STOP)->SetWindowText(_T("Continue"));
       
	   CString str;
       GetDlgItem(IDC_PAUSE)->GetWindowText(str);////////////////�õ���ť���ڵ�״̬
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
			   ::SetFocus(GetDlgItem(IDC_PIC)->m_hWnd);////�á���ͣ����ťʧȥ����
	   };
	   


}


void CFKDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
	case TIMER_START:
		if (DOWN((fknow.x),(fknow.y+1))==true)
				        fknow.y++;//////�����Զ�����
		DRAW();
		break;
	};
	DRAW();////////////////////////����
	CDialog::OnTimer(nIDEvent);
}


///////////////////////////Those the Code
void CFKDlg::DRAW()
{ 
	  CBitmap *tempbitmap=new CBitmap;
	  CClientDC dc(CWnd::GetDlgItem(IDC_PIC));
	  tempbitmap->CreateCompatibleBitmap(&dc,WIDTH*H,WIDTH*S);////////����һ���հ�ͼƬ
 	  mdc->SelectObject(tempbitmap);///////////////ѡ��ͼƬ
	  mdc->BitBlt(0,0,WIDTH*H,WIDTH*S,mdc2,0,0,BLACKNESS);//////////���Ϻ�ɫ����
	  for(int i=0;i<4;i++)
		  for(int k =0;k<4;k++)
		  {
			  if(fknow.shape[fknow.now][i][k]==1)
			  {
				  CBitmap *temp=new CBitmap;
				  temp->LoadBitmap(fknow.color);				
				  mdc2->SelectObject(temp);
                  mdc->BitBlt((fknow.x+k)*WIDTH,(fknow.y+i)*WIDTH,WIDTH,WIDTH,mdc2,0,0,SRCCOPY);				   
				  delete temp;//////////////////////////////����������������ķ���
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
				  delete temp;//////�����Ѿ��ѻ������ķ���
			  }
		}
	dc.BitBlt(0,0,WIDTH*H,WIDTH*S,mdc,0,0,SRCCOPY);//////////��MDC������Ļ��
	if(tempbitmap) delete tempbitmap;
}
bool CFKDlg::DOWN(int nX,int nY)
{
	
    if(nX<0)
	{
 		return false;///////////////�ж��Ƿ��߳����
	}
	  else 
	  {
		  for(int i =3;i>=0;i--)
			  for(int k =0;k<4;k++)
			  {
				  if(fknow.shape[fknow.now][k][i]==1  && nX+i+1>10)
					  return false;/////////////�ж��Ƿ��߳��ұ�
			  };
		
		  for(int m =0;m<4;m++)
			  for(int n =0;n<4;n++)
			  {
				  if(fknow.shape[fknow.now ][m][n]==1  && nY+m+1>20)/////////�ж��Ƿ񵽴�ײ�
				  {
					  for(int z =0;z<4;z++)
			             for(int u =0;u<4;u++)
						 {
					      	BLANK[fknow.y+z][fknow.x+u]+=fknow.shape[fknow.now ][z][u];////////������ķ�������ݸ�����
						 };
				      fknow=fknext;////��NEXT�������ķ���
			     	  srand(time(0));
	                  fknext=fk[rand()%7];///////��NEXT�������һ���µ�
			          if(fknext.max >0)
					        fknext.now =rand()%fknext.max;
					  fknow.x =H/2-1;
					  XC();////////////////�ж��Ƿ���Ҫ����
					  DRAWNEXT();///////////////////////////////����һ��Ҫ���µķ��黭����Ļ��
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
		///������ײЧ��
	  }
	  ////////////////////////////
	for(int i=0;i<4;i++)
		for(int k=0;k<4;k++)
		{
		    if((BLANK[nY+i][nX+k]+fknow.shape[fknow.now][i][k])==2)////////////////�ж��Ƿ��Ѿ��ͱ�ķ���ײ��һ��
			{
				if((nY-1)<=0)
				{
                      
		              CFKDlg::OnStop();
					  MessageBox("Sorry You Lost!");
			          return false;/////////////////////�������ķ����Ѿ������ˣ���ô������
				};
				for(int m =0;m<4;m++)
			        for(int n =0;n<4;n++)
					{
						BLANK[fknow.y+m][fknow.x+n]+=fknow.shape[fknow.now][m][n];////////������ķ�������ݸ�����
					};
				fknow=fknext;////��NEXT�������ķ���
				srand(time(0));
	            fknext=fk[rand()%7];///////��NEXT�������һ���µ�
			    if(fknext.max >0)
					fknext.now =rand()%fknext.max;
	            fknow.x =H/2-1;
				XC();////////////////�ж��Ƿ���Ҫ����
			    DRAWNEXT();///////////////////////////////����һ��Ҫ���µķ��黭����Ļ��
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
		 if(count==10)//////////////�ж��Ƿ�Ҫ����
		 {
			 for(int m=i;m>0;m--)
				 for(int n=0;n<10;n++)
					 BLANK[m][n]=BLANK[m-1][n];//////////���㣬��ʹ���������
			 for(int z=0;z<10;z++)
				 BLANK[0][z]=0;////////////ʹ��һ�б��
			 i++;//////////////////�ص�ǰһ�м�飬���жϸո�������һ���Ƿ���Ҫ��ȥ
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
			                  //////////////// �����ǲ�ͬ�ķ������в�ͬ���ٶ�
			 case 20000:
				 MessageBox("You Win!");
				 CFKDlg::OnStop();/////////////������־�Ӯ��
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
    DRAWNEXT();/////////////////////��ʼ����������

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
	delete tempDC;///////////////////////����һ�����黭����
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
						fknow.x--;//////���������ƶ�
					DRAW();
					return true;
					break;
				}
			case VK_RIGHT:
				{
					if (DOWN((fknow.x+1),(fknow.y))==true)
						fknow.x++;//////�����ƶ�
					DRAW();
					return true;
					break;
				}
			case VK_DOWN:
				{
					if (DOWN((fknow.x),(fknow.y+1))==true)
						fknow.y++;/////�����ƶ�
					DRAW();
					return true;
					break;
				}
			case VK_UP:
				{
					int tempint;
					tempint=fknow.now;
					fknow.changeshape();//////�������
					if(DOWN(fknow.x,fknow.y)==false)
						fknow.now =tempint;///���β��ɹ�ʱ����Ϊԭ��������
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
					};///////////����ֱ�ӵ��ײ�
					DRAW();
					return true;
					break;
				}
				
			}

		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}
