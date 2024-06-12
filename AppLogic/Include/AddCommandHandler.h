#pragma once
#include "ICommandHandler.h"

namespace MediatorTest
{

class CAddCommandHandler : public ICommandHandler
{
public:
   virtual std::unique_ptr<ICommandResult> Handle (const ICommand& command) override;
};

}
