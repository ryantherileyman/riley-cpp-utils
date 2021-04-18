
cmake_minimum_required(VERSION 3.19)

project(RileyCppUtils VERSION 1.2)

option(RILEY_CPP_UTILS_WITH_TESTS "Build and run RileyCppUtils test executables" ON)

add_subdirectory(src/main/r3/string)
add_subdirectory(src/main/r3/validation)

if (${RILEY_CPP_UTILS_WITH_TESTS})
	enable_testing()
	add_subdirectory(src/test/r3/string)
	add_subdirectory(src/test/r3/validation)
endif()
