cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(
	"DynamiCLib"
	VERSION 1.0.0
	DESCRIPTION "Template of dynamic library cmake config"
	LANGUAGES C
)

set(CMAKE_C_STANDARD 17)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c")


# instead of executable create a shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})

