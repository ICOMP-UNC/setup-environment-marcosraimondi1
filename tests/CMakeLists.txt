# version minima requerida por este proyecto de cmake
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# include headears directory from project
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

# get files to test
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../src/prod.c)

# collect tests
file(GLOB TESTS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/unit/*.c)

# link with unity header
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity/src)

# create test executable
add_executable(test_${PROJECT_NAME} ${TESTS_FILES} ${SRC_FILES})

# link with unity
target_link_libraries(test_${PROJECT_NAME} unity)

# add test
add_test(NAME test_${PROJECT_NAME} COMMAND test_${PROJECT_NAME})
