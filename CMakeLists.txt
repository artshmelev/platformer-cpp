cmake_minimum_required(VERSION 2.8)
project(platformer-cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lsfml-graphics")

include_directories(include)
file(GLOB SRC_LIST "src/*.cpp")
file(COPY "resources" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${CMAKE_PROJECT_NAME} ${SRC_LIST})
add_custom_target(run "./${CMAKE_PROJECT_NAME}" WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} DEPENDS ${CMAKE_PROJECT_NAME})
