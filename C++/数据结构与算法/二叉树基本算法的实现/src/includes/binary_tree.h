#ifndef C_BINARY_TREE_H
#define C_BINARY_TREE_H
#include <vector>

template <class T>
struct Node {
    T data;
    Node* left;
    Node* right;
};

template <class T>
class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();

    int height();
    [[nodiscard]] int size() const;
    bool isEmpty();
    Node<T> * parent(Node<T> * node);
    static Node<T> * leftChild(Node<T> * node);
    static Node<T> * rightChild(Node<T> * node);
    bool insert(const T& item);
    bool remove(const T& item);
    bool find(const T& item);
    bool getData(T& item);
    Node<T> * getRoot();
    Node<T> * swapTree();

    void build(const std::vector<T>& seq, const T& order, const T& null_marker);

    template<class U> friend void PreOrder(Node<U>* node);
    template<class U> friend void InOrder(Node<U>* node);
    template<class U> friend void PostOrder(Node<U>* node);
    template<class U> friend void LevelOrder(Node<U>* node);

private:
    Node<T> * root;
    int count;

    void clear(Node<T> * node);
};

template<class T>
void PreOrder(Node<T> * node);

template<class T>
void InOrder(Node<T> * node);

template<class T>
void PostOrder(Node<T> * node);

template<class T>
void LevelOrder(Node<T> * node);

#include "binary_tree.tpp"

#endif //C_BINARY_TREE_H
