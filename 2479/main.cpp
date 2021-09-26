#include <iostream>
#include "stack"

using namespace std;

int main() {
    int t;
    string str;

    cin >> t;
    getline (cin,str);

    while (t--) {
        getline (cin,str);
        stack<char> myStack;

        if (str.length() == 0) {
            cout <<  "Yes" << endl ;
            continue;
        }

        bool flag = true;
        for (char c: str) {
            if (c == '(' || c== '[') {
                myStack.push(c);
            } else if (c == ')' || c == ']') {
                c = c == ')' ? '(' : '[';
                if (!myStack.empty() && myStack.top() == c) {
                    myStack.pop();
                } else {
                    flag = false;
                    break;
                }
            }
        }

        if (myStack.empty() && flag) {
            cout<< "Yes"<<endl;
        } else {
            cout <<  "No" << endl ;
        }
    }

    return 0;
}
