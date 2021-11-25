//#include <bits/stdc++.h>
#include <iostream>
#include "stack"

using namespace std;

// 7311 - Insert Parentheses
int main() {
    string s;
    stack<int> myStack;

    cin >> s;

    int count = 0;
    for (char c: s) {
        if (c == '(') {
            myStack.push(1);
        } else if (c == ')') {
            if (myStack.empty()) {
                count++;
            } else {
                myStack.pop();
            }
        }
    }

    count += myStack.size();
    cout << count;

    return 0;
}
