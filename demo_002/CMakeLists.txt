
# Exe
add_executable(demo_002 demo_002.cpp)

target_include_directories(demo_002 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/configuration)

# C++
target_compile_features(demo_002 PUBLIC cxx_std_20)
