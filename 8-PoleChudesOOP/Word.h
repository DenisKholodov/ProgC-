#ifndef WORD_H
#define WORD_H

#include <vector>

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

#endif