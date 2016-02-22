/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include "MarchingCube.h"
#include "GridCube.h"
#include "Filter.h"

using namespace std;

MarchingCube::MarchingCube() {
    vector<Filter> filters;

    Filter f0;
    filters.push_back(f0);

    Filter f1;
    f1 << a;
    f1 >> b >> d >> e;
    //f1.meshes() = ogreMeshe;
    filters.push_back(f1);

    cout << "nactive: " << f1.nonactiveVertices() << " active: " << f1.activeVertices() << " yarp: " << f1.yarpVertices() << " narp: " << f1.narpVertices() << endl;

    for (int i = 0; i < 256; i++) {
        GridCube gc(i);
        Cube::Rotation r;
        bool ok = f1.place(gc, r);
        cout << gc << " is " << ok << " r: " << r << endl;
    }

    GridCube c1;
    c1 << a;
    cout << "Cube: " << c1 << endl << "Filter: " << f1 << endl;
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

