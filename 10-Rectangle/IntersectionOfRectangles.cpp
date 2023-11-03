#include <iostream>

class Point2D
{
private:
    int m_x;
    int m_y;
public:
    Point2D(int x = 0, int y = 0)
        : m_x(x), m_y(y)
    {
    }

    void setPoint(int x, int y)
    {
        m_x = x;
        m_y = y;
    }

    int getX()
    {
        return m_x;
    }

    int getY()
    {
        return m_y;
    }
};

class Rectangle
{
private:
    Point2D m_corner1;
    Point2D m_corner2;
    Point2D m_corner3;
    Point2D m_corner4;

public:
    Rectangle(const Point2D &corner1, const Point2D &corner2, const Point2D &corner3, const Point2D &corner4)
        : m_corner1(corner1), m_corner2(corner2), m_corner3(corner3), m_corner4(corner4)
    {
    }

    int getY_LowerSide()
    {
        return m_corner1.getY();
    }

    
    int getY_HigherSide()
    {
        return m_corner3.getY();
    }


    int getX_LeftSide()
    {
        return m_corner1.getX();
    }


    int getX_RightSide()
    {
        return m_corner3.getX();
    }

};


int main()
{
    Rectangle rec1(Point2D(2, 3), Point2D(2, 5), Point2D(4, 5), Point2D(4, 3));
    Rectangle rec2(Point2D(3, 4), Point2D(3, 7), Point2D(8, 7), Point2D(8, 4));
    if (rec1.getY_LowerSide() <= rec2.getY_HigherSide() && rec2.getX_LeftSide() <= rec1.getX_RightSide())
        std::cout << "Intersection!\n";
    else if (rec1.getY_LowerSide() <= rec2.getY_HigherSide() && rec2.getX_RightSide() >= rec1.getX_LeftSide())
        std::cout << "Intersection!\n";
    else if (rec1.getY_HigherSide() >= rec2.getY_LowerSide() && rec2.getX_LeftSide() <= rec1.getX_RightSide())
        std::cout << "Intersection!\n";
    else if (rec1.getY_HigherSide() >= rec2.getY_LowerSide() && rec2.getX_RightSide() >= rec1.getX_LeftSide())
        std::cout << "Intersection!\n";

    return 0;
}