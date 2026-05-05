cmake_minimum_required(VERSION 3.16)
project(ExpenseStats VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directory for headers
include_directories(include)

# Main executable
add_executable(expense_stats
    src/main.cpp
    src/stats_calculator.cpp
)

# Compiler options
target_compile_options(expense_stats PRIVATE
    $<$<CONFIG:Release>:-O2>
    $<$<CONFIG:Debug>:-g>
)

# Unit test executable (always built, simple self-test)
add_executable(run_tests
    src/stats_calculator.cpp
    tests/test_stats.cpp
)

# Optional: create a custom target for cleaning
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_BINARY_DIR}/*
    COMMENT "Clean all build files"
)