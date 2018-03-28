#include "stdafx.h"
#include "CppUnitTest.h"
#include "globals.h"
#include "..\FastTacticsLibrary\TwoDCoordinate.h"
#include "..\FastTacticsLibrary\PolarCoordinate.h"
#include "..\FastTacticsLibrary\CoordinateConverter.h"
#include "BaseTester.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tacticstests
{
	TEST_CLASS(CoordinateConverterTests), public BaseTester
	{
	private:
		const int ROUNDING_DIGITS = FLOAT_PRECISION;
		const TwoDCoordinate _offSet = TwoDCoordinate(0.0F, 0.0F);
	public:

#pragma region Quadrant I tests 15 -> 75 degrees

		TEST_CATEGORY(Testfor15Degrees, L"Quadrant I")
		TEST_METHOD(Testfor15Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(.259F, .966F);
			PolarCoordinate expected = PolarCoordinate(15.0089F, 1.0001F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor30Degrees, L"Quadrant I")
		TEST_METHOD(Testfor30Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(.5F, .866F);
			PolarCoordinate expected = PolarCoordinate(30.0007F, 1.000F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor45Degrees, L"Quadrant I")
		TEST_METHOD(Testfor45Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(1.0F, 1.0F);
			PolarCoordinate expected = PolarCoordinate(45.0F, 1.4142136F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor60Degrees, L"Quadrant I")
		TEST_METHOD(Testfor60Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(.866F, .5F);
			PolarCoordinate expected = PolarCoordinate(59.9993F, 1.0F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor75Degrees, L"Quadrant I")
		TEST_METHOD(Testfor75Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(.966F, .259F);
			PolarCoordinate expected = PolarCoordinate(74.9911F, 1.0001F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}
#pragma endregion Quadrant I tests 15 -> 75 degrees

#pragma region 90 due east degree test
		TEST_CATEGORY(Testfor90Degrees, L"Due East")
		TEST_METHOD(Testfor90Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(1.0F, 0.0F);
			PolarCoordinate expected = PolarCoordinate(EAST, 1.000F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}
#pragma endregion 90 due east degree test

#pragma region Quadrant IV tests 105 -> 165 degrees
		
		TEST_CATEGORY(Testfor105Degrees, L"Quadrant IV")
		TEST_METHOD(Testfor105Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(.5F, -.866F);
			PolarCoordinate expected = PolarCoordinate(149.9993F, 1.000F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor120Degrees, L"Quadrant IV")
		TEST_METHOD(Testfor120Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(.866F, -.5F);
			PolarCoordinate expected = PolarCoordinate(120.0007F, 1.000F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor135Degrees, L"Quadrant IV")
		TEST_METHOD(Testfor135Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(1.0F, -1.0F);
			PolarCoordinate expected = PolarCoordinate(135.000F, 1.4142136F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor150Degrees, L"Quadrant IV")
		TEST_METHOD(Testfor150Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(.5F, -.866F);
			PolarCoordinate expected = PolarCoordinate(149.9993F, 1.000F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor165Degrees, L"Quadrant IV")
		TEST_METHOD(Testfor165Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(.259F, -.966F);
			PolarCoordinate expected = PolarCoordinate(164.9911F, 1.0001F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}


#pragma endregion Quadrant IV tests 105 -> 165 degrees

#pragma region 180 due south degree test

		TEST_CATEGORY(Testfor180Degrees, L"Due South")
		TEST_METHOD(Testfor180Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(0.0F, -1.0F);
			PolarCoordinate expected = PolarCoordinate(SOUTH, 1.000F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

#pragma endregion 180 due south degree test

#pragma region Quadrant III tests 195 -> 255 degrees

		TEST_CATEGORY(Testfor195Degrees, L"Quadrant III")
		TEST_METHOD(Testfor195Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(-.259F, -.966F);
			PolarCoordinate expected = PolarCoordinate(195.0089F, 1.0001F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}
		TEST_CATEGORY(Testfor210Degrees, L"Quadrant III")
		TEST_METHOD(Testfor210Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(-.5F, -.866F);
			PolarCoordinate expected = PolarCoordinate(210.0007F, 1.0F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor225Degrees, L"Quadrant III")
		TEST_METHOD(Testfor225Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(-1.0F, -1.0F);
			PolarCoordinate expected = PolarCoordinate(225.000F, 1.4142136F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor240Degrees, L"Quadrant III")
		TEST_METHOD(Testfor240Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(-.866F, -.5F);
			PolarCoordinate expected = PolarCoordinate(239.9993F, 1.000F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor255Degrees, L"Quadrant III")
		TEST_METHOD(Testfor255Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(-.966F, -.259F);
			PolarCoordinate expected = PolarCoordinate(254.9911F, 1.0001F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}


#pragma endregion Quadrant III tests 195 -> 255 degrees

#pragma region 270 due west degree test

		TEST_CATEGORY(Testfor270Degrees, L"Due West")
		TEST_METHOD(Testfor270Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(-1.0F, -0.0F);
			PolarCoordinate expected = PolarCoordinate(WEST, 1.000F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

#pragma endregion 270 due west degree test
		
#pragma region Quadrant II tests 285 -> 345 degrees

		TEST_CATEGORY(Testfor285Degrees, L"Quadrant II")
		TEST_METHOD(Testfor285Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(-.966F, .259F);
			PolarCoordinate expected = PolarCoordinate(285.0089F, 1.0001F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor300Degrees, L"Quadrant II")
		TEST_METHOD(Testfor300Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(-.866F, .5F);
			PolarCoordinate expected = PolarCoordinate(300.0007F, 1.000F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor315Degrees, L"Quadrant II")
		TEST_METHOD(Testfor315Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(-1.0F, 1.0F);
			PolarCoordinate expected = PolarCoordinate(315.000F, 1.4142136F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor330Degrees, L"Quadrant II")
		TEST_METHOD(Testfor330Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(-.5F, .866F);
			PolarCoordinate expected = PolarCoordinate(329.9993F, 1.000F);
			
			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

		TEST_CATEGORY(Testfor345Degrees, L"Quadrant II")
		TEST_METHOD(Testfor345Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(-.259F, .966F);
			PolarCoordinate expected = PolarCoordinate(344.9911F, 1.0001F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

#pragma endregion Quadrant II tests 285 -> 345 degrees

#pragma region 360 due north degree test

		TEST_CATEGORY(Testfor360Degrees, L"Due North")
		TEST_METHOD(Testfor360Degrees)
		{
			// ARRANGE
			TwoDCoordinate testPoint = TwoDCoordinate(-0.00000F, 1.000000F);
			PolarCoordinate expected = PolarCoordinate(NORTH, 1.00000F);

			// ACT
			PolarCoordinate actual = CoordinateConverter::ConvertFrom2DToPolar(testPoint);
			TwoDCoordinate convertedPoint = CoordinateConverter::ConvertFromPolarTo2D(actual, _offSet);

			// ASSERT
			AssertOnActualNotEqualToExpected(expected.toString(), actual.toString());
			AssertOnActualNotEqualToExpected(testPoint.toString(), convertedPoint.toString());
		}

#pragma endregion 360 due north degree test

	};
}