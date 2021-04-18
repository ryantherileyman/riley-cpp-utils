
set(R3_STRING_UTILS_EXPORT_ALL_SYMBOLS ${CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS})
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

set(R3_STRING_UTILS_SOURCES
	r3-StringUtils.cpp
)

add_library(r3-StringUtils-lib STATIC
	${R3_STRING_UTILS_SOURCES}
)
target_include_directories(r3-StringUtils-lib PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_library(r3-StringUtils-shared SHARED
	${R3_STRING_UTILS_SOURCES}
)
target_include_directories(r3-StringUtils-shared PUBLIC "${PROJECT_SOURCE_DIR}/include")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ${R3_STRING_UTILS_EXPORT_ALL_SYMBOLS})
