
#include <assert.h>
#include <iostream>

#include <r3/validation/r3-validation-utils.hpp>

using namespace r3::validation;

bool testIsInRange_MinOnly(int minValue, int value, bool expectedResult) {
	IntRange range = IntRange::createMin(minValue);
	bool actualResult = range.isInRange(value);

	bool result = (actualResult == expectedResult);
	return result;
}

bool testIsInRange_MaxOnly(int maxValue, int value, bool expectedResult) {
	IntRange range = IntRange::createMax(maxValue);
	bool actualResult = range.isInRange(value);

	bool result = (actualResult == expectedResult);
	return result;
}

bool testIsInRange_MinAndMax(int minValue, int maxValue, int value, bool expectedResult) {
	IntRange range = IntRange::create(minValue, maxValue);
	bool actualResult = range.isInRange(value);

	bool result = (actualResult == expectedResult);
	return result;
}

int main() {
	assert(testIsInRange_MinOnly(0, 1, true));
	assert(testIsInRange_MinOnly(0, 0, true));
	assert(testIsInRange_MinOnly(0, -1, false));

	assert(testIsInRange_MaxOnly(0, -1, true));
	assert(testIsInRange_MaxOnly(0, 0, true));
	assert(testIsInRange_MaxOnly(0, 1, false));

	assert(testIsInRange_MinAndMax(3, 5, 2, false));
	assert(testIsInRange_MinAndMax(3, 5, 3, true));
	assert(testIsInRange_MinAndMax(3, 5, 5, true));
	assert(testIsInRange_MinAndMax(3, 5, 6, false));

	std::cout << "All tests passed!\n";
	return 0;
}
