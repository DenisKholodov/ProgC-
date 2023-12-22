#include <iostream>
#include <vector>
#include <cmath>
#include <string>

class A
{
public:
    int power (int a)
    {
        return a*a;
    } 
};
A gm_a;

class B
{
public:
    void oput (int a)
    {
        std::cout << a << '\n';
    }
    void oputZavis (int a)
    {
        std::cout << gm_a.power(a) << '\n';
    }
};

int main()
{
    std::vector <std::string> a{"name", "misha"};
    //std::vector <int> b(3, 10);
    int c(2.7);
    int c1{2.7};

    std::cout << trunc(2.88)<<'\n';
    std::cout << a.front() << '\n';
    std::cout << c1;
    return 0;
}