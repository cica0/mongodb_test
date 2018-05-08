cmake_minimum_required(VERSION 2.8)
PROJECT(SE)

ADD_DEFINITIONS(-O3 -Wall -g -std=c++0x)
set (SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set (THIRD_DIR /home/chang/work/common/base/third-64)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include
                    ${PROJECT_SOURCE_DIR}/deps
                    ${THIRD_DIR}/mongo-client_2-5-4-0_PD_BL/include)

#ADD_LIBRARY(
#)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib
    ${THIRD_DIR}/mongo-client_2-5-4-0_PD_BL/lib
    ${THIRD_DIR}/boost/lib
)

set (MY_SOURCES 
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/split_word.cpp
    ${SRC_DIR}/index.cpp
    ${SRC_DIR}/mongodb.cpp)

add_executable(SE ${MY_SOURCES})


target_link_libraries(SE
    libmongoclient.a
    pthread
    libboost_system.a
    boost_thread 
    boost_filesystem
    boost_program_options
)
#add_executable(${PROJECT} main.cpp)
#
#CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
#
#AUX_SOURCE_DIRECTORY(src DIR_SRCS)
#
#
##if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
##    set (CMAKE_INSTALL_PREFIX "/usr/local/cppjieba" CACHE PATH "default install path" FORCE )
##endif()
#
#
## cmake .. -DENC=GBK
## IF (DEFINED ENC)
##     ADD_DEFINITIONS(-DCPPJIEBA_${ENC})
## ENDIF()
#
##ADD_SUBDIRECTORY(deps)
##ADD_SUBDIRECTORY(test)
##
##ENABLE_TESTING()
##ADD_TEST(NAME ./test/test.run COMMAND ./test/test.run)
##ADD_TEST(NAME ./load_test COMMAND ./load_test)
##ADD_TEST(NAME ./demo COMMAND ./demo)
