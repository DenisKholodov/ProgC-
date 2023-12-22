#include <iostream>
#include <vector>
#include <string>
#include "Word.h"

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
