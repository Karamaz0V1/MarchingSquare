/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#ifndef __MARCHINGCUBE_H__
#define __MARCHINGCUBE_H__
#include <vector>
#include "GridCube.h"
#include "Filter.h"

class MarchingCube {
    public:
        MarchingCube();
        ~MarchingCube();

    private:
        void computeCases();
        void buildFilters();

    private:
        std::vector<GridCube> _gridcubes;
        std::vector<Filter> _filters;
        // _cases[256];

};

#endif /* __MARCHINGCUBE_H__ */
