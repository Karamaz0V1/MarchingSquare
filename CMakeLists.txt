PROJECT(marching_square)
PROJECT(marching_cube)

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

FIND_PACKAGE(VISP REQUIRED)
IF(VISP_FOUND)
  INCLUDE(${VISP_USE_FILE})
ENDIF(VISP_FOUND)

add_compile_options("$<$<CONFIG:DEBUG>:-Wall>")

SET(SRC_MC 
    MarchingCube.cpp
    GridCube.cpp
    Cube.cpp
    Filter.cpp
    )

SET(HDR_MC
    MarchingCube.h
    GridCube.h
    Cube.h
    Filter.h
    )

SET(SRC_MS 
    MarchingSquare.cpp
    )

SET(HDR_MS
    MarchingSquare.h
    )


ADD_EXECUTABLE(marching_square main_ms.cpp ${SRC_MS} ${HDR_MS})
ADD_EXECUTABLE(marching_cube main_mc.cpp ${SRC_MC} ${HDR_MC})
target_compile_features(marching_cube PRIVATE cxx_range_for)
