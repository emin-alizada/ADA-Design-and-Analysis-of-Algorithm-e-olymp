#include <iostream>
#include "stack"

using namespace std;

int main() {
    string s;
    stack<int> myStack;

    cin >> s;

    bool flag = true;
    for (char c: s) {
        if (c == '(') {
            myStack.push(1);
        } else if (c == ')') {
            if (myStack.empty()) {
                flag = false;
                break;
            }
            myStack.pop();
        }
    }

    if (myStack.empty() && flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
