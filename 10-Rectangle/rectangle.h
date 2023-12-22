#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Point2D.h"

class Rectangle
{
private:
    Point2D m_corner1;
    Point2D m_corner2;
    Point2D m_corner3;
    Point2D m_corner4;

public:
    Rectangle(const Point2D &corner1, const Point2D &corner2, const Point2D &corner3, const Point2D &corner4);

    int getY_LowerSide() { return m_corner1.getY();}
    int getY_HigherSide() { return m_corner3.getY();}
    int getX_LeftSide() { return m_corner1.getX();}
    int getX_RightSide() { return m_corner3.getX();}

    Point2D getCorner1() { return m_corner1; }
    Point2D getCorner2() { return m_corner2; }
    Point2D getCorner3() { return m_corner3; }
    Point2D getCorner4() { return m_corner4; }
};

#endif