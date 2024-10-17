cmake_minimum_required(VERSION 3.5.0)

project(discord-diplomacy VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(CURL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONC REQUIRED jansson)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")

add_executable(discord-diplomacy ${SOURCES})

target_include_directories(discord-diplomacy PRIVATE include)

target_include_directories(discord-diplomacy PRIVATE ${CURL_INCLUDE_DIRS} ${JSONC_INCLUDE_DIRS})

target_link_libraries(discord-diplomacy PRIVATE ${CURL_LIBRARIES} ${JSONC_LIBRARIES})
