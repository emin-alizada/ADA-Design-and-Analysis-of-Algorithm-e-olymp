#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> stack1;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "push") {
            int n;
            cin >> n;
            stack1.push(n);
            cout << "ok" << endl;
        }

        if (cmd == "pop") {
            cout << stack1.top() << endl;
            stack1.pop();
        }

        if (cmd == "back") {
            cout << stack1.top() << endl;
        }

        if (cmd == "size") {
            cout << stack1.size() << endl;
        }

        if (cmd == "clear") {
            while (!stack1.empty()) {
                stack1.pop();
            }
            cout << "ok" << endl;
        }

        if (cmd == "exit") {
            cout << "bye" << endl;
            break;
        }
    }

    return 0;
}
