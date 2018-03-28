#pragma once
#define FLOAT_PRECISION 4
#define HALF(x) (float) x / 2.00F
#define GET_DISTANCE(secondPoint) firstPoint.getDistance(secondPoint) 
#define ASSERT_DISTANCE(first, second) AssertOnActualNotEqualToExpected(first, second)

#define TEST_CATEGORY_NAME(categoryName) TEST_METHOD_ATTRIBUTE(L"TestCategory", categoryName)
#define TEST_CATEGORY(methodName, categoryName) BEGIN_TEST_METHOD_ATTRIBUTE(methodName) TEST_CATEGORY_NAME(categoryName) END_TEST_METHOD_ATTRIBUTE()
