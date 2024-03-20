# minimum required cmake version for this project
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# project details
project(
	"FirstProjectInCmake"
	VERSION 1.1.0
	DESCRIPTION "CMake C Project Template for Operating Systems II"
	LANGUAGES C
)

# enable testing
include(CTest)

set(CMAKE_C_STANDARD 17)

# include directory where to find headers
include_directories(include)

# module to fetch a repository
include(FetchContent)

set(UNITY_GIT_URL "https://github.com/ThrowTheSwitch/Unity.git")

# enable debug
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(
	Unity
	GIT_REPOSITORY ${UNITY_GIT_URL}
	SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity
	UPDATE_COMMAND "" # disable update command
)

# wait for repo ready
FetchContent_MakeAvailable(Unity)

# add sources
file(GLOB_RECURSE SOURCES "src/*.c") # adds into global variable SOURCES .c files

# create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# add libraries, finds other CMakeLists.txt
add_subdirectory(lib/libdyn)
add_subdirectory(lib/libsta)

target_include_directories(${PROJECT_NAME} PUBLIC lib/libdyn/include)
target_include_directories(${PROJECT_NAME} PUBLIC lib/libsta/include)

# link libraries, specify Project Name defined in CMakeLists.txt of each library
target_link_libraries(${PROJECT_NAME} StatiCLib DynamiCLib)

# add tests
if (RUN_TESTS EQUAL 1 OR RUN_COVERAGE EQUAL 1)
	add_subdirectory(tests)
endif()

