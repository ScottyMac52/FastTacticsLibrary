#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\FastTacticsLibrary\PolarCoordinate.h"
#include "globals.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tacticstests
{
	TEST_CLASS(PolarCoordinateTests)
	{
		TEST_CATEGORY(TestOperatorEqual, L"Operator Tests - PolarCoordinate")
		TEST_METHOD(TestOperatorEqual)
		{
			// ARRANGE
			PolarCoordinate first = PolarCoordinate(90.0F, 10.0F);
			PolarCoordinate second = PolarCoordinate(90.0F, 10.0F);
			
			// ACT
			bool areEqual = first == second;

			// ASSERT
			Assert::IsTrue(areEqual);
		}

		TEST_CATEGORY(TestOperatorNotEqual, L"Operator Tests - PolarCoordinate")
		TEST_METHOD(TestOperatorNotEqual)
		{

			PolarCoordinate first = PolarCoordinate(90.0F, 10.0F);
			PolarCoordinate second = PolarCoordinate(90.0F, 10.1F);

			// ACT
			bool areEqual = first == second;

			// ASSERT
			Assert::IsFalse(areEqual);
		}

		TEST_CATEGORY(TestOperatorPlusEqualForRange, L"Operator Tests - PolarCoordinate")
		TEST_METHOD(TestOperatorPlusEqualForRange)
		{
			// ARRANGE
			PolarCoordinate first = PolarCoordinate(90.0F, 10.0F);
			PolarCoordinate offset = PolarCoordinate(0.0F, 10.0F);
			PolarCoordinate expected = PolarCoordinate(90.0F, 20.0F);

			// ACT
			PolarCoordinate actual = first += offset;

			// ASSERT
			Assert::IsTrue(expected == actual);
		}

		TEST_CATEGORY(TestOperatorMinusEqualForRange, L"Operator Tests - PolarCoordinate")
		TEST_METHOD(TestOperatorMinusEqualForRange)
		{
			// ARRANGE
			PolarCoordinate first = PolarCoordinate(90.0F, 10.0F);
			PolarCoordinate offset = PolarCoordinate(0.0F, 10.0F);
			PolarCoordinate expected = PolarCoordinate(90.0F, 0.0F);

			// ACT
			PolarCoordinate actual = first -= offset;

			// ASSERT
			Assert::IsTrue(expected == actual);
		}

		TEST_CATEGORY(TestOperatorPlusEqualForDegrees, L"Operator Tests - PolarCoordinate")
		TEST_METHOD(TestOperatorPlusEqualForDegrees)
		{
			// ARRANGE
			PolarCoordinate first = PolarCoordinate(90.0F, 10.0F);
			PolarCoordinate offset = PolarCoordinate(45.0F, 0.0F);
			PolarCoordinate expected = PolarCoordinate(135.0F, 10.0F);

			// ACT
			PolarCoordinate actual = first += offset;

			// ASSERT
			Assert::IsTrue(expected == actual);
		}

		TEST_CATEGORY(TestOperatorMinusEqualForDegrees, L"Operator Tests - PolarCoordinate")
		TEST_METHOD(TestOperatorMinusEqualForDegrees)
		{
			// ARRANGE
			PolarCoordinate first = PolarCoordinate(90.0F, 10.0F);
			PolarCoordinate offset = PolarCoordinate(45.0F, 0.0F);
			PolarCoordinate expected = PolarCoordinate(45.0F, 10.0F);

			// ACT
			PolarCoordinate actual = first -= offset;

			// ASSERT
			Assert::IsTrue(expected == actual);
		}

	};
}