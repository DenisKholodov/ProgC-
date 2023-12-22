#include <iostream>
#include "Fraction.h"

Fraction::Fraction(): m_num(1), m_denom(1) {}

Fraction::Fraction(float num)
{
    int denom = 100000000;
    int numINT;
    num *= denom;
    numINT = static_cast<int>(num);
    if (numINT == 0) std::cout << "Warning!!! Denominator = 0!!! Denominator has been changed to the default value (1).\n";
    if (num < 0) numINT *= -1;
    abbreviatedFraction(numINT, denom);
    if (num < 0) numINT *= -1;
    m_num = numINT;
    m_denom = denom;
}

Fraction::Fraction(int num, int denom)
{
    int sign = 1;
    try
    {
        if(denom != 0)
        {
            if (denom < 0 || num < 0) 
            {
                sign = -1;
            }
            if (denom < 0)
                denom *= -1;
            if (num < 0)
                num *= -1;
            
            abbreviatedFraction(num, denom);
            std::cout << "Constructor int int 2\n";

            /*if (denom < 0) 
            {
                denom *= -1;
                num *= -1;
            }*/
            //std::cout << "Warning! \n";
            m_num = num * sign;
            m_denom = denom;
            //std::cout << m_num << " !! " << m_denom << " !!!!!\n";
        }
        else
        {
            throw "Warning!!! Denominator = 0!!! Denominator has been changed to the default value (1).\n";
        }
    }
    catch(const char* exception)
    {
        std::cerr << "\n\nError:" << exception << '\n';
        m_num = num;
        m_denom = 1;
        std::cout << m_num << " !! " << m_denom << " !!!!!\n";
    }
}

int Fraction::getDenom()
{
    return m_denom;
}

int Fraction::getNum()
{
    return m_num;
}

void Fraction::printFraction()
{
    std::cout << m_num << "/" << m_denom;
};

void Fraction::printDecimal()
{
    std::cout << (double) m_num / m_denom;
};