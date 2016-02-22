/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#ifndef __FILTER_H__
#define __FILTER_H__
#include "GridCube.h"

class Filter: public Cube {
    public:
        Filter(const std::bitset<8> & vertices = std::bitset<8>(), const std::bitset<8> & nvertices = std::bitset<8>());
        Filter(const Cube & vertices, const Cube & nvertices);
        Filter(const Filter & filter);
        virtual bool equal(const Filter & filter) const;
        bool place(const Cube & cube, Rotation & r) const;
        bool place(const GridCube & gc, Rotation & r) const;
        virtual int activeVertices() const;
        virtual int narpVertices() const;

        void rotateX();
        void rotateY();
        void rotateZ();

        virtual bool operator==(const Filter & filter) { return equal(filter); }

        friend Filter& operator>>(Filter& filter, int vertex) { filter._nvertices[vertex] = true; return filter; }
        friend std::ostream& operator<<(std::ostream& stream, const Filter & filter) { stream << "Y[" << filter._vertices << "]N[" << filter._nvertices << "]R" << filter._r; return stream;}

    private:
        bool place(const Cube & cube) const;
        bool placeZ(const Cube & cube, Rotation & rotation);

    public:
        std::bitset<8> _nvertices;

    private:
        // _mesh3D
        // _normal
        Rotation _r;
};

#endif /* __FILTER_H__ */



