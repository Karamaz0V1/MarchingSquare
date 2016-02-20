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

class Cube {
    public:
        Cube();
        virtual ~Cube() = 0;
        const bool & vertex(int index) const;
        bool & vertex(int index);

    private:
        //unsigned char _vertices;
        std::bitset<8> _vertices;
};

#endif /* __CUBE_H__ */



