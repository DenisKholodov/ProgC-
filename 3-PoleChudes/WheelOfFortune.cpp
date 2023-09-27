#include <iostream>
#include <string>
#include <array>
#include <windows.h>
#include <locale.h>

int QuantityChar(std::string &str)
{
    int n = 0;
    for (auto iter = str.begin(); iter != str.end(); iter++)
    {
        n++;
    }
    return n;
}
void FillAnswer(std::string &str_E, char* str_A)
{
    auto iter = str_E.begin();
    for (int i = 0; iter != str_E.end(); i++)
    {
        //std::cout << (int) *iter << '\n';
        if (*iter < 0)
        {
            str_A[i] = '_';
        }
        else
        {
            str_A[i] = *iter;
        }
        iter++;
    }
}
void PrintCharsArr (char* str, int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cout << str[i];
    }
    std::cout << '\n' << '\n';
}

bool CINcheck(std::string &str)
{
    auto iter = str.begin();
    for(; iter != str.end(); iter++)
    {
        if ((int) *iter >= 0 && (char) *iter != '-')
        {
            std::cout << "������������ �� ������������� ����� ��� ���� ����������� � ���� �������.\n���������� ��� ���.\n";
            return 1;
        }
    }
    return 0;
}

bool LetterInArrChars(char* arr_ch, int n, char let)
{
    for(int i = 0; i < n; i++)
    {
        if(arr_ch[i] == let) return 1;
    }
    return 0;
}

bool LetterInString(std::string &str, char let)
{
    auto iter = str.begin();
    for (; iter != str.end(); iter++)
    {
        if (*iter == let) return 0;
    }
    return 1;
}

bool Sign_InArrChars(char* arr_ch, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(arr_ch[i] == '_') return 1;
    }
    return 0;
}

void Wheel(std::string &str_KEY, char* str_ANS, int n)
{
    char letter;

    int q = 0; //������� � ������� ��������� ����
    char* arr_chars; // ������ ��������� ����
    arr_chars = (char *) malloc(70 * sizeof (char));

    while(Sign_InArrChars(str_ANS, n))
    {  
        auto iter = str_KEY.begin();
        std::cout << "������� �����: ";
        std::cin >> letter;
        if (letter < 0)
        {
            if (LetterInArrChars(arr_chars, q, letter))
            {
                std::cout << "����� ����� ��� ���� �������!\n";
                PrintCharsArr(str_ANS, n);
            }
            else if (LetterInString(str_KEY, letter))
            {
                std::cout << "����� ����� ��� � �����!\n";
                PrintCharsArr(str_ANS, n);
                arr_chars[q] = letter; q++;
            }
            else 
            {
                for (int k = 0; k < n; k++)
                {
                    if (*iter == letter)
                    {
                        str_ANS[k] = letter;
                    }
                    iter++;
                }
                std::cout << "�������!\n";
                PrintCharsArr(str_ANS, n);
                arr_chars[q] = letter; q++;
            }
        }
        else
        {
            std::cout << "���.. ���-�� ����� �� ���. ���������� ��� ���. ���������� ������� ������������� �����! �� � �������.\n";
            PrintCharsArr(str_ANS, n);
        }
    }
    free(arr_chars);
}

int main()
{
    system("chcp 1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");

    std::string str_enigma;
    do{
        str_enigma = "";
        std::cout << "������� �����, ������� ������� ��������: ";
        std::cin >> str_enigma;
    } while(CINcheck(str_enigma));

    char* chars_answer; //������ �������� � �������
    int n = QuantityChar(str_enigma);
    chars_answer = (char *) malloc(n * sizeof (char));

    FillAnswer(str_enigma, chars_answer);
    PrintCharsArr(chars_answer, n);

    Wheel(str_enigma, chars_answer, n);

    std::cout << "���� ��������! �� �������� �����: ";
    PrintCharsArr(chars_answer, n);
    
    free(chars_answer);
    return 0;
}