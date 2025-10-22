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
set(CMAKE_CXX_EXTENSIONS ON)

# Build
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

# configuration
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/configuration/directories.h.in ${CMAKE_CURRENT_SOURCE_DIR}/configuration/directories.h)

# Demos
add_subdirectory(demo_001)
add_subdirectory(demo_002)

# Resources
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR}/${OUTPUTCONFIG})
endforeach()
