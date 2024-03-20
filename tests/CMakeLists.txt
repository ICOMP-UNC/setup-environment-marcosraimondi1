cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

# get files to test
file(GLOB SRC_FILES 
	${CMAKE_CURRENT_SOURCE_DIR}/../src/prod.c
	${CMAKE_CURRENT_SOURCE_DIR}/../src/div.c
)

# collect tests
file(GLOB TESTS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/unit/*.c)

# link with unity header
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity/src)

# test for Coverage
if (RUN_COVERAGE)
	message("Coverage enabled")

	# check if necessary programs are installed
	find_program(LCOV_PATH lcov)
	if (NOT LCOV_PATH)
		message(FATAL_ERROR "lcov not found! Aborting...")
	endif()
		
	find_program(GCOV_PATH gcov)
	if (NOT GCOV_PATH)
		message(FATAL_ERROR "gcov not found! Aborting...")
	endif()

	# set coverage flags
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fprofile-arcs -ftest-coverage --coverage")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov --coverage")
endif()

# create test executable
add_executable(test_${PROJECT_NAME} ${TESTS_FILES} ${SRC_FILES})

# link with unity
target_link_libraries(test_${PROJECT_NAME} unity)

# add test
add_test(NAME test_${PROJECT_NAME} COMMAND test_${PROJECT_NAME})

