cmake_minimum_required(VERSION 3.16)
project(base64 C)

set(CMAKE_C_STANDARD 11)

add_library(base64 base64.c base64.h main.c urlsafe.h  urlsafe.c)

add_executable(base64_exe main.c)
set(CMAKE_C_FLAGS "-Weverything -Wall -Werror=vla -Wno-vla -Wextra -Wshadow -Wconversion -Wno-long-long -pedantic -fsanitize=address -fno-omit-frame-pointer" CACHE STRING "C compiler flags" FORCE )
target_link_libraries (base64_exe LINK_PUBLIC base64)


# the compiler flags for compiling C sources
MESSAGE( STATUS "CMAKE_C_FLAGS: " ${CMAKE_C_FLAGS} )
