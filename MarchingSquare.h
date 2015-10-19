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
    class KAtom;
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
        void addAtom(KAtom * atom);
        void updateField();

    public:
        void demoblob();
        void demoblob2();
        void demoblob3();
        // TODO: frame once function

    private:
        kmatrix _field;
        std::vector<KAtom*> _atoms;
        void drawSquare(vpImage<vpRGBa> & im, const vpImagePoint & p, int square) const;
        void drawSquares(vpImage<vpRGBa> & fieldImage, kmatrix & out) const;

        // TODO: opti
        class KAtom {
            public:
                KAtom(vpImagePoint position, double weight) : _position(position), _weight(weight) {}
                virtual double kdistance(const vpImagePoint & point) const {
                    return _weight / sqrt((_position.get_i() - point.get_i()) * (_position.get_i() - point.get_i()) + (_position.get_j() - point.get_j()) * (_position.get_j() - point.get_j()));
                }
                void positionShift(int x, int y) { _position += vpImagePoint(y, x); }
                void positionShift() {
                    if (_position.get_j() + _xSpeed > _xMax || _position.get_j() + _xSpeed < 0) _xSpeed = -_xSpeed;
                    if (_position.get_i() + _ySpeed > _yMax || _position.get_i() + _ySpeed < 0) _ySpeed = -_ySpeed;
                    _position += vpImagePoint(_ySpeed, _xSpeed);
                }
                vpImagePoint _position;
                double _weight;
                double _xSpeed;
                double _ySpeed;
                int _xMax;
                int _yMax;
        };
        // TODO: new KAtoms
};

#endif /* __MARCHINGSQUARE_H__ */



