cmake_minimum_required(VERSION 3.0)
#add_compile_options(-std=c++11)
set(CMAKE_CXX_STANDARD 11)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)

set(EXECUTABLE base58)


add_executable(${EXECUTABLE} ${DIR_SRCS})

