# version minima requerida por este proyecto de cmake
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# detalles del proyecto
project(
	"FirstProjectInCmake"
	VERSION 1.0.0
	DESCRIPTION "CMake C Project Template for Operating Systems II"
	LANGUAGES C
)

set(CMAKE_C_STANDARD 17)

# include directory where to find headers
include_directories(include)

# add sources
file(GLOB_RECURSE SOURCES "src/*.c") # agrega en la variable global SOURCES todos los archivos .c

# add flags
# set(CMAKE_C_FLAGS flags)

# crear el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})
