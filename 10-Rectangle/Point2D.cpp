#include <iostream>
#include "Point2D.h"

void Point2D::print() const 
{
    std::cout << "X = " << m_x << "  Y = " << m_y << '\n';
}

Point2D& Point2D::setPoint(int x, int y)
{
    m_x = x;
    m_y = y;
    return *this;
}