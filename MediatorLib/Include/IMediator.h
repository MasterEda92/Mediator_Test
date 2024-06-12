#pragma once
#include <string>
#include <memory>
#include "ICommandHandler.h"

namespace MediatorTest
{

class IMediator
{
public:
   virtual void RegisterCommandHandler (std::string strCmdKey, std::shared_ptr<ICommandHandler> pHandler) = 0;
   virtual std::unique_ptr<ICommandResult> Send (const ICommand& command) = 0;
};

}
