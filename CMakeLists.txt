PROJECT(marching_square)
PROJECT(marching_cube)

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

FIND_PACKAGE(VISP REQUIRED)
IF(VISP_FOUND)
  INCLUDE(${VISP_USE_FILE})
ENDIF(VISP_FOUND)

add_compile_options("$<$<CONFIG:DEBUG>:-Wall>")

SET(SRC 
    MarchingCube.cpp
    MarchingSquare.cpp
    Cube.cpp
    Filter.cpp
    )

SET(HDR
    MarchingCube.h
    MarchingSquare.h
    Cube.h
    Filter.h
    )

ADD_EXECUTABLE(marching_square main_ms.cpp ${SRC} ${HDR})
ADD_EXECUTABLE(marching_cube main_mc.cpp ${SRC} ${HDR})
