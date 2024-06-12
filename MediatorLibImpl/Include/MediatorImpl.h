#pragma once
#include "IMediator.h"
#include <map>

namespace MediatorTest
{

class CMediatorImpl : public IMediator
{
public:
	void RegisterCommandHandler(std::string strCmdKey, std::shared_ptr<ICommandHandler> pHandler) override;
	std::unique_ptr<ICommandResult> Send(const ICommand& command) override;

private:
	std::map<std::string, std::shared_ptr<ICommandHandler>> m_mapHandlers;
};

}
