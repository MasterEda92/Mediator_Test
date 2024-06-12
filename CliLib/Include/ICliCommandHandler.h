#pragma once
#include <memory>
#include <string>

class ICliCommand;
class ICliCommandHandler
{
public:
   virtual ~ICliCommandHandler () {}
   virtual void AddCommand(std::shared_ptr<ICliCommand> pCommand) = 0;
   virtual void ListCommands() const = 0;
   virtual void RunCli() const = 0;
   virtual void InvokeCommand(std::string strCommand) const = 0;
};
