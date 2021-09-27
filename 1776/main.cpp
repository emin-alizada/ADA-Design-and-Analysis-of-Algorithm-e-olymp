#include <iostream>
#include <stack>
#include <string>

using namespace std;
int x, n, cur, ok, i;
stack<int> s;

int main() {
//    Reading first n
    while (scanf("%d", &n), n) {
//        reading first number of train
        while (scanf("%d", &x), x) {
            cur = 1;
            ok = 1;

//            emptying stack if it has elements
            while (!s.empty()){
                s.pop();
            }

//            Will read n-1 times numbers, since we have read first number of train in 13 line
            for (i = 1; i < n; i++) {
//                After reading first number creating stack up to that number
                for (; cur <= x; cur++){
                    s.push(cur);
                }

//                if at any moment x isn't the number that
                if (s.top() != x)
                    ok = 0;
                else
                    s.pop();
                cin >> x;
            }

            if (ok == 1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;

        }
        cout << endl;
    }
}