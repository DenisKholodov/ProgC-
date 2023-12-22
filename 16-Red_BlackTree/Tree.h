#ifndef TREE_H
#define TREE_H

#include "node.h"

template<class T>
class Tree
{
 private:
    Node<T>* m_root;
    int m_size;
    void print_tree(Node<T>*);
    void delete_tree(Node<T>*);

 public:
    Tree(T);
    ~Tree();
    void print();
    bool find(T);
    void insert(T);
    void erase(T);
};

#endif