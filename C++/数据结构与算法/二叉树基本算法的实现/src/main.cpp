#include "includes/binary_tree.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    BinaryTree<char> tree;

    string input;
    char order;

    cout << "Please enter the order of the node to be inserted:" << endl;
    cin >> input;

    cout << endl << "Please enter the traversal order (P: PreOrder, O: PostOrder, L: LevelOrder):" << endl;
    cin >> order;

    const vector<char> seq(input.begin(), input.end());
    tree.build(seq, order, '#');

    cout << endl << "Tree properties:" << endl;
    cout << "\tSize:\t" << tree.size() << endl;
    cout << "\tHeight:\t" << tree.height() << endl;

    cout << endl << "Traversals before swapping:" << endl;
    cout << "\tPreOrder:\t"; PreOrder<char>(tree.getRoot()); cout << endl;
    cout << "\tInOrder:\t"; InOrder<char>(tree.getRoot()); cout << endl;
    cout << "\tPostOrder:\t"; PostOrder<char>(tree.getRoot()); cout << endl;
    cout << "\tLevelOrder:\t"; LevelOrder<char>(tree.getRoot()); cout << endl;

    cout << endl << "After swapping left and right subtrees:" << endl;
    tree.swapTree();

    cout << "\tPreOrder:\t"; PreOrder<char>(tree.getRoot()); cout << endl;
    cout << "\tInOrder:\t"; InOrder<char>(tree.getRoot()); cout << endl;
    cout << "\tPostOrder:\t"; PostOrder<char>(tree.getRoot()); cout << endl;
    cout << "\tLevelOrder:\t"; LevelOrder<char>(tree.getRoot()); cout << endl;

    return 0;
}
