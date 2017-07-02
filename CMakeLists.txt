cmake_minimum_required(VERSION 3.0)
#project(apue)
#
##set(SOURCE_FILES main.c)
#set(CMAKE_VERBOSE_MAKEFILE ON)
##set(SOURCE_DIR ./)
#
#include_directories(./include)
##add_executable(apue ${SOURCE_FILES})
##add_executable(hostname)
#message("hi\n")
##message(${make_test_SOURCE_DIR})
#message(${PROJECT_BINARY_DIR})
##add_custom_command(make .)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
#
#add_custom_target(apue COMMAND make -C ${mytest_SOURCE_DIR}
#        CLION_EXE_DIR=${PROJECT_BINARY_DIR})
project(mytest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_custom_target(mytest COMMAND make -C ${mytest_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})