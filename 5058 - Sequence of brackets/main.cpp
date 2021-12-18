//
//  main.cpp
//  e-olymp Sequence of brackets (5058)
//
//  Created by Emin Alizade on 3/2/19.
//  Copyright © 2019 Emin Alizade. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

int main(int argc, const char *argv[]) {
    stack<int> s;
    string a;
    cin >> a;
    int length = a.length();
    char b;
    int x;
    int flag = 0;
    for (int i = 0; i < length; i++) {
        b = a[i];
        x = b;
        if (x == 40 || x == 123 || x == 91) {
            s.push(x);
        }

        if (x == 41 || x == 125 || x == 93) {
            if (!s.empty()) {
                if ((x - 1) == s.top() || (x - 2) == s.top()) {
                    s.pop();
                } else {
                    flag = 1;
                    break;
                }
            } else {
                flag = 1;
                break;
            }
        }
    }

    if (s.empty() && flag == 0) {
        cout << "yes";
    }
    if (!s.empty() || flag == 1) {
        cout << "no";
    }

    return 0;
}
