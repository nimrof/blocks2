cmake_minimum_required (VERSION 3.0)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

project (blocks2)
add_subdirectory(lib)
add_subdirectory(blocksLib)

#add_executable(Tutorial tutorial.cxx)
