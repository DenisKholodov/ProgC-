#ifndef ISTACK_H
#define ISTACK_H

#include <iostream>

class Istack 
{
public:
    virtual void pop() = 0;
    virtual void push(int elem) = 0;
    virtual void print() = 0;
    virtual void printErrorMassage() = 0;

    virtual ~Istack(){};
};

void Istack::printErrorMassage()
{
    std::cout << "You cannot delete element.\n";
};

#endif