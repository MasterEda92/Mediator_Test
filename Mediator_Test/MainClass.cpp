#include "MainClass.h"
#include "AddCommandHandler.h"
#include "MediatorImpl.h"
#include "AddCommand.h"
#include <iostream>
#include <CliCommandHandler.h>
#include "AddCliCommand.h"

int CMain::Main()
{
   Init();

   m_pCliCommandHandler->RunCli();

   return 0;
}

void CMain::Init()
{
   InitCmdHandlers();
   InitMediator();
   RegisterCmdHandlers();
   InitCliCommandHandler();
   RegisterCliCommands();
}

void CMain::InitCmdHandlers()
{
   m_pAddHandler = std::make_shared<MediatorTest::CAddCommandHandler>();
}

void CMain::InitMediator()
{
   m_pMediator = std::make_shared<MediatorTest::CMediatorImpl>();
}

void CMain::RegisterCmdHandlers()
{
   m_pMediator->RegisterCommandHandler(MediatorTest::CAddCommand::GetCmdKeyS(), m_pAddHandler);
}

void CMain::InitCliCommandHandler()
{
   m_pCliCommandHandler = std::make_shared<CCliCommandHandler>("Willkommen zum Mediator-CLI-Testprogramm!");
}

void CMain::RegisterCliCommands()
{
   m_pCliCommandHandler->AddCommand(std::make_shared<CAddCliCommand>(m_pMediator));
}
