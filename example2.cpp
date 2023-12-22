#include <vector>
#include <iostream>

class Istack 
{
public:
    virtual void pop() = 0;
    virtual void push(int elem) = 0;
    virtual Istack& print() = 0;

    virtual ~Istack(){};
};

class LIFO : public Istack
{
private:
    std::vector<int> stack;
public:
    virtual void pop()
    {
        if (stack.empty())
            std::cout << "Stack is empty. You cannot delete element.\n";
        else
            stack.pop_back();
        //return *this;
    }
    virtual void push(int elem)
    {
        stack.push_back(elem);
        //return *this;
    }
    virtual Istack& print()
    {
        if (stack.empty())
        {
            std::cout << "Empty.\n";
            //return *this;
            return *this;
        }
        for (const auto &elem : stack)
        {
            std::cout << elem << " ";
        }
        std::cout << '\n';
        return *this;
    }
};

class FIFO : public Istack
{
private:
    std::vector<int> stack;
public:
    virtual void pop()
    {
        if (stack.empty())
            std::cout << "Queue is empty. You cannot delete element.\n";
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