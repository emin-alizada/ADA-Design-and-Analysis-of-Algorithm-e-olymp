//
//  main.cpp
//  e-olymp Number of operations(901)
//
//  Created by Emin Alizade on 3/3/19.
//  Copyright © 2019 Emin Alizade. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
    string s;
    cin >> s;
    int x;
    int count = 0;
    int length = s.length();
    for (int i = 0; i < length; i++) {
        x = s[i];
        if (x == 42 || x == 43 || x == 45) {
            count++;
        }
    }
    if (s[0] == 42 || s[0] == 43 || s[0] == 45) {
        cout << count - 1;
    } else {
        cout << count;
    }

    return 0;
}