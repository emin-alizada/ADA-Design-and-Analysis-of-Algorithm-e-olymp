#include <iostream>
#define MAX 101

using namespace std;

int g[MAX][MAX], used[MAX], d[MAX], f[MAX], t = 1, n, m;

void dfsMatrix(int v) {
    d[v] = t++;
    used[v] = 1;

    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0 && g[v][i] == 1) {
            dfsMatrix(i);
        }
    }
    f[v] = t++;
}

int main() {
    cin >> n >> m;

    int a, b, v;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;

        g[a][b] = 1;
        g[b][a] = 1;
    }

    cin >> v;

    dfsMatrix(v);

    for (int i = 1; i <= n; ++i) {
        cout << d[i] << " " << f[i] << endl;
    }

    return 0;
}