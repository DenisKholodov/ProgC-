#include <string>
#include <iostream>

std::string A  (std::string a, std::string b)
{
    if (a<b)
        return a;
    else
        return b;
}


int main()
{
    std::cout << A("9rtyuio", "1");
    return 0;
}