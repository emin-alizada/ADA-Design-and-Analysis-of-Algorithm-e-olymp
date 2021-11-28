#include <iostream>
#include "stack"
#include "map"

using namespace std;

int main() {
    int n, temp;
    stack<pair<int, int>> myStack;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> temp;

        if (myStack.empty()) {
            myStack.push(make_pair(temp, i));
            cout <<  -1 << " " ;
        } else {
            if ( myStack.top().first > temp ) {
                cout << myStack.top().second << " ";
                myStack.push(make_pair(temp, i));
            } else {
                while (!myStack.empty() && myStack.top().first <= temp) {
                    myStack.pop();
                }

                if (myStack.empty()) {
                    myStack.push(make_pair(temp, i));
                    cout <<  -1 << " " ;
                } else {
                    cout << myStack.top().second << " ";
                    myStack.push(make_pair(temp, i));
                }
            }
        }
    }

    return 0;
}
