cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(
	"StatiCLib"
	VERSION 1.0.0
	DESCRIPTION "Template of static library cmake config"
	LANGUAGES C
)

set(CMAKE_C_STANDARD 17)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c")

# create static library
add_library(${PROJECT_NAME} STATIC ${SOURCES})

