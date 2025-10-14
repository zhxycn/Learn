#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct symbol {
    char s;
    int line;
    int col;
};

class Stack {
public:
    vector<symbol> stack;

    [[nodiscard]] bool empty() const {
        return stack.empty();
    }

    [[nodiscard]] char top() const {
        if (stack.empty()) {
            return '\0';
        }
        return stack.back().s;
    }

    void pop() {
        stack.pop_back();
    }

    void push(const char symbol, const int line, const int col) {
        stack.push_back({symbol, line, col});
    }
};

int main() {
    while (true) {
        string s;
        Stack stack;
        int line = 0;

        do {
            line++;
            getline(cin, s);

            if (s == "@") {
                cout << "Exit..." << endl;
                return 0;
            }

            for (int i = 0; i < s.length(); i++) {
                if (stack.top() == '{' && s.at(i) == '}' ||
                    stack.top() == '[' && s.at(i) == ']' ||
                    stack.top() == '(' && s.at(i) == ')') {
                    stack.pop();
                    continue;
                    }

                if (s.at(i) == '{' || s.at(i) == '[' || s.at(i) == '(' ||
                    s.at(i) == '}' || s.at(i) == ']' || s.at(i) == ')') {
                    stack.push(s.at(i), line, i + 1);
                    }
            }
        } while (s.back() != '#');

        if (stack.empty()) {
            cout << "All symbols match" << endl;
        } else {
            for (const auto& sym : stack.stack) {
                cout << "Unmatched '" << sym.s << "' at line " << sym.line << ", col " << sym.col << endl;
            }
        }

        cout << endl;
    }
}
