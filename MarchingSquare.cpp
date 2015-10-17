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
#define COL 192
#define ROW 108
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

    vpImage<vpRGBa> fieldImage(ROW * SCL - SCL, COL * SCL - SCL);
    vpDisplayX disp(fieldImage, 10, 10, "KMarchingSquare");
    vpDisplay::display(fieldImage);

    for (int i = 0; i < out.size(); i++)
        for (int j = 0; j < out[0].size(); j++)
            drawSquare(fieldImage, vpImagePoint(i * SCL, j * SCL), out[i][j]);

    vpDisplay::flush(fieldImage);
    vpDisplay::getClick(fieldImage);
}

void MarchingSquare::animate() {
    vpImage<vpRGBa> fieldImage(ROW * SCL - SCL, COL * SCL - SCL);
    vpDisplayX disp(fieldImage, 10, 10, "KMarchingSquare");
    vpDisplay::display(fieldImage);
    kmatrix out;
    while (true) {
        randomize(10);
        march(out);
        vpDisplay::display(fieldImage);
        for (int i = 0; i < out.size(); i++)
            for (int j = 0; j < out[0].size(); j++)
                drawSquare(fieldImage, vpImagePoint(i * SCL, j * SCL), out[i][j]);
        vpDisplay::flush(fieldImage);
    }
}

void MarchingSquare::drawSquare(vpImage<vpRGBa> & im, const vpImagePoint & p, int square) const {
    switch (square) {
        case 14:
        case 1: {
            vpImagePoint offset1(SCL/2, 0);
            vpImagePoint offset2(SCL, SCL/2);
            vpDisplay::displayLine(im, p + offset1, p + offset2, KCOLOR);
            break;
                }
        case 13:
        case 2: {
            vpImagePoint offset1(SCL, SCL/2);
            vpImagePoint offset2(SCL/2, SCL);
            vpDisplay::displayLine(im, p + offset1, p + offset2, KCOLOR);
            break;
                }
        case 12:
        case 3: {
            vpImagePoint offset1(SCL/2, 0);
            vpImagePoint offset2(SCL/2, SCL);
            vpDisplay::displayLine(im, p + offset1, p + offset2, KCOLOR);
            break;
                }
        case 11:
        case 4: {
            vpImagePoint offset1(0, SCL/2);
            vpImagePoint offset2(SCL/2, SCL);
            vpDisplay::displayLine(im, p + offset1, p + offset2, KCOLOR);
            break;
                }
        case 5: {
            vpImagePoint offset1(SCL/2, 0);
            vpImagePoint offset2(0, SCL/2);
            vpDisplay::displayLine(im, p + offset1, p + offset2, KCOLOR);
            offset1 = vpImagePoint(SCL, SCL/2);
            offset2 = vpImagePoint(SCL/2, SCL);
            vpDisplay::displayLine(im, p + offset1, p + offset2, KCOLOR);
            break;
                }
        case 9:
        case 6: {
            vpImagePoint offset1(0, SCL/2);
            vpImagePoint offset2(SCL, SCL/2);
            vpDisplay::displayLine(im, p + offset1, p + offset2, KCOLOR);
            break;
                }
        case 8:
        case 7: {
            vpImagePoint offset1(SCL/2, 0);
            vpImagePoint offset2(0, SCL/2);
            vpDisplay::displayLine(im, p + offset1, p + offset2, KCOLOR);
            break;
                }
        case 10: {
            vpImagePoint offset1(0, SCL/2);
            vpImagePoint offset2(SCL/2, SCL);
            vpDisplay::displayLine(im, p + offset1, p + offset2, KCOLOR);
            offset1 = vpImagePoint(SCL/2, 0);
            offset2 = vpImagePoint(SCL, SCL/2);
            vpDisplay::displayLine(im, p + offset1, p + offset2, KCOLOR);
            break;
                }
        default:
            break;
    }
}
