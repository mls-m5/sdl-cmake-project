


cmake_minimum_required (VERSION 3.1)

set (CMAKE_CXX_STANDARD 11) #Works since cmake 3.1

#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
set(CMAKE_BUILD_TYPE Debug)


include_directories ("${PROJECT_SOURCE_DIR}/include")
project (main)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_executable(main src/main.cpp)

target_link_libraries(main -lSDL2)



