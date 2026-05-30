cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME stats_demo)
project(${PROJECT_NAME} CXX)

#Default to Release build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

#C++17 is mandatory
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#downloading and setting up Eigen
# include(FetchContent)

# FetchContent_Declare(
#   Eigen3
#   GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
#   GIT_TAG master
# )

# FetchContent_MakeAvailable(Eigen3)

# If Eigen is already installed on the system, you can use find_package
find_package(Eigen3 REQUIRED NO_MODULE)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/stats_demo.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)

# defining an output folder
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "bin"
)