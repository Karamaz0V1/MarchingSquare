/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#include <iostream>
#include "MarchingSquare.h"
#include <vector>
using std::vector;

int main( int argc, char* argv[] )
{
    std::cout << "HULLO!" << std::endl;
    MarchingSquare ms;
    ms.randomize(50);
    ms.dispMatrix();
    vector<vector<int> > out;
    ms.march(out);
    ms.dispMatrix(out);
    ms.displayMarchingSquare();
}


