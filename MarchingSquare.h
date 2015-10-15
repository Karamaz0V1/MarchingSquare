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
#define matrix std::vector<std::vector<int> >

class MarchingSquare {
    public:
        MarchingSquare();
        virtual ~MarchingSquare();
        void randomize(int n = 500);
        void dispMatrix() const;
        void dispMatrix(const matrix & mat) const;
        void march(matrix & patternMap) const;

    private:
        matrix _field;
};

#endif /* __MARCHINGSQUARE_H__ */



