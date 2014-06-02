cmake_minimum_required(VERSION 2.8)
project(RWmaker)
message(status "${CMAKE_CURRENT_SOURCE_DIR}")
include_directories(src include)
set(HEADER_FILES include/Test.hpp)
find_package(Boost 1.53)
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK) 
message(status "** Boost Include: ${Boost_INCLUDE_DIR}")
message(status "** Boost Libraries: ${Boost_LIBRARY_DIRS}")
message(status "** Boost Libraries: ${Boost_LIBRARIES}")

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

set(Boost_USE_STATIC_LIBS        OFF)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
set(BOOST_ALL_DYN_LINK           ON)   # force dynamic linking for all libraries


find_package(Armadillo REQUIRED)
INCLUDE_DIRECTORIES(${ARMADILLO_INCLUDE_DIRS})
LINK_DIRECTORIES(${ARMADILLO_LIBRARIES})


#include(FindROOT.cmake)
#set(INCLUDE_DIRECTORIES ${ROOT_INCLUDE_DIR})
#include_directories(${INCLUDE_DIRECTORIES})

#set(LINK_DIRECTORIES ${ROOT_LIBRARY_DIR})
#link_directories(${LINK_DIRECTORIES})

#INCLUDE_DIRECTORIES(${ROOT_INCLUDE_DIR})
#LINK_DIRECTORIES(${ROOT_LIBRARY_DIR})

add_executable(RWmaker src/Main.cpp ${HEADER_FILES})
target_link_libraries(RWmaker -lm ${Boost_LIBRARIES})
target_link_libraries(RWmaker -lm ${ARMADILLO_LIBRARIES})
#target_link_libraries(RWmaker -lm ${ROOT_LIBRARIES})

find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM
        )
endif(DOXYGEN_FOUND)

if (CMAKE_COMPILER_IS_GNUCXX)
    message(status "Setting GCC flags")

    # Remove the -g flag when not debugging
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall -Wextra -W -pedantic -std=c++0x -O3 -larmadillo -llapack -lblas")
else()
    message(status "Setting MSVC flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc-")
endif()
install(TARGETS RWmaker DESTINATION ${CMAKE_BINARY_DIR}/lib)
