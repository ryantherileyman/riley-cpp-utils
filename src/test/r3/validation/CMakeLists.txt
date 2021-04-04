
add_executable(
	IntRangeTests
	IntRangeTests-main.cpp
)
target_link_libraries(IntRangeTests PRIVATE r3-ValidationUtils-lib)
target_include_directories(IntRangeTests PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_test(NAME IntRange COMMAND IntRangeTests)
