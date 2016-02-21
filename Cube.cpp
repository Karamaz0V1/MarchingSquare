/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#include "Cube.h"
#include <cassert>

using namespace std;

Cube::Cube(const std::bitset<8> & init) : _vertices(init) {
}

Cube::Cube(const Cube & cube) : _vertices(cube._vertices) {
}

Cube::~Cube() {}

bool Cube::vertex(int index) const {
    assert(index < 8);
    return _vertices[index];
}

void Cube::setVertex(int index) {
    _vertices[index] = true;
}

int Cube::getId() const {
    return (int) _vertices.to_ulong();
}

bool Cube::equal(const Cube & cube) const {
    return _vertices == cube._vertices;
}
