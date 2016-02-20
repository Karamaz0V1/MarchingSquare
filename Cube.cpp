/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Cube.h"

Cube::Cube() : _vertices() {
}

const bool & Cube::vertex(int index) const {
    return _vertices[0];
}

bool & Cube::vertex(int index) {
    return _vertices[0];
}
