cmake_minimum_required(VERSION 3.0)
project(pubg-lagswitch)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(pubg-lagswitch ${SOURCES})
