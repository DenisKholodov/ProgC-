#include <iostream>
#include <string>
#include <array>
#include <windows.h>
#include <locale.h>

class Player
{
private:
    std:string m_name;

public:
    char getLetter(char a);
}

class Word
{
private:
    std::string m_word;
    char* m_arrEnigma;
    int m_quantityChar;

public:
    void showChars()
    {
        for(int i = 0; i < m_quantityChar; i++)
        {
            std::cout << m_arrEnigma[i];
        }
        std::cout << '\n' << '\n';
    }
    std::string getAnswer() { return m_word; }
    void setWord(std::string word) { m_word = word; }
    char* getArrEnigma(){ return m_arrEnigma; }
    int getQuantityEnigma() { return m_quantityChar; }
}

class Round()
{
privat:
    Word m_slovo;
    char* m_arrSaid;
privat:
    void setEnigma(std::string quest) { m_slovo.setWord(quest); }
    bool end(char* m_slovo.getArrEnigma, int m_slovo.getQuantityEnigma)
    {
        for(int i = 0; i < n; i++)
        {
            if(arr_ch[i] == '_') return 1;
        }
        return 0;
    }
}

int main()
{
    
    return 0;
}