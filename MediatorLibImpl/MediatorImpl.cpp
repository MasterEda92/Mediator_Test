#include "MediatorImpl.h"

namespace MediatorTest
{

void CMediatorImpl::RegisterCommandHandler(std::string strCmdKey, std::shared_ptr<ICommandHandler> pHandler)
{
   m_mapHandlers.insert_or_assign(strCmdKey, pHandler);
}

std::unique_ptr<ICommandResult> CMediatorImpl::Send(const ICommand& command)
{
   std::string strKey = command.GetCmdKey();
   auto it = m_mapHandlers.find(strKey);
   if (it == m_mapHandlers.end())
      return nullptr;

   return it->second->Handle (command);
}

}
