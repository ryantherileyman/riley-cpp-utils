
cmake_minimum_required(VERSION 3.19)

project(RileyCppUtils VERSION 1.0)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

add_subdirectory(src/main/r3/validation)

enable_testing()
add_subdirectory(src/test/r3/validation)
