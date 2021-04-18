
#include <string>
#include <vector>

namespace r3 {

	namespace StringUtils {

		template <typename T> std::vector<std::basic_string<T>> split(const std::basic_string<T>& sourceString, T splitChar) {
			std::vector<std::basic_string<T>> result;

			size_t currPos = 0;
			bool doneFlag = false;
			while (!doneFlag) {
				size_t splitCharPos = sourceString.find(splitChar, currPos);
				result.push_back(sourceString.substr(currPos, splitCharPos));

				doneFlag = (splitCharPos == std::string::npos);
				if (!doneFlag) {
					currPos = splitCharPos + 1;
				}
			}

			return result;
		}

	}

}
