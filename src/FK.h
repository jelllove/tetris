// FK.h : main header file for the FK application
//

#if !defined(AFX_FK_H__A8163FAC_7641_4ED1_B7A4_E85320ACFD42__INCLUDED_)
#define AFX_FK_H__A8163FAC_7641_4ED1_B7A4_E85320ACFD42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFKApp:
// See FK.cpp for the implementation of this class
//

class CFKApp : public CWinApp
{
public:
	CFKApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFKApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFKApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FK_H__A8163FAC_7641_4ED1_B7A4_E85320ACFD42__INCLUDED_)
