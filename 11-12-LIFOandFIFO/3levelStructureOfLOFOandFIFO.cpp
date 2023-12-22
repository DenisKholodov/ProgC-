#include <vector>
#include <iostream>

#include "Istack3levelStruct.h"

class LIFO : public ContainVector
{
public:
    
    virtual void push(int element)
    {
    m_elements.push_back(element);
    }

};

class FIFO : public ContainVector
{
public:
    virtual void push(int element)
    {
    m_elements.insert(m_elements.begin(), element);
    }
};

int main()
{
    LIFO stack;
    stack.print();
    stack.push(5);
    stack.print();
    stack.push(7);
    stack.push(8);
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.pop();
    stack.print();
    stack.pop();
    stack.pop();
    std::cout << '\n';
    FIFO queue;
    queue.print();
    queue.push(5);
    queue.print();
    queue.push(7);
    queue.push(8);
    queue.print();
    queue.pop();
    queue.print();
    queue.pop();
    queue.pop();
    queue.print();
    queue.pop();
    queue.pop();
    return 0;
}