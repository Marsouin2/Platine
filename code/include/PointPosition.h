#ifndef POINT_POSITION_H_
#define POINT_POSITION_H_

// # basic position struct containing two points
// ADU : pouvoir mettre que float ou double
template<typename T>
class PointPosition
{
public:
    PointPosition(T x, T y) : _x(x), _y(y) {}
    PointPosition() : _x(0.0), _y(0.0) {}
    ~PointPosition() { reset(); }
    void reset() { _x = 0.0; _y = 0.0; }

private:
    T _x; // abscisse
    T _y; // ordonnee
};

#endif