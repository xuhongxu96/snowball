add_library(snowball_runtime STATIC
    api.h
    api.cpp

    header.h

    utilities.cpp
)
target_include_directories(snowball_runtime PUBLIC .)