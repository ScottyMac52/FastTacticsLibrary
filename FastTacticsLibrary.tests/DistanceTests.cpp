#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\FastTacticsLibrary\TwoDCoordinate.h"
#include "BaseTester.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tacticstests
{		
	TEST_CLASS(DistanceTester), public BaseTester
	{
	public:
		
		TEST_METHOD(TestToEnsureThatPosition34ResultsInDistanceOf5)
		{
			// ARRANGE
			TwoDCoordinate firstPoint = TwoDCoordinate(0, 0);
			TwoDCoordinate secondPoint = TwoDCoordinate(3, 4);
			float expected = 5.0F;

			// ACT
			float distance = GET_DISTANCE(secondPoint);

			// ASSERT
			ASSERT_DISTANCE(expected, distance);
		}

		TEST_METHOD(TestToEnsureThatPositionNeg3Neg4ResultsInDistanceOf5)
		{
			// ARRANGE
			TwoDCoordinate firstPoint = TwoDCoordinate(0, 0);
			TwoDCoordinate secondPoint = TwoDCoordinate(-3, -4);
			float expected = 5.0F;

			// ACT
			float distance = GET_DISTANCE(secondPoint);

			// ASSERT
			ASSERT_DISTANCE(expected, distance);
		}


		TEST_METHOD(TestToEnsureThatPosition0ResultsInDistanceOf0)
		{
			// ARRANGE
			TwoDCoordinate firstPoint = TwoDCoordinate(0, 0);
			TwoDCoordinate secondPoint = TwoDCoordinate(0, 0);
			float expected = 0.0F;

			// ACT
			float distance = GET_DISTANCE(secondPoint);

			// ASSERT
			ASSERT_DISTANCE(expected, distance);
		}

		TEST_METHOD(TestToEnsureThatPosition11ResultsInDistanceOf1Point41421354)
		{
			// ARRANGE
			TwoDCoordinate firstPoint = TwoDCoordinate(0, 0);
			TwoDCoordinate secondPoint = TwoDCoordinate(1, 1);
			float expected = 1.41421354F;

			// ACT
			float distance = GET_DISTANCE(secondPoint);

			// ASSERT
			ASSERT_DISTANCE(expected, distance);
		}

		TEST_METHOD(TestToEnsureThatPositionNeg1Neg1ResultsInDistanceOf1Point41421354)
		{
			// ARRANGE
			TwoDCoordinate firstPoint = TwoDCoordinate(0, 0);
			TwoDCoordinate secondPoint = TwoDCoordinate(-1, -1);
			float expected = 1.41421354F;

			// ACT
			float distance = GET_DISTANCE(secondPoint);

			// ASSERT
			ASSERT_DISTANCE(expected, distance);
		}

		TEST_METHOD(TestToEnsureDistanceOf1Is707OnBothSides)
		{
			// ARRANGE
			TwoDCoordinate firstPoint = TwoDCoordinate(0, 0);
			TwoDCoordinate secondPoint = TwoDCoordinate(0.7071068F, 0.7071068F);
			float expected = 1.00000012F;

			// ACT
			float distance = GET_DISTANCE(secondPoint);

			// ASSERT
			ASSERT_DISTANCE(expected, distance);
		}

		TEST_METHOD(TestToEnsureDistanceOf10Is7_07OnBothSides)
		{
			// ARRANGE
			TwoDCoordinate firstPoint = TwoDCoordinate(0, 0);
			TwoDCoordinate secondPoint = TwoDCoordinate(7.071068F, 7.071068F);
			float expected = 10.0F;

			// ACT
			float distance = GET_DISTANCE(secondPoint);

			// ASSERT
			ASSERT_DISTANCE(expected, distance);
		}
	};
}