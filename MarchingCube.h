/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#ifndef __MARCHINGCUBE_H__
#define __MARCHINGCUBE_H__
#include "Cube.h"

class MarchingCube {
    public:
        MarchingCube();
        ~MarchingCube();

    private:
        void computeCases();

    private:
        // _cases[256];

};

#endif /* __MARCHINGCUBE_H__ */
