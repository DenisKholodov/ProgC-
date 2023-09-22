#include <iostream>
#include <string>
#include <array>

long int fibb_recersion(long int n)
{
    if (n > 2)
    {   
        return fibb_recersion(n - 1) + fibb_recersion(n - 2);
    }
    else
    {
        return 1;
    }
}

void fibb_for(long int n)
{
    long int fibb1 = 1, fibb2 = 1, fibb_h;
    for (int i = 0; i < n; i++)
    {
        std::cout << fibb1 << ' ';
        fibb_h = fibb2;
        fibb2 = fibb1 + fibb2;
        fibb1 = fibb_h;
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
        fibb_for(n);
    }
    return 0;
}