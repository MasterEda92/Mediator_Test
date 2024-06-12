#pragma once
#include "ICliCommandHandler.h"
#include <map>

class CCliCommandHandler : public ICliCommandHandler {
public:
   CCliCommandHandler(std::string strWelcomeMsg);
   virtual ~CCliCommandHandler () {}

   void AddCommand(std::shared_ptr<ICliCommand> pCommand);
   void ListCommands() const;
   void RunCli() const;
   void InvokeCommand(std::string strCommand) const;

protected:
   bool GetInputAndHandleCommand() const;
   bool HandleCommand (std::string strCommand) const;
   void Help() const;

private:
   std::string GetCommandInput () const;

protected:
   std::string m_strWelcomeMsg;
   std::map<std::string, std::shared_ptr<ICliCommand>> m_mapCommands;
};
