#include <iostream>
#include <vector>

#include "Point2D.h"
#include "rectangle.h"
#include "Comparison.h"

int main()
{
    Comparison comp;
    
    Rectangle rec1(Point2D(2, 3), Point2D(2, 5), Point2D(4, 5), Point2D(4, 3));
    Rectangle rec2(Point2D(3, 4),  Point2D(8, 7), Point2D(3, 7), Point2D(8, 4));
    
    if (comp.rectangle(rec1, rec2))
        std::cout << "Intersection!\n";
    else 
        std::cout << "Nope Intersection!\n";
    
    return 0;
}