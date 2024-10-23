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
        basic_language.cpp
        basic_language.h
        kafka_test.cpp
        kafka_test.h
        redis_test.cpp
        redis_test.h
        mysql_test.cpp
        mysql_test.h
        file_rw_test.cpp
        file_rw_test.h
)
add_library(mylib STATIC lib.cpp)
target_include_directories(mylib PUBLIC .)

# 查找并配置 spdlog
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} spdlog::spdlog)

target_link_libraries(${PROJECT_NAME} mylib )
