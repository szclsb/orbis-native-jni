cmake_minimum_required(VERSION 3.17)
project(orbis_native)

set(CMAKE_CXX_STANDARD 20)

find_package(Java REQUIRED)
find_package(JNI REQUIRED)

if (NOT JNI_FOUND)
    message(FATAL_ERROR "JNI not found")
endif()

# generate jni header files command target
set(JAVAH orbis_generate_header)
set(CMAKE_STUB_DIR ${PROJECT_SOURCE_DIR}/stub)
set(JAVA_SOURCE_PROJECT ${PROJECT_SOURCE_DIR}/../zx-orbis/math)
set(JAVA_CLASSPATH ${JAVA_SOURCE_PROJECT}/src/main/java)
file(GLOB JAVA_SOURCE ${JAVA_CLASSPATH}/ch/szclsb/orbis/math/jni/*.java)

add_custom_target(${JAVAH}
        COMMAND javac -classpath ${JAVA_CLASSPATH} -h ${PROJECT_SOURCE_DIR}/header ${JAVA_SOURCE} -d ${CMAKE_STUB_DIR}
        )

# build shared library
include_directories(${JNI_INCLUDE_DIRS})
file(GLOB SOURCE_FILES source/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

#add_dependencies(${PROJECT_NAME} ${JAVAH})