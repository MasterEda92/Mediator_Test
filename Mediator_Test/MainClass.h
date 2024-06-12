#pragma once
#include <memory>
#include "ICommandHandler.h"
#include "IMediator.h"
#include <ICliCommandHandler.h>

class CMain
{
public:
   int Main ();
   void Init ();

private:
   void InitCmdHandlers ();
   void InitMediator ();
   void RegisterCmdHandlers ();
   void InitCliCommandHandler ();
   void RegisterCliCommands ();

private:
   std::shared_ptr<MediatorTest::ICommandHandler> m_pAddHandler;
   std::shared_ptr<MediatorTest::IMediator> m_pMediator;
   std::shared_ptr<ICliCommandHandler> m_pCliCommandHandler;
};

