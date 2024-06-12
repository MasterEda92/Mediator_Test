#pragma once
#include <string>
#include <functional>
#include "ICliCommandHandler.h"

class ICliCommand
{
public:
   virtual ~ICliCommand () {}
   virtual std::string GetCommand() const = 0;
   virtual std::string GetDescription() const = 0;
   virtual void SetCommandFn(std::function<void()> fn) = 0;
   virtual void SetCommandHandler(ICliCommandHandler* pHandler) = 0;
   virtual void Run() = 0;
};
