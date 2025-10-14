#include <any>
#include <iostream>
#include <stdexcept>
#include <string>
#include <typeinfo>
using namespace std;

struct node {
    any data;
    mutable node *next{};
};

class LinkList {
protected:
    node *head;

public:
    LinkList() {
        head = new node;
        head->next = nullptr;
    }

    ~LinkList() {
        const node *p = head;

        while (p) {
            const node *q = p->next;
            delete p;
            p = q;
        }
    }

    void push_back(const any &value) const {
        const auto new_node = new node;
        new_node->data = value;
        new_node->next = nullptr;

        const node *p = head;

        while (p->next) {
            p = p->next;
        }

        p->next = new_node;
    }

    [[nodiscard]] any get_item(const int index) const {
        const node *p = head;
        int count = 0;

        while (p->next) {
            p = p->next;
            if (count == index) {
                return p->data;
            }
            count++;
        }

        throw out_of_range("Index out of range");
    }

    void reverse() const {
        node *p = head->next;
        head->next = nullptr;
        while (p) {
            node *q = p->next;
            p->next = head->next;
            head->next = p;
            p = q;
        }
    }

    friend void merge(const LinkList &list_a, const LinkList &list_b);

    friend void print_list(const LinkList &list, bool reverse);
};

class BigNum : public LinkList{
public:
    [[nodiscard]] string to_string() const {
        string result;
        const node *p = head->next;

        while (p) {
            result += std::to_string(any_cast<int>(p->data));
            p = p->next;
        }

        return result;
    }

    friend BigNum factorial(const int &n);
};

ostream &operator<<(ostream &os, const any &object) {
    if (object.type() == typeid(int)) {
        os << any_cast<int>(object);
    } else if (object.type() == typeid(float)) {
        os << any_cast<float>(object);
    } else if (object.type() == typeid(double)) {
        os << any_cast<double>(object);
    } else if (object.type() == typeid(char)) {
        os << any_cast<char>(object);
    } else if (object.type() == typeid(string)) {
        os << any_cast<string>(object);
    } else if (object.type() == typeid(const char *)) {
        os << any_cast<const char *>(object);
    } else {
        os << "[unsupported object]";
    }

    return os;
}

void merge(const LinkList &list_a, const LinkList &list_b) {
    const node *p = list_a.head;

    while (p->next) {
        p = p->next;
    }

    p->next = list_b.head->next;
}

void print_list(const LinkList &list, const bool reverse = false) {
    if (reverse) {
        const LinkList &temp = list;
        temp.reverse();
        print_list(temp, false);
        return;
    }

    const node *p = list.head;

    while (p->next) {
        p = p->next;
        cout << p->data;
        if (p->next) {
            cout << " -> ";
        }
    }

    cout << endl;
}

BigNum factorial(const int &n) {
    BigNum list;
    list.push_back(1);

    for (int i = 2; i <= n; ++i) {
        int carry = 0;
        node *p = list.head->next;

        while (p) {
            const int product = any_cast<int>(p->data) * i + carry;
            p->data = product % 10;
            carry = product / 10;
            p = p->next;
        }

        while (carry) {
            list.push_back(carry % 10);
            carry /= 10;
        }
    }

    list.reverse();
    return list;
}

int main() {
    const LinkList list_a, list_b;

    // TEST CODE HERE
    list_a.push_back(111);
    list_a.push_back(222);
    list_a.push_back('a');

    list_b.push_back(3.14);
    list_b.push_back("Hello World!");

    cout << "Items in List A: ";
    print_list(list_a);
    cout << "Items in List A (Reversed): ";
    print_list(list_a, true);
    cout << "Items in List B: ";
    print_list(list_b);

    merge(list_a, list_b);
    cout << "Items in List A after merging List B: ";
    print_list(list_a, false);

    cout << "100! = " << factorial(100).to_string() << endl;

    return 0;
}
