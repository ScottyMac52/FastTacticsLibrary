#pragma once
#include "..\FastTacticsLibrary\PolarCoordinate.h"
#include "..\FastTacticsLibrary\TwoDCoordinate.h"

class BaseTester
{
protected:
	void AssertOnActualNotEqualToExpected(std::wstring, std::wstring);
	void AssertOnActualEqualToExpected(std::wstring expected, std::wstring actual);
	void AssertOnActualNotEqualToExpected(float, float);
	std::wstring GetAssertError(std::wstring, std::wstring) const;
	std::wstring GetAssertError(float, float) const;
public:
	BaseTester();
	~BaseTester();
};

