add_executable(en
    main.cc

    en.h
    en.cc
)
target_link_libraries(en PUBLIC snowball_runtime)