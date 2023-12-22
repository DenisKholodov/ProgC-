#include "Istack3level"

void Istack::printErrorMassage()
{
    std::cout << "You cannot delete element.\n";
};

class ContainVector: public Istack
{
public:

    std::vector<int> m_elements;

    virtual void pop()
    {
    if (!m_elements.empty()) {
        int temp = m_elements.back();
        m_elements.pop_back();
    }
    ContainVector::printErrorMassage();
    }

    virtual void print()
    {
        if (m_elements.empty())
        {
            std::cout << "Empty.\n";
            return;
        }
        for (const auto &elem : m_elements)
        {
            std::cout << elem << " ";
        }
        std::cout << '\n';
    }

    virtual void printErrorMassage()
    {
        Istack::printErrorMassage();
    }
};