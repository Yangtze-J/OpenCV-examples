cmake_minimum_required(VERSION 3.5)
PROJECT(MASK)
set(SRC_LIST mat_mask_operations.cpp)
find_package(OpenCV 3.4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(mask ${SRC_LIST})
target_link_libraries(mask ${OpenCV_LIBS})
