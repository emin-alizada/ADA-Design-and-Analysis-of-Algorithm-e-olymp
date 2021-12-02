#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

//1871 - Squirrel and bamboo

int main() {
    int n, val;

    cin >> n;

    stack<int> s;
    s.push(0);

    while (n--)
    {
        cin >> val;
        if (val > 0) {
            s.push(max(val, s.top()));
        }
        else {
            s.pop();
            cout << s.top() << endl;
        }
    }
    return 0;
}