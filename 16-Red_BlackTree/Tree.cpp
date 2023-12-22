#ifndef TREE_H
#define TREE_H

#include "Tree.h"

template<class T>
Tree<T>::Tree(T key)
{
    m_root = new Node<T>(key);
    m_size = 1;
}

template<class T>
Tree<T>::~Tree()
{
    delete_tree(m_root);
}

template<class T>
void Tree<T>::delete_tree(Node<T>* tmp_node)
{
    if (tmp_node)
    {
        delete_tree(tmp_node->m_left);
        delete_tree(tmp_node->m_right);
        delete tmp_node;
    }
}

template<class T>
void Tree<T>::print_tree(Node<T>* tmp_node)
{
    if (tmp_node) // Проверка на ненулевой указатель
    {
        print_tree(tmp_node->m_left);
        std::cout << tmp_node->m_key << " ";
        print_tree(tmp_node->m_right);
    }
}

template<class T>
void Tree<T>::print()
{
    print_tree(m_root);
    std::cout << std::endl;
}

template<class T>
bool Tree<T>::find(T key)
{
    Node<T>* tmp_node = m_root;
    while (tmp_node && tmp_node->m_key != key)
    {
        if (tmp_node->m_key > key)
            tmp_node = tmp_node->m_left;
        else
            tmp_node = tmp_node->m_right;
    }
    return tmp_node != NULL;
}

template<class T>
void Tree<T>::insert(T key)
{
    Node<T>* tmp_node = m_root;
    while (tmp_node && tmp_node->m_key != key)
    {
        if (tmp_node->m_key > key && tmp_node->m_left == NULL)
        {
            tmp_node->m_left = new Node<T>(key);
            m_size++;
            return;
        }
        if (tmp_node->m_key < key && tmp_node->m_right == NULL)
        {
            tmp_node->m_right = new Node<T>(key);
            m_size++;
            return;
        }
        if (tmp_node->m_key > key)
            tmp_node = tmp_node->m_left;
        else
            tmp_node = tmp_node->m_right;
    }
}

template<class T>
void Tree<T>::erase(T key)
{
    Node<T>* tmp_node = m_root;
    Node<T>* parent = NULL;
    while (tmp_node && tmp_node->m_key != key)
    {
        parent = tmp_node;
        if (tmp_node->m_key > key)
        {
            tmp_node = tmp_node->m_left;
        }
        else
        {
            tmp_node = tmp_node->m_right;
        }
    }
    if (!tmp_node)
        return;
    if (tmp_node->m_left == NULL)
    {
        // Вместо tmp_node подвешивается его правое поддерево
        if (parent && parent->m_left == tmp_node)
            parent->m_left = tmp_node->m_right;
        if (parent && parent->m_right == tmp_node)
            parent->m_right = tmp_node->m_right;
        m_size--;
        delete tmp_node;
        return;
    }
    if (tmp_node->m_right == NULL)
    {
        // Вместо tmp_node подвешивается его левое поддерево
        if (parent && parent->m_left == tmp_node)
            parent->m_left = tmp_node->m_left;
        if (parent && parent->m_right == tmp_node)
            parent->m_right = tmp_node->m_left;
        m_size--;
        delete tmp_node;
        return;
    }
    // У элемента есть два потомка, тогда на место элемента поставим
    // наименьший элемент из его правого поддерева
    Node<T>* replace = tmp_node->m_right;
    while (replace->m_left)
        replace = replace->m_left;
    int replace_value = replace->m_key;
    erase(replace_value);
    tmp_node->m_key = replace_value;
}



#endif