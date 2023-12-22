#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:

    int m_num;
    int m_denom;

    int common_divisor(int a, int b)
    { 
        std::cout << a << " !! " << b << " !&&&&&&!\n";
        if (a % b == 0) 
        {
            std::cout << b << " !&&&&&&!\n";
            return b;
        }
        else if (b % a == 0) {
            std::cout << b << " !&&&&&&!\n";
            return a;
        }
        else if (a > b){
            std::cout << a%b << " !&&&&&&!\n";
            return common_divisor(a%b, b);
        }
        return common_divisor(a, b%a);
    }

    void abbreviatedFraction(int &num, int &denom)
    {
        //std::cout << num << " !! " << denom << " !!!!!\n";
        //std::cout << "Constructor int int \n";
        int tmp = common_divisor(num, denom);
        num = num/tmp;
        denom = denom/tmp;
    }

public:
    Fraction();
    Fraction(float num);
    Fraction(int num, int denom);

    int getNum();
    int getDenom();
    void printFraction();
    void printDecimal();
    
    Fraction operator+ (const Fraction& fr)
    {
        //std::cout << m_num << "  !!  " << m_denom << "  !!  " << fr.m_num << "  !!  " << fr.m_denom << "  !!  \n";
        return Fraction(m_num * fr.m_denom + fr.m_num * m_denom, m_denom * fr.m_denom);
    }
    Fraction operator- (const Fraction& fr)
    {
        return Fraction(m_num * fr.m_denom - fr.m_num * m_denom, m_denom * fr.m_denom);
    }
    Fraction operator* (const Fraction& fr)
    {
        return Fraction(m_num * fr.m_num, m_denom * fr.m_denom); 
    }
};

#endif