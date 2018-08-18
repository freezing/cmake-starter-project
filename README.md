# CMake starter project

# How to add dependency

```
git remote add googletest https://github.com/google/googletest
git subtree add --prefix=third_party/googletest googletest master --squash
```

Add to `third_party/CMakeLists.txt`:

```
if (CMAKE_STARTER_PROJECT_INCLUDE_GOOGLETEST)
    add_subdirectory(googletest)
endif()
```

Add this flag in the root `CMakeLists.txt`:

```
option(CMAKE_STARTER_PROJECT_INCLUDE_GOOGLETEST "Include the vendored thirdparty googletest library." ON)
```