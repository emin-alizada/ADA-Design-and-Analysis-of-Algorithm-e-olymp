//
//  main.cpp
//  e-olymp Shift the elements to the right (922)
//
//  Created by Emin Alizade on 3/2/19.
//  Copyright © 2019 Emin Alizade. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    a[1] = b[n];
    for (int i = 1; i < n; i++) {
        a[i + 1] = b[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
