//
// Created by Emin Alizade on 03.01.22.
//

#include <iostream>
#define MAX 101

using namespace std;

int n, g[MAX][MAX], used[MAX], s, counter = 0;

void dfsMatrix(int v) {
    used[v] = 1;
    counter++;

    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0 && g[v][i] == 1) {
            dfsMatrix(i);
        }
    }
}

int main() {
    cin>>n >> s;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> g[i][j];
        }
    }

    dfsMatrix(s);

    cout << counter;

    return 0;
}