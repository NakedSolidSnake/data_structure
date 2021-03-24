cmake_minimum_required(VERSION 3.7.0)

project(rasp_rover)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

# This one is important
SET(CMAKE_SYSTEM_NAME Linux)

# Specify the cross compiler
#SET(CMAKE_C_COMPILER   arm-linux-gnueabihf-gcc)
#SET(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

include(GNUInstallDirs)


function(add_test_unit BIN_NAME BIN SOURCE)
  add_executable(${BIN} ${SOURCE})
  set_target_properties(${BIN}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test_lib
    )
    add_test(NAME ${BIN_NAME} COMMAND ${BIN})
endfunction()

enable_testing()

add_library(data_structure SHARED "")
target_sources(data_structure 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/src/stack_array/stack_array.c

  )
target_include_directories(data_structure 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/include
  )


add_test_unit(stack_array stack_array_test tests/stack_array_test.c)
target_link_libraries(stack_array_test PUBLIC data_structure)