/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#include "MarchingSquare.h"
#include <iostream>
#include <cstdlib>

MarchingSquare::MarchingSquare() {
    int c = 255;
    int l = 255;

    _field.reserve(c);
    for (int i = 0; i < _field.capacity(); i++)
        _field[i].reserve(l);
}

MarchingSquare::~MarchingSquare() {}

void MarchingSquare::randomize(int n) {
    for (int i = 0; i < n; i++)
        _field[rand()%_field.capacity()][rand()%_field[0].capacity()] = 1;
}

