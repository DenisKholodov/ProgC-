#include <iostream>
#include <vector>
#include <string>
#include "Round.h"

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