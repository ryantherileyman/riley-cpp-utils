
#include <assert.h>
#include <exception>
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

template <typename T> bool testCharAtPosIsInCharSet_InRange(const std::basic_string<T>& sourceString, size_t startPos, const T* searchCharList, bool expectedResult) {
	bool actualResult = r3::StringUtils::charAtPosIsInCharSet(sourceString, startPos, searchCharList);
	bool result = (actualResult == expectedResult);
	return result;
}

template <typename T> bool testCharAtPostIsInCharSet_OutOfRange(const std::basic_string<T>& sourceString, size_t startPos, const T* searchCharList) {
	try {
		r3::StringUtils::charAtPosIsInCharSet(sourceString, startPos, searchCharList);
		return false;
	}
	catch ( std::out_of_range exception ) {
		return true;
	}
}

template <typename T> bool testFindNextPosInCharSet(const std::basic_string<T>& sourceString, size_t startPos, const T* searchCharList, size_t expectedResult) {
	size_t actualResult = r3::StringUtils::findNextPosInCharSet(sourceString, startPos, searchCharList);
	bool result = (actualResult == expectedResult);
	return result;
}

template <typename T> bool testFindNextPosNotInCharSet(const std::basic_string<T>& sourceString, size_t startPos, const T* excludeCharSet, size_t expectedResult) {
	size_t actualResult = r3::StringUtils::findNextPosNotInCharSet(sourceString, startPos, excludeCharSet);
	bool result = (actualResult == expectedResult);
	return result;
}

int main() {
	assert(testSplit_Empty());
	assert(testSplit_SingleLine());
	assert(testSplit_MultiLine());

	assert(testJoin_Empty());
	assert(testJoin_Single());
	assert(testJoin_Multiple());

	assert(testCharAtPosIsInCharSet_InRange(std::string("Basic\tWhite Space"), 0, "\t ", false));
	assert(testCharAtPosIsInCharSet_InRange(std::wstring(L"Basic\tWhite Space"), 5, L"\t ", true));
	assert(testCharAtPosIsInCharSet_InRange(std::string("Basic\tWhite Space"), 11, "\t ", true));
	assert(testCharAtPosIsInCharSet_InRange(std::wstring(L"Basic\tWhite Space"), 16, L"\t ", false));

	assert(testCharAtPostIsInCharSet_OutOfRange(std::string("Basic\tWhite Space"), 17, "\t "));

	assert(testFindNextPosInCharSet(std::string("Basic\tWhite Space"), 0, "\t ", 5));
	assert(testFindNextPosInCharSet(std::wstring(L"Basic\tWhite Space"), 5, L"\t ", 5));
	assert(testFindNextPosInCharSet(std::string("Basic\tWhite Space"), 6, "\t ", 11));
	assert(testFindNextPosInCharSet(std::string("Basic\tWhite Space"), 12, "\t ", std::string::npos));
	assert(testFindNextPosInCharSet(std::string("Basic\tWhite Space"), 16, "\t ", std::string::npos));
	assert(testFindNextPosInCharSet(std::wstring(L"Basic\tWhite Space"), 17, L"\t ", std::string::npos));
	assert(testFindNextPosInCharSet(std::string("Basic\tWhite Space"), 50, "\t ", std::string::npos));

	assert(testFindNextPosNotInCharSet(std::string("Basic\tWhite Space"), 0, "\t ", 0));
	assert(testFindNextPosNotInCharSet(std::wstring(L"Basic\tWhite Space"), 5, L"\t ", 6));
	assert(testFindNextPosNotInCharSet(std::string("Basic\tWhite Space"), 11, "\t ", 12));
	assert(testFindNextPosNotInCharSet(std::string("Basic\tWhite Space"), 12, "\t ", 12));
	assert(testFindNextPosNotInCharSet(std::string("Basic\tWhite Space"), 17, "\t ", std::string::npos));
	assert(testFindNextPosNotInCharSet(std::wstring(L"Basic\tWhite Space"), 50, L"\t ", std::string::npos));

	std::cout << "All tests passed!\n";
	return 0;
}
