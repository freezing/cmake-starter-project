if (CMAKE_STARTER_PROJECT_INCLUDE_GOOGLETEST)
    add_subdirectory(googletest)
endif()

if (CMAKE_STARTER_PROJECT_INCLUDE_GOOGLEBENCHMARK)
    add_subdirectory(benchmark)
endif()
