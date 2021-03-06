cmake_minimum_required(VERSION 3.2)

#CXX Setup
set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_C_COMPILER /usr/bin/gcc-7)
#set(CMAKE_C_COMPILER /usr/bin/clang-7)
set(CMAKE_CXX_COMPILER:FILEPATH /usr/bin/g++-9)
#set(CMAKE_CXX_COMPILER /usr/bin/clang++-9)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    set(CC_EXTRA_COMPILE_FLAGS "-O0 -g --coverage") # -O0 and --coverage are slower
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    set(CC_EXTRA_COMPILE_FLAGS "-Ofast")
endif()
#set(CC_EXTRA_COMPILE_FLAGS_RELEASE "-Ofast")
#set(CC_EXTRA_COMPILE_FLAGS_DEBUG "-O0 -g --coverage") # -O0 and --coverage are slower
#set(CC_EXTRA_LINK_FLAGS    "")

#reset existing
#set(CMAKE_CXX_FLAGS_DEBUG  ${CC_EXTRA_COMPILE_FLAGS_DEBUG})
#set(CMAKE_CXX_FLAGS_RELEASE  ${CC_EXTRA_COMPILE_FLAGS_RELEASE})
set(CMAKE_CXX_FLAGS  ${CC_EXTRA_COMPILE_FLAGS})
set(CMAKE_CXX_FLAGS  ${CC_EXTRA_COMPILE_FLAGS})
set(CMAKE_EXE_LINKER_FLAGS  ${CC_EXTRA_LINK_FLAGS})

#add to existing
#set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${CC_EXTRA_COMPILE_FLAGS}")
#set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${CC_EXTRA_LINK_FLAGS}")

#Project name
#Must be after set compiler paths
project(MooshakTools)

#Project folders
set(SRC "src")
set(APPS "apps")
set(TEST "test")
set(BIN "bin")
set(DOC "doc")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../${BIN})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../${BIN})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../${BIN})

#include folders
set(CPPLIB "/home/hdaniel/Dropbox/01-libs/cpp")
include_directories(. ${CPPLIB} )

#Intel thread building blocks (-lttb)
#apt install libtbb-dev (use par policies) ("/usr/lib/x86_64-linux-gnu/libtbb.so")
#set(TBBLIB "/usr/lib/x86_64-linux-gnu/libtbb.so")

#Catch2 lib
set(CATCH2LIB "${CPPLIB}/catch2/libCatch2.a")

#Targets
list(APPEND TARGETS evaluate submissions report)
foreach(TARGET IN LISTS TARGETS)
    add_executable(${TARGET} ${APPS}/${TARGET}.cpp)
endforeach()

#Unit tests
list(APPEND UNITTESTS testEval testSubmissionsInfo benchSubmissionsInfo testSubmission testAppSubmissions testAppEvaluate testAll)
foreach(UNITTEST IN LISTS UNITTESTS)
    add_executable(${UNITTEST} ${TEST}/${UNITTEST}.cpp)
    target_link_libraries(${UNITTEST} ${CATCH2LIB})
endforeach()

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


