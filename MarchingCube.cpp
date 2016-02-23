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
    GridCube c1;
    c1 << a;
    cout << "Cube: " << c1 << endl;
    buildFilters();
    computeCases();
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

void MarchingCube::computeCases() {
    int cpt = 0;
    for (int i = 0; i < 256; i++) {
        GridCube gc(i);
        cout << "Case " << i << ": " << gc;
        Cube::Rotation r;
        for (vector<Filter>::const_iterator it = _filters.begin(); it != _filters.end(); it++) {
            while (it->place(gc, r)) {
            }
        }
        if (gc.activeVertices() == 0) {
            cout << " [COMPLETE]" << endl;
            cpt ++;
        } else {
            cout << " [INCOMPLETE]" << endl;
        }
        _gridcubes.push_back(gc);
    }
    cout << cpt << "/256 complete" << endl;
}

void MarchingCube::buildFilters() {
    Filter f6;
    f6 << a << b << c << e;
    f6 >> d >> f >> g >> h;
    _filters.push_back(f6);

    Filter f5;
    f5 << a << b << c << f;
    f5 >> d >> e >> g;
    _filters.push_back(f5);

    Filter f4;
    f4 << a << b << c << d;
    f4 >> e >> f >> g >> h;
    _filters.push_back(f4);

    Filter f3;
    f3 << a << b << c;
    f3 >> d >> e >> f >> g;
    _filters.push_back(f3);

    Filter f2;
    f2 << a << b;
    f2 >> d >> c >> e >> f;
    _filters.push_back(f2);

    Filter f1;
    f1 << a;
    f1 >> b >> d >> e;
    //f1.meshes() = ogreMeshe;
    _filters.push_back(f1);

    Filter f1b = f1;

    Filter f0;
    f0 << a << b << c << d << e << f << g << h;
    _filters.push_back(f0);
}
