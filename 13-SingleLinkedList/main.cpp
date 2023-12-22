#include "SingleLinkedList.h"


int main()
{
    SingleLinkedList examle;
    examle.push(5);
    examle.push(7);
    examle.push(9);
    examle.print();

    examle.pop();
    examle.print();
    examle.pop();
    examle.print();
    return 0;
}