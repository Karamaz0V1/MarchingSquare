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

#define a 0
#define b 1
#define c 2
#define d 3
#define e 4
#define f 5
#define g 6
#define h 7

class Cube {
    public:
        Cube();
        virtual ~Cube() = 0;
        inline bool vertex(int index) const;
        std::bitset<8> & vertices();

    public:
        //unsigned char _vertices;
        std::bitset<8> _vertices;
};

#endif /* __CUBE_H__ */



