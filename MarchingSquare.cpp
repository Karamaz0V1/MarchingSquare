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
#include <visp/vpImage.h>
#define COL 100
#define ROW 10
#define SCL 10
#define KCOLOR vpColor::green
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

void MarchingSquare::dispMatrix(const kmatrix & mat) const {
    for (kmatrix::const_iterator it = mat.begin(); it != mat.end(); it++) {
        for (vector<int>::const_iterator it2 = it->begin(); it2 != it->end(); it2++)
            cout << *it2 << " ";
        cout << endl;
    }
}

void MarchingSquare::march(kmatrix & patternMap) const {
    patternMap.resize(ROW - 1);
    for (kmatrix::iterator it = patternMap.begin(); it != patternMap.end(); it++)
        it->resize(COL - 1);

    kmatrix::iterator itpm = patternMap.begin();
    for (int i = 0; i < ROW - 1; i++) {
        vector<int>::iterator it2pm = itpm->begin();
        for (int j = 0; j < COL - 1; j++) {
            unsigned char binaryVal = 0;
            binaryVal = _field[i][j]; binaryVal <<= 1;
            binaryVal |= _field[i][j+1]; binaryVal <<= 1;
            binaryVal |= _field[i+1][j+1]; binaryVal <<= 1;
            binaryVal |= _field[i+1][j];
            *it2pm = binaryVal;
            it2pm++;
        }
        itpm++;
    }
}

void MarchingSquare::displayMarchingSquare() const {
    kmatrix out;
    march(out);

    vpImage<vpRGBa> fieldImage(ROW * SCL, COL * SCL);
    vpDisplayX disp(fieldImage, 10, 10, "KMarchingSquare");
    vpDisplay::display(fieldImage);

    for (kmatrix::const_iterator it = out.begin(); it != out.end(); it++)
        for (vector<int>::const_iterator it2 = it->begin(); it2 != it->end(); it2++) {


        }

    vpImagePoint p1(0,0), p2(0,50);
    //vpDisplay::displayLine(fieldImage, p1, p2, vpColor::green);
    drawSquare(fieldImage, p1, 1);

    vpDisplay::flush(fieldImage);
    vpDisplay::getClick(fieldImage);
}

void MarchingSquare::drawSquare(vpImage<vpRGBa> & im, const vpImagePoint & p, int square) const {
    switch (square) {
        case 1: {
            vpImagePoint offset1(SCL/2, 0);
            vpImagePoint offset2(SCL, SCL/2);
            vpDisplay::displayLine(im, p + offset1, p + offset2, KCOLOR);
            break;
                }
        default:
            break;
    }
}
