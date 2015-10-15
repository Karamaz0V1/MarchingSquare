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
#define COL 100
#define ROW 100
// TODO: user defined

using std::vector;
using std::cout;
using std::endl;

MarchingSquare::MarchingSquare() : _field(ROW, vector<int>(COL)) {
}

MarchingSquare::~MarchingSquare() {}

void MarchingSquare::randomize(int n) {
    // TODO: init seed
    for (int i = 0; i < n; i++)
        _field[rand()%_field.capacity()][rand()%_field[0].capacity()] = 1;
}

void MarchingSquare::dispMatrix() const {
    dispMatrix(_field);
}

void MarchingSquare::dispMatrix(const matrix & mat) const {
    for (matrix::const_iterator it = mat.begin(); it != mat.end(); it++) {
        for (vector<int>::const_iterator it2 = it->begin(); it2 != it->end(); it2++)
            cout << *it2 << " ";
        cout << endl;
    }
}

void MarchingSquare::march(matrix & patternMap) const {
    patternMap.resize(ROW - 1);
    for (matrix::iterator it = patternMap.begin(); it != patternMap.end(); it++)
        it->resize(COL - 1);

    matrix::iterator itpm = patternMap.begin();
    for (matrix::const_iterator it = _field.begin(); it != _field.end() - 1; it++) {
        vector<int>::iterator it2pm = itpm->begin();
        for (vector<int>::const_iterator it2 = it->begin(); it2 != it->end() - 1; it2++) {
            unsigned char binaryVal = 0;
            binaryVal = *it2;
            binaryVal << 1;
            binaryVal |= *it2 + 1;
            *it2pm = binaryVal;
            it2pm++;
        }
        itpm++;
    }
}
