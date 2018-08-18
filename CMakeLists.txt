cmake_minimum_required(VERSION 3.7)
project(cmake_starter_project)

enable_testing()

option(DUMMYLIB_BUILD_STATIC "Build static dummy library." ON)
option(DUMMYLIB_BUILD_TESTS "Build dummy library unit tests." ON)
option(DUMMYLIB_BUILD_BENCHMARKS "Build dummy library benchmarks." ON)
option(CMAKE_STARTER_PROJECT_INCLUDE_GOOGLETEST "Include the vendored thirdparty googletest library." ON)
option(CMAKE_STARTER_PROJECT_INCLUDE_GOOGLEBENCHMARK "Include the vendored thirdparty google benchmark library." OFF)
#option(CI_CONFIG "Configure for CI." OFF)

# Disable benchmark.
option(BENCHMARK_ENABLE_TESTING "If you want to run the tests for benchmark library, set to ON." OFF)
# Different versions of CMake require set.
set(BENCHMARK_ENABLE_TESTING OFF)

if (DUMMYLIB_BUILD_BENCHMARKS)
    # It's important to run benchmarks in the release mode.
    set(CMAKE_BUILD_TYPE Release)
    set(CMAKE_STARTER_PROJECT_INCLUDE_GOOGLEBENCHMARK ON)
endif()

add_subdirectory(lib)
add_subdirectory(third_party)
