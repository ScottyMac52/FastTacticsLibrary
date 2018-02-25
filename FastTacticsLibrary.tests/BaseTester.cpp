#include "stdafx.h"
#include "BaseTester.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void BaseTester::AssertOnActualNotEqualToExpected(float expected, float actual)
{
	Assert::IsTrue(expected == actual, GetAssertError(expected, actual).c_str());
}

std::wstring BaseTester::GetAssertError(float expected, float actual) const
{
	wchar_t buffer[100];
	swprintf_s(buffer, 100, L"Expected: %f, Actual: %f", expected, actual);
	return std::wstring(buffer);
}

BaseTester::BaseTester()
{
}


BaseTester::~BaseTester()
{
}
