#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\FastTacticsLibrary\ThreeDCoordinate.h"
#include "globals.h"
#include "BaseTester.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tacticstests
{		
	TEST_CLASS(ThreeDCoordinateTests), public BaseTester
	{
	private:
		const int ROUNDING_DIGITS = MAX_FLOAT_DIGITS;

	public:
		
		TEST_CATEGORY(TestToCheckForStringVersion, L"ThreeDCoordinateTests")
		TEST_METHOD(TestToCheckForStringVersion)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(PolarCoordinate(90.0F, 10.0F), 34000.00F);
			std::wstring expected = L"90.0000° at 10.0000 units -> Angels 34";

			// ACT
			std::wstring strVersion = testCoord.toString(ROUNDING_DIGITS);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected, strVersion);

		}

		TEST_CATEGORY(TestDetrminationOfAngels, L"ThreeDCoordinateTests")
		TEST_METHOD(TestDetrminationOfAngels)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(PolarCoordinate(90.0F, 10.0F), 34000.00F);
			std::wstring expected = L"Angels 34";

			// ACT
			std::wstring actual = testCoord.getAngels();
			
			// ASSERT
			Assert::AreEqual(expected, actual);
		}

		TEST_CATEGORY(TestPositiveBearingChange, L"ThreeDCoordinateTests")
		TEST_METHOD(TestPositiveBearingChange)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(PolarCoordinate(90.0F, 10.0F), 34000.00F);
			ThreeDCoordinate expected = ThreeDCoordinate(PolarCoordinate(100.00F, 10.00F), 34000.00F);

			// ACT
			testCoord += ThreeDCoordinate(PolarCoordinate(10.00F, 0.00F), 0.00F);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(ROUNDING_DIGITS), testCoord.toString(ROUNDING_DIGITS));

		}

		TEST_CATEGORY(TestNegativeBearingChange, L"ThreeDCoordinateTests")
		TEST_METHOD(TestNegativeBearingChange)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(PolarCoordinate(135.0F, 10.0F), 34000.00F);
			ThreeDCoordinate expected = ThreeDCoordinate(PolarCoordinate(100.00F, 10.00F), 34000.00F);

			// ACT
			testCoord -= ThreeDCoordinate(PolarCoordinate(35.00F, 0.00F), 0.00F);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(ROUNDING_DIGITS), testCoord.toString(ROUNDING_DIGITS));

		}

		TEST_CATEGORY(TestPositiveRangeChange, L"ThreeDCoordinateTests")
		TEST_METHOD(TestPositiveRangeChange)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(PolarCoordinate(90.0F, 10.0F), 34000.00F);
			ThreeDCoordinate expected = ThreeDCoordinate(PolarCoordinate(90.00F, 50.00F), 34000.00F);

			// ACT
			testCoord += ThreeDCoordinate(PolarCoordinate(0.00F, 40.00F), 0.00F);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(ROUNDING_DIGITS), testCoord.toString(ROUNDING_DIGITS));
		}

		TEST_CATEGORY(TestNegativeRangeChange, L"ThreeDCoordinateTests")
		TEST_METHOD(TestNegativeRangeChange)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(PolarCoordinate(90.0F, 50.0F), 34000.00F);
			ThreeDCoordinate expected = ThreeDCoordinate(PolarCoordinate(90.00F, 10.00F), 34000.00F);

			// ACT
			testCoord -= ThreeDCoordinate(PolarCoordinate(0.00F, 40.00F), 0.00F);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(ROUNDING_DIGITS), testCoord.toString(ROUNDING_DIGITS));
		}

		TEST_CATEGORY(TestPositiveAltitudeChange, L"ThreeDCoordinateTests")
		TEST_METHOD(TestPositiveAltitudeChange)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(PolarCoordinate(90.0F, 10.0F), 34000.00F);
			ThreeDCoordinate expected = ThreeDCoordinate(PolarCoordinate(90.00F, 10.00F), 41000.00F);

			// ACT
			testCoord += ThreeDCoordinate(PolarCoordinate(0.00F, 0.00F), 7000.00F);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(ROUNDING_DIGITS), testCoord.toString(ROUNDING_DIGITS));
		}

		TEST_CATEGORY(TestNegativeAltitudeChange, L"ThreeDCoordinateTests")
		TEST_METHOD(TestNegativeAltitudeChange)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(PolarCoordinate(90.0F, 10.0F), 41000.00F);
			ThreeDCoordinate expected = ThreeDCoordinate(PolarCoordinate(90.00F, 10.00F), 34000.00F);

			// ACT
			testCoord -= ThreeDCoordinate(PolarCoordinate(0.00F, 0.00F), 7000.00F);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(ROUNDING_DIGITS), testCoord.toString(ROUNDING_DIGITS));
		}

		TEST_CATEGORY(TestEqualityEqual, L"ThreeDCoordinateTests")
		TEST_METHOD(TestEqualityEqual)
		{
			// ARRANGE
			ThreeDCoordinate first = ThreeDCoordinate(PolarCoordinate(90.0F, 10.0F), 34000.00F);
			ThreeDCoordinate second = ThreeDCoordinate(PolarCoordinate(90.00F, 10.00F), 34000.00F);

			// ACT and ASSERT
			AssertOnActualNotEqualToExpected(first.toString(ROUNDING_DIGITS), second.toString(ROUNDING_DIGITS));
		}

		TEST_CATEGORY(TestEqualityNotEqual, L"ThreeDCoordinateTests")
		TEST_METHOD(TestEqualityNotEqual)
		{
			// ARRANGE
			ThreeDCoordinate first = ThreeDCoordinate(PolarCoordinate(90.0000499F, 10.0F), 34000.00F);
			ThreeDCoordinate second = ThreeDCoordinate(PolarCoordinate(90.00F, 10.00F), 34000.00F);

			// ACT and ASSERT
			AssertOnActualEqualToExpected(first.toString(ROUNDING_DIGITS), second.toString(ROUNDING_DIGITS));
		}

	};
}