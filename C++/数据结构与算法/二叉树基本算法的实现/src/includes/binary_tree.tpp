#pragma once
#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include <cstddef>

template<class T>
BinaryTree<T>::BinaryTree()
    : root(nullptr), count(0) {}

template<class T>
BinaryTree<T>::~BinaryTree() {
    clear(root);
}

template<class T>
void BinaryTree<T>::clear(Node<T> * node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
    if (count > 0) --count;
}

template<class T>
int BinaryTree<T>::height() {
    std::function<int(Node<T> *)> h = [&](Node<T> * n) -> int {
        if (!n) return 0;
        const int hl = h(n->left);
        const int hr = h(n->right);
        return 1 + (hl > hr ? hl : hr);
    };
    return h(root);
}

template<class T>
int BinaryTree<T>::size() const {
    return count;
}

template<class T>
bool BinaryTree<T>::isEmpty() {
    return root == nullptr;
}

template<class T>
Node<T> * BinaryTree<T>::parent(Node<T> * node) {
    if (!root || !node || node == root) return nullptr;
    Node<T> * cur = root;
    while (cur) {
        if (cur->left == node || cur->right == node) return cur;
        if (node->data < cur->data) cur = cur->left;
        else if (node->data > cur->data) cur = cur->right;
        else break;
    }
    return nullptr;
}

template<class T>
Node<T> * BinaryTree<T>::leftChild(Node<T> * node) {
    if (!node) return nullptr;
    return node->left;
}

template<class T>
Node<T> * BinaryTree<T>::rightChild(Node<T> * node) {
    if (!node) return nullptr;
    return node->right;
}

template<class T>
bool BinaryTree<T>::insert(const T& item) {
    auto* newNode = new Node<T>{item, nullptr, nullptr};
    if (!root) {
        root = newNode;
        count = 1;
        return true;
    }
    Node<T> * cur = root;
    Node<T> * parent = nullptr;
    while (cur) {
        parent = cur;
        if (item < cur->data) cur = cur->left;
        else if (item > cur->data) cur = cur->right;
        else {
            delete newNode;
            return false;
        }
    }
    if (item < parent->data) parent->left = newNode;
    else parent->right = newNode;
    count++;
    return true;
}

template<class T>
bool BinaryTree<T>::remove(const T& item) {
    Node<T> * cur = root;
    Node<T> * parent = nullptr;
    while (cur && cur->data != item) {
        parent = cur;
        if (item < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    if (!cur) return false;

    if (cur->left && cur->right) {
        Node<T> * succParent = cur;
        Node<T> * succ = cur->right;
        while (succ->left) {
            succParent = succ;
            succ = succ->left;
        }
        cur->data = succ->data;
        parent = succParent;
        cur = succ;
    }

    Node<T> * child = (cur->left) ? cur->left : cur->right;
    if (!parent) {
        root = child;
    } else if (parent->left == cur) {
        parent->left = child;
    } else {
        parent->right = child;
    }
    delete cur;
    --count;
    return true;
}

template<class T>
bool BinaryTree<T>::find(const T& item) {
    Node<T> * cur = root;
    while (cur) {
        if (item == cur->data) return true;
        if (item < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return false;
}

template<class T>
bool BinaryTree<T>::getData(T& item) {
    Node<T> * cur = root;
    while (cur) {
        if (item == cur->data) {
            item = cur->data;
            return true;
        }
        if (item < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return false;
}

template<class T>
Node<T> * BinaryTree<T>::getRoot() {
    return root;
}

template<class T>
Node<T> * BinaryTree<T>::swapTree() {
    std::function<void(Node<T> *)> swap = [&](Node<T> * node) {
        if (!node) return;
        std::swap(node->left, node->right);
        swap(node->left);
        swap(node->right);
    };
    swap(root);
    return root;
}

template<class T>
void BinaryTree<T>::build(const std::vector<T>& seq, const T& order, const T& null_marker) {
    clear(root);
    root = nullptr;
    count = 0;

    if (seq.empty()) return;

    if (order == T('P') || order == T('p')) {
        std::ptrdiff_t idx = 0;
        std::function<Node<T>*()> buildPre = [&]() -> Node<T>* {
            if (idx >= static_cast<std::ptrdiff_t>(seq.size())) return nullptr;
            const T &val = seq[static_cast<size_t>(idx++)];
            if (val == null_marker) return nullptr;
            auto* node = new Node<T>{val, nullptr, nullptr};
            count++;
            node->left = buildPre();
            node->right = buildPre();
            return node;
        };
        root = buildPre();
        return;
    }

    if (order == T('O') || order == T('o')) {
        std::ptrdiff_t idx = static_cast<std::ptrdiff_t>(seq.size()) - 1;
        std::function<Node<T>*()> buildPost = [&]() -> Node<T>* {
            if (idx < 0) return nullptr;
            const T val = seq[static_cast<size_t>(idx--)];
            if (val == null_marker) return nullptr;
            auto* node = new Node<T>{val, nullptr, nullptr};
            count++;
            node->right = buildPost();
            node->left = buildPost();
            return node;
        };
        root = buildPost();
        return;
    }

    if (order == T('L') || order == T('l')) {
        size_t i = 0;
        if (seq[i] == null_marker) return;
        root = new Node<T>{seq[i++], nullptr, nullptr};
        count++;
        std::queue<Node<T>*> q;
        q.push(root);
        while (!q.empty() && i < seq.size()) {
            Node<T>* cur = q.front(); q.pop();
            if (i < seq.size()) {
                const T &lv = seq[i++];
                if (lv != null_marker) {
                    cur->left = new Node<T>{lv, nullptr, nullptr};
                    count++;
                    q.push(cur->left);
                }
            }
            if (i < seq.size()) {
                const T &rv = seq[i++];
                if (rv != null_marker) {
                    cur->right = new Node<T>{rv, nullptr, nullptr};
                    count++;
                    q.push(cur->right);
                }
            }
        }
        return;
    }

    std::ptrdiff_t idx = 0;
    std::function<Node<T>*()> buildPre = [&]() -> Node<T>* {
        if (idx >= static_cast<std::ptrdiff_t>(seq.size())) return nullptr;
        const T &val = seq[static_cast<size_t>(idx++)];
        if (val == null_marker) return nullptr;
        auto* node = new Node<T>{val, nullptr, nullptr};
        count++;
        node->left = buildPre();
        node->right = buildPre();
        return node;
    };
    root = buildPre();
}

template<class T>
void PreOrder(Node<T> * node) {
    if (!node) return;
    std::cout << node->data << " ";
    PreOrder(node->left);
    PreOrder(node->right);
}

template<class T>
void InOrder(Node<T> * node) {
    if (!node) return;
    InOrder(node->left);
    std::cout << node->data << " ";
    InOrder(node->right);
}

template<class T>
void PostOrder(Node<T> * node) {
    if (!node) return;
    PostOrder(node->left);
    PostOrder(node->right);
    std::cout << node->data << " ";
}

template<class T>
void LevelOrder(Node<T> * node) {
    if (!node) return;
    std::queue<Node<T> *> q;
    q.push(node);
    while (!q.empty()) {
        Node<T> * cur = q.front(); q.pop();
        std::cout << cur->data << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}
