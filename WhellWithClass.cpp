#include <iostream>
#include <string>
#include <array>
#include <windows.h>
#include <locale.h>

class Player
{
private:
    std::string m_name;
public:
    char sayLetter(char a);
};

class Word
{
private:
    std::string m_word;
    char* m_arrEnigma;
    int m_quantityChar;

public:
    Word(std::string word = "приветпривет")
        : m_word(word)
        {
            m_quantityChar = 0;
            for (auto iter = word.begin(); iter != word.end(); iter++)
            {
                m_quantityChar++;
            }
            
            m_arrEnigma = (char *) malloc(m_quantityChar * sizeof (char));

            auto iter = word.begin();
            for (int i = 0; iter != word.end(); i++)
            {
                if (*iter < 0)
                {
                    m_arrEnigma[i] = '_';
                }
                else
                {
                    m_arrEnigma[i] = *iter;
                }
                iter++;
            }
            //std::cout << m_word;
        }

    void showChars()
    {
        for(int i = 0; i < m_quantityChar; i++)
        {
            std::cout << m_arrEnigma[i];
        }
        std::cout << '\n' << '\n';
    }
    std::string getAnswer() { return m_word; }
    char* getArrEnigma(){ return m_arrEnigma; }
    int getQuantityEnigma() { return m_quantityChar; }

};

class Round
{
private:
    Word m_slovo;
    char* m_arrSaid;

public:

    Round(const std::string &word)
        : m_slovo(word)
    {
    }

    std::string getAnswer() { return m_slovo.getAnswer(); }
    void showChars() { m_slovo.showChars(); }

    bool end()
    {
        for(int i = 0; i < m_slovo.getQuantityEnigma(); i++)
        {
            if(m_slovo.getArrEnigma()[i] == '_') return 1;
        }
        return 0;
    }
    bool checkLetter (char letter)
    {
        auto iter = m_slovo.getAnswer().begin();
        for (; iter != m_slovo.getAnswer().end(); iter++)
        {
            if (*iter == letter) return 0;
        }
        return 1;
    }
    void openLetter(char letter)
    {
        auto iter = m_slovo.getAnswer().begin();
        for (int k = 0; k < m_slovo.getQuantityEnigma(); k++)
        {
            if (*iter == letter)
            {
                m_slovo.getArrEnigma()[k] = letter;
            }
            iter++;
        }
    }

};

int main()
{
    system("chcp 1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");

    std::string word;
    std::cin >> word;
    Round round1(word);

    std::cout << round1.getAnswer() << '\n';
    round1.showChars();
    do
    {
        char letter = ' ';
        std::cin >> letter;
        if (round1.checkLetter(letter))
        {
            std::cout << "Такой буквы нет в слове!\n";
            round1.showChars();
        }
        else 
        {
            round1.openLetter(letter);
            round1.showChars();
        }
        
    }while(round1.end());
    return 0;
}