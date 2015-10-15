/***************************************************************************
 *
 * TODO: Project Title
 *
 * Author: Florent Guiotte <guiotte.florent@gmail.com>
 *
 **************************************************************************/

#ifndef __MARCHINGSQUARE_H__
#define __MARCHINGSQUARE_H__
#include <vector>

class MarchingSquare {
    public:
        MarchingSquare();
        ~MarchingSquare();
        void randomize(int n = 100);

    private:
        std::vector<std::vector<int> > _field;
};

#endif /* __MARCHINGSQUARE_H__ */



