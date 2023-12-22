#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>

#include "Round.h"
#include "Word.h"

int main()
{
    system("chcp 1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");

    std::string word;
    std::cin >> word;
    Round round1(word);

    round1.showChars();
    std::cout << '\n' << '\n';
    do
    {
        try{
        char letter = ' ';
        std::cin >> letter;
        if (round1.checkLetterSaid(letter))
        {
            round1.showChars();
            throw "Такая буква уже была названа!\n";
        }
        else if (round1.checkLetterAnswer(letter))
        {
            round1.addSaidLetter(letter).showChars();
            throw "Такой буквы нет в слове!\n";
        }
        else 
        {
            std::cout << "Откройте букву!\n";
            round1.openLetter(letter).addSaidLetter(letter).showChars();
            std::cout << '\n' << '\n';
        }
        }
        catch(const char* exception)
        {
            std::cerr << "\n\nError:" << exception << '\n';
        }
    }while(round1.end());
    std::cout << "Вы отгадали слово: << ";
    round1.showChars();
    std::cout << " >>! Вы молодец!\n" << '\n';
    return 0;
}