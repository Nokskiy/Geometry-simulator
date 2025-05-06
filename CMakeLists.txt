cmake_minimum_required(VERSION 3.10)

project(Simulator)

set(CXX_STANDARD 17)
if(MSVC)
    add_compile_options(/std:c++17)
else()
    add_compile_options(-std=c++17)
endif()

add_subdirectory(raylib)
add_subdirectory(nlohmann/json)

add_executable(main src/main.cpp)

include_directories(nlohmann/json/include)

target_link_libraries(main PRIVATE raylib)