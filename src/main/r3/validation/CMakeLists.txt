
add_library(
	r3-ValidationUtils
	r3-validation-IntRange.cpp
)

target_include_directories(r3-ValidationUtils PUBLIC "${PROJECT_SOURCE_DIR}/include")
