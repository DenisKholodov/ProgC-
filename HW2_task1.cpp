#include <iostream>
#include <array>
#include <memory>

using namespace std;

void VariantFirst ()
{
    int arr[5] = {1,2,3,4,5};
    
    cout << "First (the simplest) variant: int arr[5]:\n";

    for (int i = 0; i < 5; i++){
        cout << arr[i] << ' ';
    }

    cout << "\nUff, it was great!\n";
}

void VariantSecond ()
{
    int n = 5;
    int* darr;
    
    cout << "Second variant (dynamic array):\n";

    darr = (int *) malloc (n * sizeof(int));
    if (darr == NULL){
        cout << "Oops! I cannot give you enough memory :(( Sorry not sorry\n";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 5; i++){
        darr[i] = i + 1;
        cout << darr[i] << ' ';
    }
    free(darr);
    cout << "\nUff, it was great!\n";
}

void VariantThird()
{
    array<int, 5> numbers {1,2,3,4,5};

    cout << "Third variant (modul <array>):\n";

    for (int i = 0; i < 5; i++){
        cout << numbers[i] << ' ';
    }

    cout << "\nUff, it was great!\n";
}

void VariantFourth()
{
    int* darr{new int[5]{1,2,3,4,5}};

    cout << "Fourth (new) variant:\n";

    for (int i = 0; i < 5; i++){
        cout << darr[i] << ' ';
    }

    delete [] darr;    // удаление и освобождение памяти динамического массива
    darr = nullptr;    // обнуление указателя

    cout << "\nUff, it was great!\n";
}

void VariantFifth()
{
    auto darr_smart {make_unique <int[]> (5)};
    
    cout << "Fifth (smart pointer) variant:\n";

    for (int i = 0; i < 5; i++)
    {
        darr_smart[i] = i + 1;
        cout << darr_smart[i] << ' ';
    }

    cout << "\nUff, it was great!\n";
}

/*void VariantSixth() //Только для С++20
{
    auto darr_shared {make_shared <int[]> (5)}; 
    
    cout << "Fifth (shared pointer) variant:\n";

    for (int i = 0; i < 5; i++)
    {
        darr_shared[i] = i + 1;
        cout << darr_shared[i] << ' ';
    }
    
    cout << "\nUff, it was great!\n";
}*/


int main ()
{
    VariantFirst();
    cout << "\n";
    VariantSecond();
    cout << "\n";
    VariantThird();
    cout << "\n";
    VariantFourth();
    cout << "\n";
    VariantFifth();
    cout << "\n";
    //VariantSixth();
    return 0;
}