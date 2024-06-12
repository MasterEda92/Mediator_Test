
// Mediator_TestMfc.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <memory>
#include <ICommandHandler.h>
#include <IMediator.h>

// CMediatorTestMfcApp:
// See Mediator_TestMfc.cpp for the implementation of this class
//
class CMediatorTestMfcApp : public CWinApp
{
public:
	CMediatorTestMfcApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()

private:
   void Init ();
   void InitCmdHandlers ();
   void InitMediator ();
   void RegisterCmdHandlers ();
   
   std::shared_ptr<MediatorTest::ICommandHandler> m_pAddHandler;
   std::shared_ptr<MediatorTest::IMediator> m_pMediator;
};

extern CMediatorTestMfcApp theApp;
