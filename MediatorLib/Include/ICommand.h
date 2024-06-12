#pragma once
#include <string>
namespace MediatorTest
{

class ICommand {
public:
   virtual std::string GetCmdKey () const = 0;
};

class ICommandResult {};

}
