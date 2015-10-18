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
#include <visp/vpDisplayX.h>
#define kmatrix std::vector<std::vector<int> >

class MarchingSquare {
    public:
        MarchingSquare();
        virtual ~MarchingSquare();
        void randomize(int n = 500);
        void dispMatrix() const;
        void dispMatrix(const kmatrix & mat) const;
        void march(kmatrix & patternMap) const;
        void displayMarchingSquare() const;
        void animate();
        void drawCircle(int i, int j, int size);
        void resetField();
        void blebleble();

    private:
        kmatrix _field;
        void drawSquare(vpImage<vpRGBa> & im, const vpImagePoint & p, int square) const;
};

#endif /* __MARCHINGSQUARE_H__ */



