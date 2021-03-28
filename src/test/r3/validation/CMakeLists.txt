
add_executable(
	IntRangeTests
	IntRangeTests-main.cpp
)
target_link_libraries(IntRangeTests PRIVATE r3-ValidationUtils)
target_include_directories(IntRangeTests PUBLIC "${PROJECT_SOURCE_DIR}/include")

if (${BUILD_SHARED_LIBS})
	add_custom_command(
		TARGET IntRangeTests POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy
			$<TARGET_FILE_DIR:r3-ValidationUtils>/r3-ValidationUtils.dll $<TARGET_FILE_DIR:IntRangeTests>
	)
endif()

add_test(NAME IntRange COMMAND IntRangeTests)
