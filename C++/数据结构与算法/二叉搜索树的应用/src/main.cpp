#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

ListNode* build_list(const vector<int>& data) {
    ListNode dummy{0, nullptr};
    ListNode* tail = &dummy;
    for (int v : data) {
        tail->next = new ListNode{v, nullptr};
        tail = tail->next;
    }
    return dummy.next;
}

void print_list(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int list_length(ListNode* head) {
    int n = 0;
    while (head) { ++n; head = head->next; }
    return n;
}

// Method 1: find mid node with slow/fast pointers, recursively build subtrees
TreeNode* sorted_list_to_bst_mid(ListNode* head, ListNode* tail) {
    if (head == tail) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != tail && fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    }
    auto* root = new TreeNode{slow->val, nullptr, nullptr};
    root->left = sorted_list_to_bst_mid(head, slow);
    root->right = sorted_list_to_bst_mid(slow->next, tail);
    return root;
}

// Method 2: simulate inorder traversal, build bottom-up in O(n)
TreeNode* sorted_list_to_bst_inorder(ListNode*& cur, int n) {
    if (n <= 0) return nullptr;
    TreeNode* left = sorted_list_to_bst_inorder(cur, n / 2);
    auto* root = new TreeNode{cur->val, nullptr, nullptr};
    cur = cur->next;
    root->left = left;
    root->right = sorted_list_to_bst_inorder(cur, n - n / 2 - 1);
    return root;
}

void pre_order(TreeNode* node) {
    if (!node) return;
    cout << node->val << " ";
    pre_order(node->left);
    pre_order(node->right);
}

void in_order(TreeNode* node) {
    if (!node) return;
    in_order(node->left);
    cout << node->val << " ";
    in_order(node->right);
}

void post_order(TreeNode* node) {
    if (!node) return;
    post_order(node->left);
    post_order(node->right);
    cout << node->val << " ";
}

int tree_height(TreeNode* node) {
    if (!node) return 0;
    int lh = tree_height(node->left);
    int rh = tree_height(node->right);
    return 1 + (lh > rh ? lh : rh);
}

bool is_balanced(TreeNode* node) {
    if (!node) return true;
    int diff = tree_height(node->left) - tree_height(node->right);
    if (diff < -1 || diff > 1) return false;
    return is_balanced(node->left) && is_balanced(node->right);
}

void free_tree(TreeNode* node) {
    if (!node) return;
    free_tree(node->left);
    free_tree(node->right);
    delete node;
}

void free_list(ListNode* head) {
    while (head) {
        ListNode* t = head->next;
        delete head;
        head = t;
    }
}

int main() {
    string line;
    cout << "Please enter a sorted list (comma separated, e.g. 10,20,30,40,50,60,70):" << endl;
    getline(cin, line);

    vector<int> data;
    istringstream iss(line);
    string token;
    while (getline(iss, token, ',')) {
        data.push_back(stoi(token));
    }

    ListNode* list1 = build_list(data);
    ListNode* list2 = build_list(data);

    cout << endl << "Linked list: ";
    print_list(list1);

    cout << endl << "=== Method 1: Slow/Fast Pointer ===" << endl;
    TreeNode* root1 = sorted_list_to_bst_mid(list1, nullptr);
    cout << "\tHeight:\t\t" << tree_height(root1) << endl;
    cout << "\tBalanced:\t" << (is_balanced(root1) ? "Yes" : "No") << endl;
    cout << "\tPreOrder:\t"; pre_order(root1); cout << endl;
    cout << "\tInOrder:\t"; in_order(root1); cout << endl;
    cout << "\tPostOrder:\t"; post_order(root1); cout << endl;

    cout << endl << "=== Method 2: Inorder Simulation ===" << endl;
    int n = list_length(list2);
    ListNode* cur = list2;
    TreeNode* root2 = sorted_list_to_bst_inorder(cur, n);
    cout << "\tHeight:\t\t" << tree_height(root2) << endl;
    cout << "\tBalanced:\t" << (is_balanced(root2) ? "Yes" : "No") << endl;
    cout << "\tPreOrder:\t"; pre_order(root2); cout << endl;
    cout << "\tInOrder:\t"; in_order(root2); cout << endl;
    cout << "\tPostOrder:\t"; post_order(root2); cout << endl;

    free_tree(root1);
    free_tree(root2);
    free_list(list1);
    free_list(list2);

    return 0;
}
