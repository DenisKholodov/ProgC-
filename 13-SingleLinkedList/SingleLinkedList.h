#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "Node.h"
#include "Istack.h"

class SingleLinkedList : public Istack
{
public:
    Node* head;
    Node* tail;

    SingleLinkedList();

    virtual void push(int element);
    virtual void pop();
    virtual void print();
    virtual void printErrorMassage();
};

SingleLinkedList::SingleLinkedList() : head(nullptr), tail(nullptr){}

void SingleLinkedList::printErrorMassage()
{
    Istack::printErrorMassage();
}

void SingleLinkedList::push(int element) 
{
    Node* p = new Node(element);
    if (head == NULL) 
    {
        head = p;
    }
    if(tail != NULL)
    {
        tail->next = p;
    }
    tail = p;
}

void SingleLinkedList::pop() 
{
    int temp;
    if (tail == NULL)
    {
        SingleLinkedList::printErrorMassage(); 
    }
    if (head == tail) 
    {
        temp = tail->val;
        delete tail;
        head = tail = NULL;
    }

    Node* p = head;
    while(p->next != tail)
    {
        p = p->next;
    }

    p->next = NULL;
    temp = tail->val;
    delete tail;
    tail = p;
}

void SingleLinkedList::print() 
{
    if (head == NULL){
        std::cout << "The list is empty!";
    }
    Node* p = head;
    while (p) 
    { 
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << "\n";
}

#endif