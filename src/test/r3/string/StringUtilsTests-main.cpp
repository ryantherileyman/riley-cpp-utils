
#include <assert.h>
#include <iostream>
#include <r3/string/r3-string-utils.hpp>

bool testSplit_Empty() {
	std::string emptyString;

	std::vector<std::string> stringList = r3::StringUtils::split(emptyString, '\n');

	bool result =
		(stringList.size() == 1) &&
		(stringList.at(0).empty());
	return result;
}

bool testSplit_SingleLine() {
	std::wstring singleLineString(L"This is all on one line.");

	std::vector<std::wstring> stringList = r3::StringUtils::split(singleLineString, L'\n');

	bool result =
		(stringList.size() == 1) &&
		(stringList.at(0).find(singleLineString) == 0);
	return result;
}

bool testSplit_MultiLine() {
	std::wstring multiLineString(L"Three\nWhole\nLines!\n");

	std::vector<std::wstring> stringList = r3::StringUtils::split(multiLineString, L'\n');

	bool result =
		(stringList.size() == 4) &&
		(stringList.at(0).find(L"Three") == 0) &&
		(stringList.at(1).find(L"Whole") == 0) &&
		(stringList.at(2).find(L"Lines!") == 0) &&
		(stringList.at(3).empty());
	return result;
}

int main() {
	assert(testSplit_Empty());
	assert(testSplit_SingleLine());
	assert(testSplit_MultiLine());

	std::cout << "All tests passed!\n";
	return 0;
}
