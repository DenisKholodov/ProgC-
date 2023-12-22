#ifndef NODE_H
#define NODE_H

template<class KeyType>
class Node
{
public:
    KeyType m_key; /*m_key - ключевое поле */
    Node<KeyType> *m_left; /* left – указатель на левого потомка */
    Node<KeyType> *m_right; /* right - указатель на правого потомка */
    Node(KeyType value): m_key(value), m_left(nullptr), m_right(nullptr){};
};

#endif