cmake_minimum_required(VERSION 3.0)

set(This ExampleTests)

set(Sources
    ExampleTests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    mycode
)


add_test(
    NAME ${This}
    COMMAND ${This}
)

