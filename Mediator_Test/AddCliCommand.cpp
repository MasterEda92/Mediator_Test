#include "AddCliCommand.h"
#include <iostream>
#include "AddCommand.h"

void CAddCliCommand::Add()
{
   auto Res = m_pMediator->Send(MediatorTest::CAddCommand(GetFirstNumber(), GetSecondNumber()));
   std::cout << "Das Ergebnis ist " << ((MediatorTest::CAddCommandResult*)Res.get())->GetResult() << std::endl;
}

int CAddCliCommand::GetFirstNumber() const
{
   std::string strInput;
   std::cout << "Geben Sie die erste Zahl ein:" << std::endl;
   std::getline(std::cin, strInput);
   return std::stoi (strInput);
}

int CAddCliCommand::GetSecondNumber() const
{
   std::string strInput;
   std::cout << "Geben Sie die zweite Zahl ein:" << std::endl;
   std::getline(std::cin, strInput);
   return std::stoi (strInput);
}
