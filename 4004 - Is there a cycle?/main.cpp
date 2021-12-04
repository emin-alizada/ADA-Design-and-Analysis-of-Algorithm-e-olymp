#include <iostream>
#define MAX 101

using namespace std;

int n, g[MAX][MAX], used[MAX];
bool flag = false;

void dfsMatrix(int v) {
    used[v] = 1;

    for (int i = 1; i <= n; ++i) {
        if (g[v][i] == 1) {
            if (used[i] == 0) {
                dfsMatrix(i);
            } else if (used[i] == 1) {
                flag = true;
            }
        }
    }
    used[v] = 2;
}

// Week 11: November 29 - December 5 - DFS (Depth First Search)
int main() {
    cin>>n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> g[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            dfsMatrix(i);
        }
    }

    cout << (flag ? 1 : 0);

    return 0;
}