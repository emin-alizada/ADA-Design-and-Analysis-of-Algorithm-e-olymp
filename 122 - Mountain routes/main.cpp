#include <iostream>

using namespace std;

#define MAX 51
int g[MAX][MAX], used[MAX];

int n, k, a, b, d;
int res;

void dfs(int v, int depth) {
    if (depth > d) {
        return;
    }

    if (v == b) {
        res++;
        return;
    }

    used[v] = 1;

    for (int i = 1; i <= n; i++) {
        if (g[v][i] && !used[i]) {
            dfs(i, depth + 1);
        }
    }

    used[v] = 0;
}

int main() {
    cin >> n >> k >> a >> b >> d;

    memset(g, 0, sizeof(g));
    memset(used, 0, sizeof(used));

    for (int i = 0; i < k; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        g[a1][a2] = 1;
    }

    res = 0;
    dfs(a, 0);

    cout << res;

    return 0;
}
