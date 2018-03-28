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
		static int GetPrecision()
		{
			return 4;
		}
	public:

		TEST_CATEGORY(TestToCheckForStringVersion, L"ThreeDCoordinateTests")
		TEST_METHOD(TestToCheckForStringVersion)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(90.0F, 10.0F, 34000.00F, GetPrecision());
			std::wstring expected = L"90.0000° at 10.0000 units -> Angels 34";

			// ACT
			std::wstring strVersion = testCoord.toString();

			// ASSERT
			AssertOnActualNotEqualToExpected(expected, strVersion);

		}

		TEST_CATEGORY(TestDetrminationOfAngels, L"ThreeDCoordinateTests")
		TEST_METHOD(TestDetrminationOfAngels)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(90.0F, 10.0F, 34000.00F, GetPrecision());
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
			ThreeDCoordinate testCoord = ThreeDCoordinate(90.0F, 10.0F, 34000.00F, GetPrecision());
			ThreeDCoordinate expected = ThreeDCoordinate(100.00F, 10.00F, 34000.00F, GetPrecision());

			// ACT
			testCoord += ThreeDCoordinate(10.00F, 0.00F, 0.00F, GetPrecision());

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), testCoord.toString());

		}

		TEST_CATEGORY(TestNegativeBearingChange, L"ThreeDCoordinateTests")
		TEST_METHOD(TestNegativeBearingChange)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(35.0F, 10.0F, 34000.00F, GetPrecision());
			ThreeDCoordinate expected = ThreeDCoordinate(0.00F, 10.00F, 34000.00F, GetPrecision());

			// ACT
			testCoord -= ThreeDCoordinate(35.00F, 0.00F, 0.00F, GetPrecision());

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), testCoord.toString());

		}

		TEST_CATEGORY(TestPositiveRangeChange, L"ThreeDCoordinateTests")
		TEST_METHOD(TestPositiveRangeChange)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(90.0F, 10.0F, 34000.00F, GetPrecision());
			ThreeDCoordinate expected = ThreeDCoordinate(90.00F, 50.00F, 34000.00F, GetPrecision());

			// ACT
			testCoord += ThreeDCoordinate(0.00F, 40.00F, 0.00F, GetPrecision());

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), testCoord.toString());
		}

		TEST_CATEGORY(TestNegativeRangeChange, L"ThreeDCoordinateTests")
		TEST_METHOD(TestNegativeRangeChange)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(90.0F, 50.0F, 34000.00F, GetPrecision());
			ThreeDCoordinate expected = ThreeDCoordinate(90.00F, 10.00F, 34000.00F, GetPrecision());

			// ACT
			testCoord -= ThreeDCoordinate(0.00F, 40.00F, 0.00F, GetPrecision());

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), testCoord.toString());
		}

		TEST_CATEGORY(TestPositiveAltitudeChange, L"ThreeDCoordinateTests")
		TEST_METHOD(TestPositiveAltitudeChange)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(90.0F, 10.0F, 34000.00F, GetPrecision());
			ThreeDCoordinate expected = ThreeDCoordinate(90.00F, 10.00F, 41000.00F, GetPrecision());

			// ACT
			testCoord += ThreeDCoordinate(0.00F, 0.00F, 7000.00F, GetPrecision());

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), testCoord.toString());
		}

		TEST_CATEGORY(TestNegativeAltitudeChange, L"ThreeDCoordinateTests")
		TEST_METHOD(TestNegativeAltitudeChange)
		{
			// ARRANGE
			ThreeDCoordinate testCoord = ThreeDCoordinate(90.0F, 10.0F, 41000.00F, GetPrecision());
			ThreeDCoordinate expected = ThreeDCoordinate(90.00F, 10.00F, 34000.00F, GetPrecision());

			// ACT
			testCoord -= ThreeDCoordinate(0.00F, 0.00F, 7000.00F, GetPrecision());

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), testCoord.toString());
		}

		TEST_CATEGORY(TestEqualityEqual, L"ThreeDCoordinateTests")
		TEST_METHOD(TestEqualityEqual)
		{
			// ARRANGE
			ThreeDCoordinate first = ThreeDCoordinate(90.0F, 10.0F, 34000.00F, GetPrecision());
			ThreeDCoordinate second = ThreeDCoordinate(90.00F, 10.00F, 34000.00F, GetPrecision());

			// ACT and ASSERT
			AssertOnActualNotEqualToExpected(first.toString(), second.toString());
		}

		TEST_CATEGORY(TestEqualityNotEqual, L"ThreeDCoordinateTests")
		TEST_METHOD(TestEqualityNotEqual)
		{
			// ARRANGE
			ThreeDCoordinate first = ThreeDCoordinate(90.0000499F, 10.0F, 34000.00F, GetPrecision());
			ThreeDCoordinate second = ThreeDCoordinate(90.00F, 10.00F, 34000.00F, GetPrecision());

			// ACT and ASSERT
			AssertOnActualEqualToExpected(first.toString(), second.toString());
		}

	};
}