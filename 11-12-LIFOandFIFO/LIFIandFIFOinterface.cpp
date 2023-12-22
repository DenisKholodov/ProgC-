#include <vector>
#include <iostream>

#include "Istack.h"

class LIFO : public Istack
{
private:
    std::vector<int> stack;
public:

    virtual void printErrorMassage()
    {
        Istack::printErrorMassage();
    }

    virtual void pop()
    {
        if (stack.empty())
            LIFO::printErrorMassage();
        else
            stack.pop_back();
        //return *this;
    }
    
    virtual void push(int elem)
    {
        stack.push_back(elem);
        //return *this;
    }

    virtual void print()
    {
        if (stack.empty())
        {
            std::cout << "Empty.\n";
            //return *this;
            return;
        }
        for (const auto &elem : stack)
        {
            std::cout << elem << " ";
        }
        std::cout << '\n';
        //return *this;
    }
};

class FIFO : public Istack
{
private:
    std::vector<int> stack;
public:

    virtual void printErrorMassage()
    {
        Istack::printErrorMassage();
    }

    virtual void pop()
    {
        if (stack.empty())
            FIFO::printErrorMassage();
        else
            stack.erase(stack.end());
        //return *this;
    }
    virtual void push(int elem)
    {
        std::vector<int> queue_h;
        queue_h.resize(stack.size() + 1);
        for (int i = 1; i < queue_h.size(); i++)
        {
            queue_h.at(i) = stack.at(i - 1);
        }
        queue_h[0] = elem;
        stack = queue_h;
        //return *this;
    }

    virtual void print()
    {
        if (stack.empty())
        {
            std::cout << "Empty.\n";
            //return *this;
            return;
        }
        for (const auto &elem : stack)
        {
            std::cout << elem << " ";
        }
        std::cout << '\n';
        //return *this;
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