cmake_minimum_required(VERSION 3.5)
PROJECT(smooth_images)
SET(SRC_LIST smooth.cpp)
find_package(OpenCV 3.4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
ADD_EXECUTABLE(smooth ${SRC_LIST})
target_link_libraries(smooth ${OpenCV_LIBS})

