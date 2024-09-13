cmake_minimum_required(VERSION 3.27)
project(cplustest)

# 显示 VCPKG_ROOT 的值
message(STATUS "VCPKG_ROOT: /Users/wanghao/Documents/tools/vcpkg")
if(NOT EXISTS "/Users/wanghao/Documents/tools/vcpkg/scripts/buildsystems/vcpkg.cmake")
    message(FATAL_ERROR "VCPKG_ROOT is not valid, please define it correctly.")
endif()

# 包含 vcpkg 的 CMake 配置脚本
include(/Users/wanghao/Documents/tools/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp
        utils.cpp
        utils.h
)
add_library(mylib STATIC lib.cpp)
target_include_directories(mylib PUBLIC .)

# 查找并配置 spdlog
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} spdlog::spdlog)