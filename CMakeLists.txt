cmake_minimum_required(VERSION 3.13)
project(T44RT)

set(CMAKE_C_STANDARD 90)

macro(ASSERT test comment)
    if (NOT ${test})
        message("Assertion failed: ${comment}")
    endif (NOT ${test})
endmacro(ASSERT)

if (CMAKE_BUILD_TYPE MATCHES "Release")
    add_compile_options("-O2")
endif ()

#find_package(GLEW REQUIRED)
#ASSERT(GLEW_FOUND "can't find glew")
#if (GLEW_FOUND)
#    include_directories(${GLEW_INCLUDE_DIRS})
#    link_libraries(${GLEW_LIBRARIES})
#endif ()

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)
ASSERT(GLUT_FOUND "can't find glut")
ASSERT(OPENGL_FOUND "can't find OPENGL")

if (GLUT_FOUND AND OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
    link_libraries(${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
endif ()


add_compile_options("-Wno-deprecated-declarations")
add_compile_options("--std=c++11")

add_executable(T44RT Ray_tracing_main.cpp objects/point_source.h objects/materials.cpp)
