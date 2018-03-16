#include "stdafx.h"
#include "CppUnitTest.h"
#include "globals.h"
#include "..\FastTacticsLibrary\PolarCoordinate.h"
#include "..\FastTacticsLibrary\Contact.h"
#include <chrono>
#include <thread>
#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tacticstests
{
	TEST_CLASS(ContactTester)
	{
	private:
		const float MaxX = 600.00F;
		const float MaxY = 600.00F;
		const int ROUNDING_DIGITS = MAX_FLOAT_DIGITS;
	public:

#pragma region ContactTester 

		TEST_CATEGORY(TestToEnsureThatSpeedChangeResultsInPositionCalculation, L"ContactTester")
		TEST_METHOD(TestToEnsureThatSpeedChangeResultsInPositionCalculation)
		{
			// ARRANGE
			PolarCoordinate pcPos = PolarCoordinate(90.0F, 50.0F);
			Contact *testContact = new Contact(pcPos, 5000.0F, 500.0F, 90.0F, ContactPersonality::Friendly, ContactMission::Air);

			// ACT
			testContact->ChangeSpeed(400.0F);
			std::this_thread::sleep_for(std::chrono::seconds(20));

			// ASSERT
			Assert::IsFalse(testContact->getPolarCoordinate() == pcPos);
		}

#pragma endregion ContactTester

	};
}
