set(DUMMYLIB_SRC
        include/dummy.h
        src/dummy.cpp)

set(DUMMYLIB_TEST_SRC
        test/dummy_test.cpp
        test/test.cpp)

set(DUMMYLIB_BENCHMARK_SRC
        benchmark/dummy_benchmark.cpp)

if (DUMMYLIB_BUILD_STATIC)
    add_library(dummy_static STATIC ${DUMMYLIB_SRC})
    set_property(TARGET dummy_static PROPERTY CXX_STANDARD 11)
    target_compile_definitions(dummy_static PUBLIC DUMMYLIB_STATIC)

    target_include_directories(dummy_static
            PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
            PUBLIC $<INSTALL_INTERFACE:include>
            PRIVATE src)

    if (DUMMYLIB_BUILD_TESTS)
        add_executable(dummylib_test ${DUMMYLIB_TEST_SRC})
        target_link_libraries(dummylib_test dummy_static gtest gmock)
        set_property(TARGET dummylib_test PROPERTY CXX_STANDARD 11)
        add_test(dummylib_test dummylib_test)
    endif()

    if (DUMMYLIB_BENCHMARK_SRC)
        # BFS Benchmark.
        add_executable(dummy_benchmark ${DUMMYLIB_BENCHMARK_SRC})
        target_link_libraries(dummy_benchmark dummy_static benchmark)
        set_property(TARGET dummy_benchmark PROPERTY CXX_STANDARD 11)
#        set_target_properties(dummy_benchmark PROPERTIES benchmark_format json benchmark_out benchmarks/bfs.json)
    endif()
endif()