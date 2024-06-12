#pragma once
#include <CliCommand.h>
#include "IMediator.h"
class CAddCliCommand : public CCliCommand
{
public:
	CAddCliCommand(std::shared_ptr<MediatorTest::IMediator> pMediator) 
		: CCliCommand ("a", "Add two numbers", std::bind (&CAddCliCommand::Add, this))
		, m_pMediator (pMediator)
	{
	}

	virtual ~CAddCliCommand() {}
private:
   void Add ();

	int GetFirstNumber() const;
	int GetSecondNumber () const;

private:
	std::shared_ptr<MediatorTest::IMediator> m_pMediator;
};

