#include <vector>
#include <iostream>
#include <stdarg.h>

class LIFO
{
private:
    std::vector<int> stack;
public:
    LIFO(){};
    LIFO(int n, ...)
    {
    va_list factor;         //указатель va_list
    va_start(factor, n);    // устанавливаем указатель
    for(int i = 0; i < n; i++)
    {
        stack.push_back(va_arg(factor, int));  // получаем значение текущего параметра типа int
    }
    va_end(factor); // завершаем обработку параметров
    };

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
    LIFO& push_n(int n, ...)
    {
        va_list factor;         //указатель va_list
        va_start(factor, n);    // устанавливаем указатель
        for(int i = 0; i < n; i++)
        {
            stack.push_back(va_arg(factor, int));  // получаем значение текущего параметра типа int
        }
        va_end(factor); // завершаем обработку параметров
        return *this;
    }
    LIFO& print()
    {
        if (stack.empty())
        {
            std::cout << "Stack is empty.\n";
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

class FIFO
{
private:
    std::vector <int> queue;
public:
    FIFO(){};
    FIFO(int n, ...)
    {
    va_list factor;         //указатель va_list
    va_start(factor, n);    // устанавливаем указатель
    for(int i = 0; i < n; i++)
    {
        queue.push_back(va_arg(factor, int));  // получаем значение текущего параметра типа int
    }
    va_end(factor); // завершаем обработку параметров
    };

    FIFO& pop()
    {
        if (queue.empty())
            std::cout << "Queue is empty. You cannot delete element.\n";
        else
            queue.erase(queue.end());
        return *this;
    }
    FIFO& push(int elem)
    {
        std::vector<int> queue_h;
        queue_h.resize(queue.size() + 1);
        for (int i = 1; i < queue_h.size(); i++)
        {
            queue_h.at(i) = queue.at(i - 1);
        }
        queue_h[0] = elem;
        queue = queue_h;
        return *this;
    }
    FIFO& print()
    {
        if (queue.empty())
        {
            std::cout << "Queue is empty.\n";
            return *this;
        }
        for (const auto &elem : queue)
        {
            std::cout << elem << " ";
        }
        std::cout << '\n';
        return *this;
    }
};

int main()
{
    LIFO stack1;
    LIFO stack{5, 1,2,3,4,5};
    stack.print().push(5).print().push(7).push(8).print().pop().print().pop().pop().print().pop().pop();
    std::cout << '\n';
    FIFO queue{5, 1,2,3,4,5};
    queue.print().push(5).print().push(7).push(8).print().pop().print().pop().pop().print().pop().pop();
    return 0;
}