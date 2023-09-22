#include <iostream>

void HanoyTowers(int n, int start, int buffer, int finish)
{
    if (n != 1)
    {
        HanoyTowers (n - 1, start, finish, buffer);
        
        std::cout << start << "-->" << finish << '\n';

        HanoyTowers (n - 1, buffer, start, finish);
        
    }
    else
    {
        std::cout << start << "-->" << finish << '\n';
        return;
    }
}
int main(){
    int quantity;
    std::cin >> quantity;

    HanoyTowers(quantity, 1, 2, 3); // HanoyTowers(quantity, start, buff, finish);

    return 0;
}