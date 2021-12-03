#include <iostream>
#define MAX 1001

using namespace std;

int g[MAX][MAX], used[MAX], n, m;
bool flag = false;

void dfsMatrix(int v, int prev = -1) {
    used[v] = 1;

    for (int i = 1; i <= n; ++i) {
        if (i != prev  && g[v][i] == 1) {
            if (used[i] == 1) {
                flag = true;
            } else {
                dfsMatrix(i, v);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    int a, b;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;

        g[a][b] = 1;
        g[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i] == 0) {
            dfsMatrix(i);
        }
    }

    cout << (flag ? "YES" : "NO");

    return 0;
}