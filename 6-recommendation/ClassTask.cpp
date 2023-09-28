#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <array>
#include <cmath>

int GetRandomNumber(int min, int max)
{
  srand(time(NULL));
  return min + rand() % (max - min + 1);
}

int isDigitString(std::string &str)
{
    int sum = 0;
    auto iter = str.begin(); // iter -- ????????; str.begin() -- ???????? ? ??????? ???????? ??????

    for (int i = 0; iter != str.end(); iter++)
    {
        std::cout << *iter << " !! ";
        if (std::isdigit(*iter))
        {
            sum += (int)str[i] - '0';
        }
        i++;
    }
    return sum;
}

int GetMonth(std::string &str)
{
    return (int) (str[3] - '0') * 10 + (str[4] - '0');
}

int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");
    
    std::string strName, strAge;
    long int mass[3] = {0, 11111111, 22222222};

    std::cout << "������� ���� ���:\n";
    std::cin >> strName;
    std::cout << "������� ���� ��������:\n";
    std::cin >> strAge;

    int number = GetRandomNumber(0, 2);

    int sum = isDigitString(strAge);
    int month = GetMonth(strAge);

    unsigned  mega = pow(sum, month) + mass[number];
    
    std::cout << "mega = " << mega << std::endl;

    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = (mega << 12 + 4 * i) >> (28);
        std::cout << arr[i] << " \n";
    }

    std::string music[14] = {"Master of puppets Metallica", "����� Pyrokinesis", "Homebody PH1","������ ������������","Russian Ebunny","Enemy Imagine dragons"," ������� ���� � ��������","Valentine Justice","Swimming pools Kendrick Lamar","Night Call Kovinsky","Yesterday The Beatles","��� ���������� ����� ����������� �������","�� ������ �� ����������","Bad habits Ed sheeran"}; 
    std::string movies[14] ={"�������� ���������", "������������", "�������", "�� ������������ �������","�����������","��� ��������","�������� �","�����","������� ����","���� � ��������","�� ����� � �����","������� ����","��������","�� �������� ������"};
    std::string actors[14] = {"����� �������", "�������� ����", "����� ���","����� �������","�������� ��������","�������� ����������","����� ���������","����� ����","������� ��������","����� ����������","��������� ������","������� ������","��� ����","���� ����"}; 
    std::string actriss[14] = {"������� �����������", "����� ����", "��������� �����","���� �����","���� ������","���� ������","����� �������","����� �����","����� �����","������� ���������","���������� ������","��������� �����","������ �����","��������� ����������"}; 
    std::string celeb[14] = {"���� ���������", "���� ����", "������ �������", "��������� ��������", "������ ����������", "������� �����", "�����", "����� �������", "������ �������","����� ����","��������� �������","����� �����","��� ���������","����� ����"};
    
    std::cout << "������������, " << strName << "!\n";
    std::cout << "���� ������: " << music[arr[0]%14] << '\n';
    std::cout << "��� �����: " << movies[arr[1]%14]<< '\n';
    std::cout << "��� �����: " << actors[arr[2]%14] << '\n';
    std::cout << "���� �������: " << actriss[arr[3]%14] << '\n';
    std::cout << "���� ������: " << celeb[arr[4]%14] << '\n';

    return 0;
}