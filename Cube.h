/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#ifndef __CUBE_H__
#define __CUBE_H__
#include <bitset>
#include <iostream>

#define a 0                              //    h---------g
#define b 1                              //   /|        /|
#define c 2                              //  d---------c |
#define d 3                              //  | |       | |
#define e 4                              //  | |       | |
#define f 5                              //  | e-------|-f
#define g 6                              //  |/        |/
#define h 7                              //  a---------b

class Cube {
    public:
        Cube(const std::bitset<8> & init = std::bitset<8>());
        Cube(const Cube & cube);
        virtual ~Cube();
        bool vertex(int index) const;
        void setVertex(int index);
        std::bitset<8> & vertices();
        int getId() const;
        virtual bool equal(const Cube & cube) const;

        virtual bool operator==(const Cube & cube) { return equal(cube); }

        friend Cube& operator<<(Cube& cube, int vertex) { cube._vertices[vertex] = true; return cube; }
        friend std::ostream& operator<<(std::ostream& stream, const Cube & cube) { stream << "[" << cube._vertices << "]"; return stream;}

    public:
        //unsigned char _vertices;
        std::bitset<8> _vertices;

        class Rotation {
            public:
                int _x;
                int _y;
                int _z;

            public:
                Rotation(int x = 0, int y = 0, int z = 0) : _x(x), _y(y), _z(z) {}
                void rotate(int ix, int iy, int iz) { _x += ix; _y += iy; _z += iz; }
                // TODO: orly euler?
                void rotateX(int i = 1) { _x = (_x + i) % 4; }
                void rotateY(int i = 1) { _y = (_y + i) % 4; }
                void rotateZ(int i = 1) { _z = (_z + i) % 4; }
                friend std::ostream& operator<<(std::ostream& stream, const Rotation& rotation) { stream << "[" << rotation._x << ", " << rotation._y << ", " << rotation._z << "]"; return stream;}
        };
};

#endif /* __CUBE_H__ */



