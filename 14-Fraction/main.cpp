#include <iostream>
#include "Fraction.h"

int main()
{

    Fraction example1{0, 0};
    std::cout << example1.getNum() << '\n';
    std::cout << example1.getDenom() << '\n';
    example1.printFraction();
    std::cout << '\n';
    example1.printDecimal();

    std::cout << '\n';
    std::cout << '\n';
    
    Fraction example3{16, -4};
    std::cout << example3.getNum() << '\n';
    std::cout << example3.getDenom() << '\n';
    example3.printFraction();
    std::cout << '\n';
    example3.printDecimal();

    std::cout << '\n';
    std::cout << '\n';

    (example1 + example3).printFraction();
    std::cout << '\n';
    (example1 + example3).printDecimal();

    return 0;
}