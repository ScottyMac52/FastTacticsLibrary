#include "stdafx.h"
#include "BaseTester.h"
#include "..\FastTacticsLibrary\TwoDCoordinate.h"
#include "..\FastTacticsLibrary\PolarCoordinate.h"
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

void BaseTester::AssertOnActualNotEqualToExpected(std::wstring expected, std::wstring actual)
{
	Assert::IsTrue(expected == actual, GetAssertError(expected, actual).c_str());
}

void BaseTester::AssertOnActualEqualToExpected(std::wstring expected, std::wstring actual)
{
	Assert::IsFalse(expected == actual, GetAssertError(expected, actual).c_str());
}

void BaseTester::AssertOnActualNotEqualToExpected(float expected, float actual)
{
	Assert::IsTrue(expected == actual);
}

std::wstring BaseTester::GetAssertError(std::wstring expected, std::wstring actual) const
{
	wchar_t buffer[200];
	swprintf_s(buffer, 200, L"Expected: %s, Actual: %s", expected.c_str(), actual.c_str());
	return std::wstring(buffer);
}

std::wstring BaseTester::GetAssertError(float expected, float actual) const
{
	wchar_t buffer[200];
	swprintf_s(buffer, 200, L"Expected: %f, Actual: %f", expected, actual);
	return std::wstring(buffer);
}


BaseTester::BaseTester()
{
}


BaseTester::~BaseTester()
{
}
