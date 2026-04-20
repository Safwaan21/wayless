cmake_minimum_required(VERSION 4.1.0)
project(wayless)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML COMPONENTS Graphics CONFIG REQUIRED)

add_executable(wayless src/simulator.cpp)

target_include_directories(wayless PRIVATE include)
target_compile_features(wayless PRIVATE cxx_std_17)
target_link_libraries(wayless PRIVATE SFML::Graphics SFML::Window SFML::System)