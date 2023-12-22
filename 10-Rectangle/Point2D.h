#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class Point2D
{
private:
    int m_x;
    int m_y;
public:
    Point2D(int x = 0, int y = 0) : m_x(x), m_y(y) {}

    Point2D& setPoint(int x, int y);

    int getX() const {return m_x;}
    int getY() const {return m_y;}
    void print() const;
};

#endif