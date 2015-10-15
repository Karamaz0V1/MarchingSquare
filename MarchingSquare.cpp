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
#define COL 10
#define ROW 10
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
    for (int i = 0; i < ROW - 1; i++) {
        vector<int>::iterator it2pm = itpm->begin();
        for (int j = 0; j < COL - 1; j++) {
            unsigned char binaryVal = 0;
            binaryVal = _field[i][j];
            binaryVal <<= 1;
            binaryVal |= _field[i][j+1];
            binaryVal <<= 1;
            binaryVal |= _field[i+1][j+1];
            binaryVal <<= 1;
            binaryVal |= _field[i+1][j];
            *it2pm = binaryVal;
            it2pm++;
        }
        itpm++;
    }
}
