#pragma once
#include <memory>
#include "ICommand.h"

namespace MediatorTest
{
   
class ICommandHandler
{
public:
   virtual std::unique_ptr <ICommandResult> Handle (const ICommand& command) = 0;
};

}