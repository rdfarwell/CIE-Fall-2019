cmake_minimum_required(VERSION 3.14)
project(hw3)

set(CMAKE_CXX_STANDARD 11)

configure_file(input.txt input.txt COPYONLY)

add_executable(hw3 main.cpp AddressBook.cpp AddressBook.h Contact.cpp Contact.h Address.cpp Address.h)