cmake_minimum_required(VERSION 3.23)
project(orbis)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
