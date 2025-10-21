# CMake Version
cmake_minimum_required(VERSION 3.30)

# Output
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# Project
project(KCD LANGUAGES CXX)

# C++ Version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Exe
add_executable(app app.cpp)

# C++ Version
target_compile_features(app
    PRIVATE
        cxx_std_20
)
