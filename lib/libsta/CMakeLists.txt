# version minima requerida por este proyecto de cmake
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# detalles del proyecto
project(
	"StatiCLib"
	VERSION 1.0.0
	DESCRIPTION "Template of static library cmake config"
	LANGUAGES C
)

set(CMAKE_C_STANDARD 17)

# include directory where to find headers
include_directories(include)

# add sources
file(GLOB_RECURSE SOURCES "src/*.c") # agrega en la variable global SOURCES todos los archivos .c

# add flags
# set(CMAKE_C_FLAGS flags)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
