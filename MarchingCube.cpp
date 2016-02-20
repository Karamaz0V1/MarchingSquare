/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#include "MarchingCube.h"
#include <iostream>

using namespace std;

MarchingCube::MarchingCube() {
    cout << "test 1" << endl;
    Cube c1;
    cout << c1._vertices << endl;
    cout << "test 2" << endl;
    Cube c2(254);
    cout << c2._vertices << endl;
    cout << c2.vertex(b) << endl;
    cout << c2.getId() << endl;
}

MarchingCube::~MarchingCube() {}

