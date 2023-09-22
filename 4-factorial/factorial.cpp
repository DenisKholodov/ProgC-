#include <iostream>
#include <string>
#include <array>

long int fact_recersion(int n)
{
    if (n != 1)
    {
        return n * fact_recersion(n - 1);
    }
    else 
    {
        return 1;
    }
}

bool isDigitString(std::string &str)
{
    auto iter = str.begin(); // iter -- итератор; str.begin() -- референс к первому элементу строки
    for (; iter != str.end() && std::isdigit(*iter); iter++){}
    return iter == str.end();
}

int main()
{
    int n;

    std::string str;
    std::cin >> str;
    
    if (isDigitString(str))
    {
        n = std::stoi(str);
    }
    else 
    {
        std::cout << "Not a positive integer number!\n";
        return 0;
    }
    if (n > 51 || n == 0)
    {
        std::cout << "Out of acceptable values!\n";
        return 0;
    }
    else
    {
        std::cout << fact_recersion(n) << std::endl;
    }
    return 0;
}