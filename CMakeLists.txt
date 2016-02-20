PROJECT(marching_square)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

FIND_PACKAGE(VISP REQUIRED)
IF(VISP_FOUND)
  INCLUDE(${VISP_USE_FILE})
ENDIF(VISP_FOUND)

SET(SRC 
    main.cpp
    MarchingCube.cpp
    MarchingSquare.cpp
    Cube.cpp
    )

SET(HDR
    MarchingCube.h
    MarchingSquare.h
    Cube.h
    )

ADD_EXECUTABLE(marching_square ${SRC} ${HDR})
