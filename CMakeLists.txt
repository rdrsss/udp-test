cmake_minimum_required(VERSION 3.0.0)
project(udp-test)

# Setup build dir
set(BUILD_DIR build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})

# Compiler flags
set(CMAKE_CXX_FLAGS "--std=c++11 -g -Wall")

# headers
include_directories(
	src
	vendor/googletest/googletest/include
	)

# sources
file(
	GLOB_RECURSE
	test_sources
	src/*.cpp)

add_subdirectory(
	vendor/googletest
	${BUILD_DIR}
	)


add_executable(
	tests
	${test_sources}
	)

target_link_libraries(
	tests
	gtest
	)

