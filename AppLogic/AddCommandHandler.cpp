#include "AddCommandHandler.h"
#include "AddCommand.h"

namespace MediatorTest
{

std::unique_ptr<ICommandResult> CAddCommandHandler::Handle(const ICommand& command)
{
   int nResult = ((CAddCommand&)command).GetFirst() + ((CAddCommand&)command).GetSecond();
   return std::make_unique<CAddCommandResult>(nResult);
}

}
