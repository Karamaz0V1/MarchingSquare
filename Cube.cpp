/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#include "Cube.h"
#include <iostream>
#include <cassert>

using namespace std;

Cube::Cube(const std::bitset<8> & init) : _vertices(init) {
}

Cube::~Cube() {}

bool Cube::vertex(int index) const {
    assert(index < 8);
    return _vertices[index];
}

int Cube::getId() const {
    return (int) _vertices.to_ulong();
}
