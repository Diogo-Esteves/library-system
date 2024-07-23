cmake_minimum_required(VERSION 3.10)
project(LibrarySystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(include lib/tinyxml2)
include_directories(include headers)


add_executable(LibrarySystem
    src/main.cpp
    src/Library.cpp
    src/Shelf.cpp
    src/Book.cpp
    src/Author.cpp
    lib/tinyxml2/tinyxml2.cpp
)