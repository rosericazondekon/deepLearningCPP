cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME hello)
project(${PROJECT_NAME} CXX)

# Default to Release build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

#C++17 is mandatory
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/hello.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)

add_executable(functional ${PROJECT_SOURCE_DIR}/functional.cpp)
target_compile_options(functional PRIVATE -Wall -Wextra -pedantic)

#defining an output folder
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "bin"
)

set_target_properties(functional PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "bin"
)
