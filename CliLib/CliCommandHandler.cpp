#include "CliCommandHandler.h"
#include <iostream>
#include <ICliCommand.h>

CCliCommandHandler::CCliCommandHandler(std::string strWelcomeMsg)
   : m_strWelcomeMsg(strWelcomeMsg) {}

void CCliCommandHandler::AddCommand(std::shared_ptr<ICliCommand> pCommand) 
{
   pCommand->SetCommandHandler(this);
   m_mapCommands.insert_or_assign(pCommand->GetCommand(), pCommand);
}

void CCliCommandHandler::ListCommands() const 
{
   std::cout << "h -> Hilfe anzeigen" << std::endl;
   std::cout << "q -> Programm beenden" << std::endl;
   for (auto& it : m_mapCommands) {
      std::cout << it.first << " -> " << it.second->GetDescription() << std::endl;
   }
}
void CCliCommandHandler::RunCli() const 
{
   std::cout << m_strWelcomeMsg << std::endl
      << "Folende Aktionen können durchgeführt werden:" << std::endl;
   ListCommands();

   bool bContinue = false;
   do {
      bContinue = GetInputAndHandleCommand();
   } while (bContinue);
}

void CCliCommandHandler::InvokeCommand (std::string strCommand) const
{
   auto it = m_mapCommands.find(strCommand);
   if (it != m_mapCommands.end())
      it->second->Run();
}

bool CCliCommandHandler::GetInputAndHandleCommand() const 
{
   return HandleCommand(GetCommandInput());
}

bool CCliCommandHandler::HandleCommand(std::string strCommand) const
{
   bool bContinue = true;
   switch (strCommand.c_str()[0]) {
   case 'h': {
      Help();
      break;
   }
   case 'q': {
      bContinue = false;
      break;
   }
   default: {
      InvokeCommand(strCommand);
      break;
   }
   }
   return bContinue;
}

void CCliCommandHandler::Help() const 
{ 
   ListCommands(); 
}

std::string CCliCommandHandler::GetCommandInput() const
{
   std::string strInput;
   std::getline(std::cin, strInput);
   return strInput;
}

