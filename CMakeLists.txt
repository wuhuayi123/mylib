cmake_minimum_required (VERSION 3.6.0)
project (mylib)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${PROJECT_SOURCE_DIR}/)

if(WIN32)
    add_definitions(-D_WIN32_WINNT=0x0601)
    set(CMAKE_VS_INCLUDE_INSTALL_TO_DEFAULT_BUILD TRUE)
endif()

#add_subdirectory(${PROJECT_SOURCE_DIR}/src/mylib)
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
