/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#ifndef __GRIDCUBE_H__
#define __GRIDCUBE_H__
#include "Cube.h"

class GridCube: public Cube {
    public:
        GridCube(const GridCube & gc);
        GridCube(const std::bitset<8> & init = std::bitset<8>());

    public:
        std::bitset<8> _treated;
};

#endif /* __GRIDCUBE_H__ */



