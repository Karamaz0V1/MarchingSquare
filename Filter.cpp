/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#include "Filter.h"
using namespace std;

Filter::Filter(const std::bitset<8> & init) : Cube(init) {
    _r.rotateX();
    cout << "Rotation: " << _r << endl;
}
