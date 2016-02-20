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
};

#endif /* __CUBE_H__ */



