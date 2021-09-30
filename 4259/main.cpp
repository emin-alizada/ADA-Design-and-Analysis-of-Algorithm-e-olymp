#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, op, temp;
    stack<int> min;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> op;

        switch (op) {
            case 1: {
                cin >> temp;

                if (min.empty()) {
                    min.push(temp);
                } else {
                    if (min.top() > temp) {
                        min.push(temp);
                    } else {
                        min.push(min.top());
                    }
                }

                break;
            }
            case 2: {
                min.pop();
                break;
            }
            case 3: {
                cout <<  min.top() << endl ;
                break;
            }
        }
    }

    return 0;
}
