#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <locale.h>

class Word
{
private:
    const std::string m_word;
    std::vector<char> m_arrEnigma;

public:
    Word(std::string word);

    Word& showChars();

    std::string getAnswer();

    std::vector<char> &getArrEnigma();

    int getQuantityEnigma();

};

Word::Word(std::string word = "Поле чудес") : m_word(word)
{
    for (const auto &letter : word)
    {
        if (letter < 0)
        {
            m_arrEnigma.push_back('_');
        }
        else
        {
            m_arrEnigma.push_back(letter);
        }
    }
}

Word& Word::showChars()
{
    for (const auto &letter : m_arrEnigma)
    {
        std::cout << letter;
    }
    return *this;   
}

std::string Word::getAnswer() { return m_word; }

std::vector<char>& Word::getArrEnigma() { return m_arrEnigma; }

int Word::getQuantityEnigma() { return m_word.size(); }

class Round
{
private:
    Word m_slovo;
    std::vector<char> m_arrSaid;

public:
    Round(const std::string &word);

    std::string getAnswer();

    void showChars();

    bool end();

    bool checkLetterAnswer (char letter);
    bool checkLetterSaid (char letter);

    Round& addSaidLetter (char letter);
    Round& openLetter(char letter);
};


Round::Round(const std::string &word) : m_slovo(word) {}

std::string Round::getAnswer() { return m_slovo.getAnswer(); }

void Round::showChars() { m_slovo.showChars(); }

bool Round::end()
{
    for (auto const &letter : m_slovo.getArrEnigma())
    {
        if (letter == '_') return 1;
    }
    return 0;
}

bool Round::checkLetterAnswer (char letter)
{
    for (const auto &buka : m_slovo.getAnswer())
    {
        if (buka == letter) return 0;
    }
    return 1;
}

bool Round::checkLetterSaid (char letter)
{
    for (const auto &buka : m_arrSaid)
    {
        if (buka == letter) return 1;
    }
    return 0;
}

Round& Round::addSaidLetter (char letter)
{
    m_arrSaid.push_back(letter);
    return *this;
}

Round& Round::openLetter(char letter)
{        
    auto iter = m_slovo.getAnswer().begin();
    for (int k = 0; k < m_slovo.getQuantityEnigma(); k++)
    {
        if (*iter == letter)
        {
            m_slovo.getArrEnigma().at(k) = letter;
        }
        iter++;
    }
    return *this;
}

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
        char letter = ' ';
        std::cin >> letter;
        if (round1.checkLetterSaid(letter))
        {
            std::cout << "Такая буква уже была названа!\n";
            round1.showChars();
            std::cout << '\n' << '\n';
        }
        else if (round1.checkLetterAnswer(letter))
        {
            std::cout << "Такой буквы нет в слове!\n";
            round1.addSaidLetter(letter).showChars();
            std::cout << '\n' << '\n';
        }
        else 
        {
            std::cout << "Откройте букву!\n";
            round1.openLetter(letter).addSaidLetter(letter).showChars();
            std::cout << '\n' << '\n';
        }
    }while(round1.end());
    std::cout << "Вы отгадали слово: << ";
    round1.showChars();
    std::cout << " >>! Вы молодец!\n" << '\n';
    return 0;
}