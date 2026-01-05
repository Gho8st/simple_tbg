cmake_minimum_required(VERSION 3.22.1)

project(SimpleTBG CXX)

add_executable(SimpleTBG
    src/main.cpp
)

target_include_directories(SimpleTBG PRIVATE
    include
)