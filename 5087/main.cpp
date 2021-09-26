#include <iostream>
#include "stack"

using namespace std;

int main() {
    int tests, operation, number;
    stack<int> myStack;

    cin >> tests;

    while (tests--) {
        cin >> operation;

        if (operation == 1) {
            cin >> number;
            myStack.push(number);
        } else if (operation == 2) {
            cout << myStack.top() << endl;
            myStack.pop();
        }
    }

    return 0;
}
