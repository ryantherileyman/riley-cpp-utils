
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
		(stringList.at(0).compare(singleLineString) == 0);
	return result;
}

bool testSplit_MultiLine() {
	std::wstring multiLineString(L"Three\nWhole\nLines!\n");

	std::vector<std::wstring> stringList = r3::StringUtils::split(multiLineString, L'\n');

	bool result =
		(stringList.size() == 4) &&
		(stringList.at(0).compare(L"Three") == 0) &&
		(stringList.at(1).compare(L"Whole") == 0) &&
		(stringList.at(2).compare(L"Lines!") == 0) &&
		(stringList.at(3).empty());
	return result;
}

bool testJoin_Empty() {
	std::vector<std::string> emptyStringList;

	std::string joinedString = r3::StringUtils::join(emptyStringList, ' ');

	bool result = joinedString.empty();
	return result;
}

bool testJoin_Single() {
	std::vector<std::string> singleStringList;
	singleStringList.push_back("Hello world");

	std::string joinedString = r3::StringUtils::join(singleStringList, ' ');

	bool result =
		(joinedString.compare("Hello world") == 0) &&
		(joinedString.size() == 11);
	return result;
}

bool testJoin_Multiple() {
	std::vector<std::wstring> multiStringList;
	multiStringList.push_back(L"Hello");
	multiStringList.push_back(L"World!");

	std::wstring joinedString = r3::StringUtils::join(multiStringList, L'\n');

	bool result =
		(joinedString.compare(L"Hello\nWorld!") == 0) &&
		(joinedString.size() == 12);
	return result;
}


int main() {
	assert(testSplit_Empty());
	assert(testSplit_SingleLine());
	assert(testSplit_MultiLine());

	assert(testJoin_Empty());
	assert(testJoin_Single());
	assert(testJoin_Multiple());

	std::cout << "All tests passed!\n";
	return 0;
}
