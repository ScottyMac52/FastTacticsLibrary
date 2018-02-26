#include "stdafx.h"
#include "CppUnitTest.h"
#include "globals.h"
#include "..\FastTacticsLibrary\TwoDCoordinate.h"
#include "BaseTester.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tacticstests
{
	TEST_CLASS(PositionTester), public BaseTester
	{
	private:
		const float MaxX = 600.00F;
		const float MaxY = 600.00F;
		const int ROUNDING_DIGITS = MAX_FLOAT_DIGITS;
	public:

#pragma region PositionTester for TwoDCoordinate 

		TEST_CATEGORY(TestToEnsure00RelativeIsCorrectInAbs, L"PositionTester - TwoDCoordinate")
		TEST_METHOD(TestToEnsure00RelativeIsCorrectInAbs)
		{
			// ARRANGE
			TwoDCoordinate relativeCoord = TwoDCoordinate(0.0F, 0.0F);
			TwoDCoordinate expected = TwoDCoordinate(HALF(MaxX), HALF(MaxY));

			// ACT
			TwoDCoordinate actual = relativeCoord.getAbsolutePosition(MaxX, MaxY);

			// ASSERT
			AssertOnActualNotEqualToExpected(actual.toString(ROUNDING_DIGITS), expected.toString(ROUNDING_DIGITS));
		}

		TEST_CATEGORY(TestToEnsureMaxXRelativeIsCorrectInAbs, L"PositionTester - TwoDCoordinate")
		TEST_METHOD(TestToEnsureMaxXRelativeIsCorrectInAbs)
		{
			// ARRANGE
			TwoDCoordinate relativeCoord = TwoDCoordinate(HALF(MaxX), 0);
			TwoDCoordinate expected = TwoDCoordinate(MaxX, HALF(MaxY));

			// ACT
			TwoDCoordinate actual = relativeCoord.getAbsolutePosition(MaxX, MaxY);

			// ASSERT
			AssertOnActualNotEqualToExpected(actual.toString(ROUNDING_DIGITS), expected.toString(ROUNDING_DIGITS));
		}

		TEST_CATEGORY(TestToEnsureMaxYRelativeIsCorrectInAbs, L"PositionTester - TwoDCoordinate")
		TEST_METHOD(TestToEnsureMaxYRelativeIsCorrectInAbs)
		{
			// ARRANGE
			TwoDCoordinate relativeCoord = TwoDCoordinate(0, HALF(MaxY));
			TwoDCoordinate expected = TwoDCoordinate(HALF(MaxX), 0);

			// ACT
			TwoDCoordinate actual = relativeCoord.getAbsolutePosition(MaxX, MaxY);

			// ASSERT
			AssertOnActualNotEqualToExpected(actual.toString(ROUNDING_DIGITS), expected.toString(ROUNDING_DIGITS));
		}

		TEST_CATEGORY(TestToEnsureMaxNegYRelativeIsCorrectInAbs, L"PositionTester - TwoDCoordinate")
		TEST_METHOD(TestToEnsureMaxNegYRelativeIsCorrectInAbs)
		{
			// ARRANGE
			TwoDCoordinate relativeCoord = TwoDCoordinate(0, -1.00F * HALF(MaxY));
			TwoDCoordinate expected = TwoDCoordinate(HALF(MaxX), MaxY);

			// ACT
			TwoDCoordinate actual = relativeCoord.getAbsolutePosition(MaxX, MaxY);

			// ASSERT
			AssertOnActualNotEqualToExpected(actual.toString(ROUNDING_DIGITS), expected.toString(ROUNDING_DIGITS));
		}
#pragma endregion PositionTester for TwoDCoordinate 

	};
}