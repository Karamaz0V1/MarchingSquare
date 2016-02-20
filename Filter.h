/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#ifndef __FILTER_H__
#define __FILTER_H__
#include "Cube.h"

class Filter: public Cube {
    public:
        Filter(const std::bitset<8> & init);

    private:
        // _mesh3D
        // _normal
        Rotation _r;
};

#endif /* __FILTER_H__ */



