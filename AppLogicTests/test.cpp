#include "pch.h"
#include "AddCommandHandler.h"
#include "AddCommand.h"

TEST(AddCommandHandlerTests, AddCommandHandlerHandlesAdditionOfTwoPositiveNumbersCorrect) {
  auto toTest = std::make_unique<MediatorTest::CAddCommandHandler>();
  auto Result = toTest->Handle (MediatorTest::CAddCommand (4, 3));
  EXPECT_EQ (((MediatorTest::CAddCommandResult*)Result.get())->GetResult(), 7);
}

TEST(AddCommandHandlerTests, AddCommandHandlerHandlesAdditionOfTwoNegativeNumbersCorrect) {
  auto toTest = std::make_unique<MediatorTest::CAddCommandHandler>();
  auto Result = toTest->Handle (MediatorTest::CAddCommand (-4, -3));
  EXPECT_EQ (((MediatorTest::CAddCommandResult*)Result.get())->GetResult(), -7);
}

TEST(AddCommandHandlerTests, AddCommandHandlerHandlesAdditionOfNegativeAndPositiveNumbersCorrect) {
  auto toTest = std::make_unique<MediatorTest::CAddCommandHandler>();
  auto Result = toTest->Handle (MediatorTest::CAddCommand (-4, 3));
  EXPECT_EQ (((MediatorTest::CAddCommandResult*)Result.get())->GetResult(), -1);
}

TEST(AddCommandHandlerTests, AddCommandHandlerHandlesAdditionOfTwoZerosCorrect) {
  auto toTest = std::make_unique<MediatorTest::CAddCommandHandler>();
  auto Result = toTest->Handle (MediatorTest::CAddCommand (0, 0));
  EXPECT_EQ (((MediatorTest::CAddCommandResult*)Result.get())->GetResult(), 0);
}

TEST(AddCommandHandlerTests, AddCommandHandlerHandlesAdditionOfNumberAndZeroCorrect) {
  auto toTest = std::make_unique<MediatorTest::CAddCommandHandler>();
  auto Result = toTest->Handle (MediatorTest::CAddCommand (5, 0));
  EXPECT_EQ (((MediatorTest::CAddCommandResult*)Result.get())->GetResult(), 5);
}
