
set(R3_VALIDATION_UTILS_EXPORT_ALL_SYMBOLS ${CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS})
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

set(R3_VALIDATION_UTILS_SOURCES
	r3-validation-IntRange.cpp
)

add_library(r3-ValidationUtils-lib STATIC
	${R3_VALIDATION_UTILS_SOURCES}
)
target_include_directories(r3-ValidationUtils-lib PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_library(r3-ValidationUtils-shared SHARED
	${R3_VALIDATION_UTILS_SOURCES}
)
target_include_directories(r3-ValidationUtils-shared PUBLIC "${PROJECT_SOURCE_DIR}/include")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ${R3_VALIDATION_UTILS_EXPORT_ALL_SYMBOLS})
