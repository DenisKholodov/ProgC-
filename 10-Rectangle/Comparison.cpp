#include "Comparison.h"

bool Comparison::rectangle(Rectangle rectangle1, Rectangle rectangle2)
{
    if (rectangle1.getCorner1().getX() <= rectangle2.getX_RightSide()  &&
        rectangle1.getCorner1().getX() >= rectangle2.getX_LeftSide()   &&
        rectangle1.getCorner1().getY() <= rectangle2.getY_HigherSide() &&
        rectangle1.getCorner1().getY() >= rectangle2.getY_LowerSide())
        return 1;
    else if (rectangle1.getCorner2().getX() <= rectangle2.getX_RightSide()  &&
             rectangle1.getCorner2().getX() >= rectangle2.getX_LeftSide()   &&
             rectangle1.getCorner2().getY() <= rectangle2.getY_HigherSide() &&
             rectangle1.getCorner2().getY() >= rectangle2.getY_LowerSide())
        return 1;
    else if (rectangle1.getCorner3().getX() <= rectangle2.getX_RightSide()  &&
             rectangle1.getCorner3().getX() >= rectangle2.getX_LeftSide()   &&
             rectangle1.getCorner3().getY() <= rectangle2.getY_HigherSide() &&
             rectangle1.getCorner3().getY() >= rectangle2.getY_LowerSide())
        return 1;
    else if (rectangle1.getCorner4().getX() <= rectangle2.getX_RightSide()  &&
             rectangle1.getCorner4().getX() >= rectangle2.getX_LeftSide()   &&
             rectangle1.getCorner4().getY() <= rectangle2.getY_HigherSide() &&
             rectangle1.getCorner4().getY() >= rectangle2.getY_LowerSide())
        return 1;
    else
        return 0;
}