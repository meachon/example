cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)

set(EXECUTABLE testcase_esdsa_sign)

link_libraries(crypto)

add_executable(${EXECUTABLE} ${DIR_SRCS})
