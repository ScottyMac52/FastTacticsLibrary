#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\FastTacticsLibrary\TwoDCoordinate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define HALF(x) (float) x / 2.00F

namespace Tacticstests
{
	TEST_CLASS(PositionTester)
	{
	private:
		const float MaxX = 300.00F;
		const float MaxY = 300.00F;
	public:

		TEST_METHOD(TestToEnsure00RelativeIsCorrectInAbs)
		{
			// ARRANGE
			TwoDCoordinate relativeCoord = TwoDCoordinate(0.0F, 0.0F);
			TwoDCoordinate expected = TwoDCoordinate(HALF(MaxX), HALF(MaxY));

			// ACT
			TwoDCoordinate actual = relativeCoord.getAbsolutePosition(MaxX, MaxY);

			// ASSERT
			Assert::IsTrue(actual == expected, L"Wrong answer!");
		}

		TEST_METHOD(TestToEnsureMaxXRelativeIsCorrectInAbs)
		{
			// ARRANGE
			TwoDCoordinate relativeCoord = TwoDCoordinate(HALF(MaxX), 0);
			TwoDCoordinate expected = TwoDCoordinate(MaxX, HALF(MaxY));

			// ACT
			TwoDCoordinate actual = relativeCoord.getAbsolutePosition(MaxX, MaxY);

			// ASSERT
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(TestToEnsureMaxYRelativeIsCorrectInAbs)
		{
			// ARRANGE
			TwoDCoordinate relativeCoord = TwoDCoordinate(0, HALF(MaxY));
			TwoDCoordinate expected = TwoDCoordinate(HALF(MaxX), 0);

			// ACT
			TwoDCoordinate actual = relativeCoord.getAbsolutePosition(MaxX, MaxY);

			// ASSERT
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(TestToEnsureMaxNegYRelativeIsCorrectInAbs)
		{
			// ARRANGE
			TwoDCoordinate relativeCoord = TwoDCoordinate(0, -1.00F * HALF(MaxY));
			TwoDCoordinate expected = TwoDCoordinate(HALF(MaxX), MaxY);

			// ACT
			TwoDCoordinate actual = relativeCoord.getAbsolutePosition(MaxX, MaxY);

			// ASSERT
			Assert::IsTrue(actual == expected);
		}


	};
}