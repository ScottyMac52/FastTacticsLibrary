#pragma once

#define GET_DISTANCE(secondPoint) firstPoint.getDistance(secondPoint) 
#define ASSERT_DISTANCE(first, second) AssertOnActualNotEqualToExpected(first, second)

class BaseTester
{
protected:
	void AssertOnActualNotEqualToExpected(float, float);
	std::wstring BaseTester::GetAssertError(float, float) const;
public:
	BaseTester();
	~BaseTester();
};

