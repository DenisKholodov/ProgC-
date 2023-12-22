#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int val;
    Node* next;
    Node(int value): val(value), next(nullptr){};
};

#endif