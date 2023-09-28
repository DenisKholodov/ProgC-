#include <iostream>
#include <ctime>
#include <limits>

bool OddOrEven_loop(int num)
{
    while (num && num != 1 && num != -1) 
    {
        num = num % 2;
    }
    return num;
}

bool OddOrEven_recursion(int num)
{
    if (num && num != 1 && num != -1) return OddOrEven_recursion(num % 2);
    else return num;
}

bool OddOrEven_bitMultiply(int num)
{
    return num & 1;
}

bool OddOrEven_bitShift(int num)
{
    int a = num >> 1;
    if (num == (a << 1)) return 0;
    else return 1;
}

void PrintOddEven(bool a)
{
    if (a) std::cout << "Odd\n";
    else std::cout << "Even\n";
}

int main()
{
    int N = 5;
    int arr0[N];
    int arr1[N];
    int arr2[N];
    int arr3[N];

    /*
    int number;
    std::cout << "number = ";
    std::cin >> number;
    PrintOddEven(OddOrEven_for(number));
    PrintOddEven(OddOrEven_bitMultiply(number));
    PrintOddEven(OddOrEven_bitShift(number));
*/
    for (int k = 0; k < N; k++){
        unsigned int start_time0 =  clock();
        for (int i = 0; i < INT_MAX; i++)
        {
            OddOrEven_loop(i);
        }
        unsigned int end_time0 = clock();
        std::cout << '(' << k << ')' << " Time of loop variant: " << end_time0 - start_time0 << '\n';
        
        arr0[k] = end_time0 - start_time0;
    }
    
    std::cout << '\n';

    for (int k = 0; k < N; k++){
        unsigned int start_time1 =  clock();
        for (int i = 0; i < INT_MAX; i++)
        {
            OddOrEven_recursion(i);
        }
        unsigned int end_time1 = clock();
        std::cout << '(' << k << ')' << " Time of recursion variant: " << end_time1 - start_time1 << '\n';
        
        arr1[k] = end_time1 - start_time1;
    }
    
    std::cout << '\n';
    
    for (int k = 0; k < N; k++){    
        unsigned int start_time2 =  clock();
        for (int i = 0; i < INT_MAX; i++)
        {
            OddOrEven_bitMultiply(i);
        }
        unsigned int end_time2 = clock();
        std::cout  << '(' << k << ')' << " Time of bitwise multiplication variant: " << end_time2 - start_time2 << '\n';

        arr2[k] = end_time2 - start_time2;
    }

    std::cout << '\n';
    
    for (int k = 0; k < N; k++){
        unsigned int start_time3 =  clock();
        for (int i = 0; i < INT_MAX; i++)
        {
            OddOrEven_bitShift(i);
        }
        unsigned int end_time3 = clock();
        std::cout << '(' << k << ')' << " Time of bitwise shift variant: " << end_time3 - start_time3 << '\n';

        arr3[k] = end_time3 - start_time3;
    }

    std::cout << '\n';

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr0[i];
    }
    std::cout << "Arithmetic mean of loop time = " << sum/N << '\n';
    
    sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr1[i];
    }
    std::cout << "Arithmetic mean of recursion time = " << sum/N << '\n';

    sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr2[i];
    }
    std::cout << "Arithmetic mean of bitwise multiplication time = " << sum/N << '\n';
    
    sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr3[i];
    }
    std::cout << "Arithmetic mean of bitwise shift time = " << sum/N << '\n';

    return 0;
}