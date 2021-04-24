
#include <string>
#include <vector>

namespace r3 {

	namespace StringUtils {

		template <typename T> std::vector<std::basic_string<T>> split(const std::basic_string<T>& sourceString, T splitChar);

		template <typename T> std::basic_string<T> join(const std::vector<std::basic_string<T>>& sourceStringList, T joinChar);

		template <typename T> bool charAtPosIsInCharSet(const std::basic_string<T>& sourceString, size_t startPos, const T* searchCharSet);

		template <typename T> size_t findNextPosInCharSet(const std::basic_string<T>& sourceString, size_t startPos, const T* searchCharSet);

		template <typename T> size_t findNextPosNotInCharSet(const std::basic_string<T>& sourceString, size_t startPos, const T* excludeCharSet);

	}

}
