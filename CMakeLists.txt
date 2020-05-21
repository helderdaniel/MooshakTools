cmake_minimum_required(VERSION 3.2)

#Project name
#project(MooshakTools)

set(SRC "src")
set(EXAMPLES "examples")
set(TEST "test")
set(BIN "bin")
set(DOC "doc")

#CXX Setup
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_C_COMPILER /usr/bin/gcc-7)
#set(CMAKE_C_COMPILER /usr/bin/clang-7)
#set(CMAKE_CXX_COMPILER:FILEPATH /usr/bin/g++-9)
#set(CMAKE_CXX_COMPILER /usr/bin/clang++-7)  #clang++-8 NOT available in ubuntu 15 apr 2019

#set(GCC_EXTRA_COMPILE_FLAGS "-Ofast -fopenmp")
set(GCC_EXTRA_COMPILE_FLAGS "-O0 -g -fopenmp")
#set(GCC_EXTRA_LINK_FLAGS    "")

#reset existing
set(CMAKE_CXX_FLAGS  ${GCC_EXTRA_COMPILE_FLAGS})
set(CMAKE_EXE_LINKER_FLAGS  ${GCC_EXTRA_LINK_FLAGS})

#add to existing
#set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_EXTRA_COMPILE_FLAGS}")
#set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_EXTRA_LINK_FLAGS}")

#Project name
#Must be after set compiler paths
project(MooshakTools)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../${BIN})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../${BIN})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../${BIN})

#include folders
set(INCLUDE "/home/hdaniel/Dropbox/01-libs/cpp") # "/usr/local/cuda-9.0/include")
include_directories(. ${INCLUDE} )

#catch2 lib
set(CATCH2LIB "${BIN}/tests-main.o")
set(CATCH2LIBSRC "${INCLUDE}/catch2/tests-main.cpp")

#Compile catch2 lib
add_library(Catch2 ${CATCH2LIBSRC})
#target_link_libraries(Catch2)

#targets
set(TARGET "main")
add_executable(${TARGET} ${EXAMPLES}/${TARGET}.cpp)
#target_link_libraries(${TARGET})


#Unit tests
set(UNITTEST0 "testEval")
add_executable(${UNITTEST0} ${TEST}/${UNITTEST0}.cpp)
target_link_libraries(${UNITTEST0} Catch2)

set(UNITTEST1 "testFile")
add_executable(${UNITTEST1} ${TEST}/${UNITTEST1}.cpp)
target_link_libraries(${UNITTEST1} Catch2)

add_test(NAME t0 COMMAND UNITTEST0)
add_test(NAME t1 COMMAND UNITTEST1)

#Doxygen
#https://vicrucann.github.io/tutorials/quick-cmake-doxygen/
#https://p5r.uk/blog/2014/cmake-doxygen.html

#Documentation build as an option. Set it to ON by default
option(BUILD_DOC "Build HTML API documentation with Doxygen" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${SRC}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    #configure
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    #option ALL allows to build the docs together with the application
    add_custom_target(doc ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )


else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

#add_executable(doc ${EXAMPLES}/main.cpp)
