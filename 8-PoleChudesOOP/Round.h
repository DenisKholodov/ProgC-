#ifndef ROUND_H
#define ROUND_H

#include "Word.h"

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

#endif