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
        virtual ~Cube();
        bool vertex(int index) const;
        std::bitset<8> & vertices();
        int getId() const;

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
                void rotateX(int i = 1) { _x += i; }
                void rotateY(int i = 1) { _y += i; }
                void rotateZ(int i = 1) { _z += i; }
                friend std::ostream& operator<<(std::ostream& stream, const Rotation& rotation) { stream << "[" << rotation._x << ", " << rotation._y << ", " << rotation._z << "]"; return stream;}
        };
};

#endif /* __CUBE_H__ */



