#include <iostream>
#include "stack"

using namespace std;

int main() {
    string str;
    stack<int> myStack;

    int op1, op2;


    while (cin >> str) {
        if (str == "*") {
            op2 = myStack.top();
            myStack.pop();
            op1 = myStack.top();
            myStack.pop();
            myStack.push(op1 * op2);
        } else if (str == "/") {
            op2 = myStack.top();
            myStack.pop();
            op1 = myStack.top();
            myStack.pop();
            myStack.push(op1 / op2);
        } else if (str == "+") {
            op2 = myStack.top();
            myStack.pop();
            op1 = myStack.top();
            myStack.pop();
            myStack.push(op1 + op2);
        } else if (str == "-") {
            op2 = myStack.top();
            myStack.pop();
            op1 = myStack.top();
            myStack.pop();
            myStack.push(op1 - op2);
        } else {
            int temp = stoi(str);
            myStack.push(temp);
        }
    }

    cout << myStack.top();

    return 0;
}
