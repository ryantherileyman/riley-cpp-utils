
#include <r3/string/r3-string-utils.hpp>

namespace r3 {

	namespace StringUtils {

		template <typename T> std::vector<std::basic_string<T>> split(const std::basic_string<T>& sourceString, T splitChar) {
			std::vector<std::basic_string<T>> result;

			size_t currPos = 0;
			bool doneFlag = false;
			while (!doneFlag) {
				size_t splitCharPos = sourceString.find(splitChar, currPos);
				result.push_back(sourceString.substr(currPos, splitCharPos - currPos));

				doneFlag = (splitCharPos == std::string::npos);
				if (!doneFlag) {
					currPos = splitCharPos + 1;
				}
			}

			return result;
		}

		template std::vector<std::string> split<char>(const std::string& sourceString, char splitChar);
		template std::vector<std::wstring> split<wchar_t>(const std::wstring& sourceString, wchar_t splitChar);

		template <typename T> std::basic_string<T> join(const std::vector<std::basic_string<T>>& sourceStringList, T joinChar) {
			std::basic_string<T> result;

			for (auto stringIterator = sourceStringList.begin(); stringIterator != sourceStringList.end(); stringIterator++) {
				result.append(*stringIterator);
				if (std::next(stringIterator) != sourceStringList.end()) {
					result.push_back(joinChar);
				}
			}

			return result;
		}

		template std::string join<char>(const std::vector<std::string>& sourceStringList, char joinChar);
		template std::wstring join<wchar_t>(const std::vector<std::wstring>& sourceStringList, wchar_t joinChar);

		template <typename T> bool charAtPosIsInCharSet(const std::basic_string<T>& sourceString, size_t startPos, const T* searchCharSet) {
			T sourceChar = sourceString.at(startPos);

			bool result = false;
			for (const T* currSearchPtr = searchCharSet; *currSearchPtr != '\0'; currSearchPtr++) {
				if (sourceChar == *currSearchPtr) {
					result = true;
					break;
				}
			}

			return result;
		}

		template bool charAtPosIsInCharSet<char>(const std::string& sourceString, size_t startPos, const char* searchCharSet);
		template bool charAtPosIsInCharSet<wchar_t>(const std::wstring& sourceString, size_t startPos, const wchar_t* searchCharSet);

		template <typename T> size_t findNextPosFromCharSet(const std::basic_string<T>& sourceString, size_t startPos, const T* searchCharSet) {
			size_t result = startPos;

			bool doneFlag = false;
			while (!doneFlag) {
				if (result >= sourceString.size()) {
					result = std::string::npos;
					break;
				}

				doneFlag = charAtPosIsInCharSet(sourceString, result, searchCharSet);

				if (!doneFlag) {
					result++;
				}
			}

			return result;
		}

		template size_t findNextPosFromCharSet<char>(const std::string& sourceString, size_t startPos, const char* searchCharSet);
		template size_t findNextPosFromCharSet<wchar_t>(const std::wstring& sourceString, size_t startPos, const wchar_t* searchCharSet);

	}

}
