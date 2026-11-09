cmake_minimum_required(VERSION 3.15)
project(PolyInfusion LANGUAGES CXX)

add_executable(PolyInfusion
    src/main.cpp
    src/console/Console.cpp
)
target_include_directories(PolyInfusion PRIVATE include)
target_compile_features(PolyInfusion PRIVATE cxx_std_17)
set_target_properties(PolyInfusion PROPERTIES CXX_EXTENSIONS OFF)
if(MSVC)
    target_compile_options(PolyInfusion PRIVATE /W4 /utf-8)
else()
    target_compile_options(PolyInfusion PRIVATE -Wall -Wextra -Wpedantic)
endif()
