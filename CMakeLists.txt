cmake_minimum_required(VERSION 3.0)
project(apue)
#
#set(SOURCE_FILES main.c)
#set(CMAKE_VERBOSE_MAKEFILE ON)
#set(SOURCE_DIR ./)
# find iso lib folder
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/include -lc  -std=C11")

include_directories(./include)
##add_executable(apue ${SOURCE_FILES})
##add_executable(hostname)
#message("hi\n")
##message(${make_test_SOURCE_DIR})
#message(${PROJECT_BINARY_DIR})
# add_custom_command(make .)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
#
#add_custom_target(apue COMMAND make -C ${mytest_SOURCE_DIR}
#        CLION_EXE_DIR=${PROJECT_BINARY_DIR})
# 编译lib
add_subdirectory(lib)

add_executable(main main.c)

add_executable(hostname sys/hostname.c)

add_executable(lseek fileIO/lseek.c)

add_executable(daemonize daemon/main.c daemon/already_running.c daemon/daemonize.c daemon/reread.c daemon/set_close_exec.c)
target_link_libraries(daemonize apue)

add_executable(non-block-io advanceIO/non_block.c)
target_link_libraries(non-block-io apue)

add_executable(dead-flock-test advanceIO/dead_flock_test.c)
target_link_libraries(dead-flock-test apue)

