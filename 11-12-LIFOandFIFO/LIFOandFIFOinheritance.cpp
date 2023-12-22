#include <vector>
#include <iostream>

class LIFO
{
protected:
    std::vector<int> stack;
public:
    LIFO& pop()
    {
        if (stack.empty())
            std::cout << "Stack is empty. You cannot delete element.\n";
        else
            stack.pop_back();
        return *this;
    }
    LIFO& push(int elem)
    {
        stack.push_back(elem);
        return *this;
    }
    LIFO& print()
    {
        if (stack.empty())
        {
            std::cout << "Empty.\n";
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

class FIFO : public LIFO
{
public:
    FIFO& pop()
    {
        if (stack.empty())
            std::cout << "Queue is empty. You cannot delete element.\n";
        else
            stack.erase(stack.end());
        return *this;
    }
    FIFO& push(int elem)
    {
        std::vector<int> queue_h;
        queue_h.resize(stack.size() + 1);
        for (int i = 1; i < queue_h.size(); i++)
        {
            queue_h.at(i) = stack.at(i - 1);
        }
        queue_h[0] = elem;
        stack = queue_h;
        return *this;
    }
};

int main()
{
    LIFO stack;
    stack.print().push(5).print().push(7).push(8).print().pop().print().pop().pop().print().pop().pop();
    std::cout << '\n';
    FIFO queue;
    queue.print().push(5).print().push(7).push(8).print().pop().print().pop().pop().print().pop().pop();
    return 0;
}