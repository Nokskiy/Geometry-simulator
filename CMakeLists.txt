cmake_minimum_required(VERSION 3.10)

project(Simulator)

set(CXX_STANDARD 17)
if(MSVC)
    add_compile_options(/std:c++17)  # Для MSVC
else()
    add_compile_options(-std=c++17)  # Для GCC/Clang
endif()

add_subdirectory(raylib)
add_subdirectory(nlohmann/json)

add_executable(main src/main.cpp)

include_directories(nlohmann/json/include)

file(COPY assets/ DESTINATION ${CMAKE_BINARY_DIR}/assets)

target_link_libraries(main PRIVATE raylib)