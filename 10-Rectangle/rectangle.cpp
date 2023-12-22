#include <vector>
#include "rectangle.h"

Rectangle::Rectangle(const Point2D &corner1, const Point2D &corner2, const Point2D &corner3, const Point2D &corner4)
{
    std::vector<Point2D> arrCorner {corner1, corner2, corner3, corner4};

    int MIN_x(corner1.getX()), MAX_x(corner1.getX()), MIN_y(corner1.getY()), MAX_y(corner1.getY());
        
    for (const auto &point : arrCorner)
        if (point.getX() > MAX_x)
            MAX_x = point.getX();
    for (const auto &point : arrCorner)
        if (point.getY() > MAX_y)
            MAX_y = point.getY();
    for (const auto &point : arrCorner)
        if (point.getX() < MIN_x)
            MIN_x = point.getX();
    for (const auto &point : arrCorner)
        if (point.getY() < MIN_y)
            MIN_y = point.getY();
    m_corner1.setPoint(MIN_x, MIN_y);
    m_corner2.setPoint(MIN_x, MAX_y);
    m_corner3.setPoint(MAX_x, MAX_y);
    m_corner4.setPoint(MAX_x, MIN_y);
}