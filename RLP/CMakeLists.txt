cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)

set(EXECUTABLE rlp_test)

#link_libraries(boost_archive)
link_libraries(boost_serialization)

add_executable(${EXECUTABLE} ${DIR_SRCS})
