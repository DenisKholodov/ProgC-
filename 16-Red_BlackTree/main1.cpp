#include <iostream>
#include <vector>

template<class KeyType>
class Node
{
public:
    KeyType m_key; 
    Node<KeyType> *m_left; 
    Node<KeyType> *m_right; 
    Node(KeyType value): m_key(value), m_left(nullptr), m_right(nullptr){};
};

/*
class RedBlackTree:
{
public:
    Node *root;
    Node *p, *t, *tp; 
    p – выделения и освобождения памяти узлов дерева;
    t – поиска узла в дереве;
    tp – определения места добавления узла в дерево. 

    insert(int value);
    deleteLeftest();


};
*/

template<class T>
class Tree
{
 private:
    Node<T>* m_root;
    int m_size;
    void print_tree(Node<T>*);
    void delete_tree(Node<T>*);
    //void left_rotate(RBTNode<T>* &, RBTNode<T>*);

 public:
    Tree(T);
    ~Tree();
    void print();
    bool find(T);
    void insert(T);
    void erase(T);
};

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
/*
template<class T>		
void Tree<T>::left_rotate(RBTNode<T>* &root, RBTNode<T>* x) 
{
	Node<T>* y = x->m_right;

	x->m_right = y->left;
	if (y->left != NULL)
		y->left->parent = x;

	y->parent = x->parent;
	if (x->parent == NULL)
		root = y;  
	else {
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->m_right = y;
	}
	y->left = x;
	x->parent = y;
};*/

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

int main()
{
	std::vector<int> nums{10, 40, 30, 60, 90, 70, 20, 50, 80, 100};
	Tree<int> tree{1};
	for (auto num : nums)
		tree.insert(num);
    tree.print();
    std::cout << '\n';

	std::vector<double> nums2{11.23, 41.1, 31.765, 61.76, 97.2, 77.2, 27.2, 57.2, 87.2, 17.20};
	Tree<double> tree2{1.};
	for (auto num : nums2)
		tree2.insert(num);
    tree2.print();
    std::cout << '\n';
    tree2.erase(11.23);
    tree2.print();

    return 0;
}