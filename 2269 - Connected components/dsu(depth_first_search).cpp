//
// Created by Emin Alizade on 03.12.21.
//

#include <iostream>
#define MAX 101

using namespace std;

int n, g[MAX][MAX], used[MAX];

void dfsMatrix(int v) {
    used[v] = 1;

    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0 && g[v][i] == 1) {
            dfsMatrix(i);
        }
    }
}

// Week 11: November 29 - December 5 - DFS (Depth First Search)
int main() {
    cin>>n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> g[i][j];
        }
    }

    int count = 0;

    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            count++;
            dfsMatrix(i);
        }
    }

    cout << count;

    return 0;
}