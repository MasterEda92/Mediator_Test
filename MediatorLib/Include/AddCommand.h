#pragma once
#include "ICommand.h"

namespace MediatorTest
{

class CAddCommand : public ICommand
{
public:
	CAddCommand(int nFirst, int nSecond) : m_nFirst (nFirst), m_nSecond (nSecond)
	{
	}
	static std::string GetCmdKeyS () { return "AddCmd"; }
	virtual std::string GetCmdKey () const override { return CAddCommand::GetCmdKeyS(); }

	int GetFirst () const { return m_nFirst; }
	int GetSecond () const { return m_nSecond; }
private:
	int m_nFirst;
	int m_nSecond;
};

class CAddCommandResult : public ICommandResult
{
public:
	CAddCommandResult(int nResult) : m_nResult (nResult)
	{
	}

	int GetResult () const { return m_nResult; }
private:
	int m_nResult;
};

}


