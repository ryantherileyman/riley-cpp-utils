
add_executable(
	StringUtilsTests
	StringUtilsTests-main.cpp
)
target_link_libraries(StringUtilsTests PRIVATE r3-StringUtils-lib)
target_include_directories(StringUtilsTests PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_test(NAME StringUtils COMMAND StringUtilsTests)
