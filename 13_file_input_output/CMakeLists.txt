cmake_minimum_required(VERSION 3.5)
PROJECT(FILE_INPUT)
set(SRC_LIST file_io.cpp)
find_package(OpenCV 3.4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(file ${SRC_LIST})
target_link_libraries(file ${OpenCV_LIBS})
