//
//  main.cpp
//  e-olymp Mobile Phone (930)
//
//  Created by Emin Alizade on 3/2/19.
//  Copyright © 2019 Emin Alizade. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    string ss;
    while (cin >> ss) { //24 test case soderjit probel iz za etoqo delaem tak
        s += ss;
    }
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = -1;
    }
    int x;
    int length = s.length();
    for (int i = 0; i < length; i++) {
        if (s[i] >= 48 && s[i] <= 57) {
            x = s[i] - 48;
            a[x] = 1;
        }
    }
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] < 0) {
            count++;
        }
    }
    cout << count << endl;
    for (int i = 0; i < 10; i++) {
        if (a[i] < 0) {
            cout << i << " ";
        }
    }
    return 0;
}
