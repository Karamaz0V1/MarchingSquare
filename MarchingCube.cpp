/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#include "MarchingCube.h"
#include "Filter.h"
#include <iostream>

using namespace std;

MarchingCube::MarchingCube() {
    Cube c1;
    c1 << f;
    Filter f1;
    f1 << a;
    f1 >> b >> d >> e >> c >> f;
    cout << "Cube: " << c1 << endl << "Filter: " << f1 << endl;
    Cube::Rotation r;
    bool ok = f1.place(c1, r);
    cout << "Is ok: " << ok << " rotation: " << r << endl;
    f1.rotateX();
    cout << "Filter: " << f1 << endl;
    f1.rotateY();
    cout << "Filter: " << f1 << endl;
    f1.rotateX();
    cout << "Filter: " << f1 << endl;
    f1.rotateY();
    cout << "Filter: " << f1 << endl;
    f1.rotateX();
    cout << "Filter: " << f1 << endl;
    f1.rotateY();
    cout << "Filter: " << f1 << endl;
    f1.rotateZ();
    cout << "Filter: " << f1 << endl;
    f1.rotateZ();
    f1.rotateZ();
    f1.rotateZ();
    cout << "Filter: " << f1 << endl;
    // First test
    //cout << "test 1" << endl;
    //Cube c1;
    //c1 << a << b << c << h;
    //cout << c1 << endl;
    //cout << "test 2" << endl;
    //Cube c2;
    //c2.setVertex(a);
    //c2.setVertex(b);
    //c2.setVertex(h);
    //cout << c2._vertices << endl;
    //cout << c2.vertex(b) << endl;
    //cout << c2.getId() << endl;
    //Cube filterY, filterN;
    //filterY << a;
    //filterN << b << e << d;
    //Filter f2(filterY, filterN);
    //Cube::Rotation r;
    //cout << "Place? " << f2.place(c1, r) << endl;
    //Filter f3;
    //f3 << a;
    //f3 >> b >> d >> e >> c;
    //cout << "Filter 2: " << f2 << endl;
    //cout << "Filter 3: " << f3 << endl;
    //cout << "== ? "<< (f2 == f3) << endl;
    //cout << "== ? "<< f2.equal(f3) << endl;

}

MarchingCube::~MarchingCube() {}

