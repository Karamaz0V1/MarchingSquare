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
#define SCL 3 
#define COL 1920 / SCL 
#define ROW 1080 / SCL
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

void MarchingSquare::drawCircle(int i, int j, int size) {
    for (int x = -size / SCL; x < size / SCL; x++)
        for (int y = -size / SCL; y < size / SCL; y ++) {
            int pi = i + x * SCL;
            int pj = j + y * SCL;
            if (sqrt((pi - i) * (pi - i) + (pj - j) * (pj - j)) < size)
                _field[i / SCL + x][j / SCL + y] = 1;
        }
}

void MarchingSquare::resetField() {
    for (kmatrix::iterator it = _field.begin(); it != _field.end(); it++)
        for (vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
            *it2 = 0;
}

void MarchingSquare::addAtom(KAtom * atom) {
    _atoms.push_back(atom);
}

// TODO: updateFieldOpti
void MarchingSquare::updateField() {
    // Grid cross
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++) {
            // Atoms cross
            double score = 0;
            for (vector<KAtom*>::const_iterator it = _atoms.begin(); it != _atoms.end(); it++) {
                score += (*it)->kdistance(vpImagePoint(i * SCL, j * SCL));
            }
            //_field[i][j] = (score >= 1) ? 1 : 0;
            _field[i][j] = (score >= 1);

        }
}

void MarchingSquare::demoblob2() {
    vpImage<vpRGBa> fieldImage(ROW * SCL - SCL, COL * SCL - SCL);
    vpDisplayX disp(fieldImage, 10, 10, "KMarchingSquare");
    vpDisplay::display(fieldImage);
    kmatrix out;

    KAtom * k1 = new KAtom(vpImagePoint(100, 100), 150);
    KAtom * k2 = new KAtom(vpImagePoint(100, 350), 50);
    KAtom * k3 = new KAtom(vpImagePoint(100, 100), 20);

    addAtom(k1);
    addAtom(k2);
    addAtom(k3);
    double k2shift = 10;
    double k3shift = 10;

    while (true) {
        updateField();
        drawSquares(fieldImage, out);
        if (k2->_position.get_j() > 1900) k2shift = -k2shift;
        if (k2->_position.get_j() < 20) k2shift = -k2shift;
        if (k3->_position.get_i() > 1070) k3shift = -k3shift;
        if (k3->_position.get_i() < 10) k3shift = -k3shift;
        k2->positionShift(0, k2shift);
        k3->positionShift(k3shift, 0);
    }

    vpDisplay::getClick(fieldImage);

}

void MarchingSquare::drawSquares(vpImage<vpRGBa> & fieldImage, kmatrix & out) const {
    march(out);
    vpDisplay::display(fieldImage);
    for (int i = 0; i < out.size(); i++)
        for (int j = 0; j < out[0].size(); j++)
                drawSquare(fieldImage, vpImagePoint(i * SCL, j * SCL), out[i][j]);
    vpDisplay::flush(fieldImage);
}

void MarchingSquare::demoblob() {
    vpImage<vpRGBa> fieldImage(ROW * SCL - SCL, COL * SCL - SCL);
    vpDisplayX disp(fieldImage, 10, 10, "KMarchingSquare");
    vpDisplay::display(fieldImage);
    kmatrix out;
    int x = 500, y = 100;
    int x2 = 600, y2 = 1820;
    while (true) {
        resetField();
        drawCircle(x, y, 100);
        drawCircle(x2, y2, 100);
        drawSquares(fieldImage, out);
        //march(out);
        //vpDisplay::display(fieldImage);
        //for (int i = 0; i < out.size(); i++)
        //    for (int j = 0; j < out[0].size(); j++)
        //        drawSquare(fieldImage, vpImagePoint(i * SCL, j * SCL), out[i][j]);
        //vpDisplay::flush(fieldImage);
        y+= SCL;
        y2-= SCL; 
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
