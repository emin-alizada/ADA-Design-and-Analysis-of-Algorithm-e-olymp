//
// Created by Emin Alizade on 02.12.21.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > g;
vector<int> used;
int n, m;

void dfsMatrix(int v) {
    cout << v << " ";
    used[v] = 1;

    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];

        if (used[to] == 0) {
            dfsMatrix(to);
        }
    }
}

int main() {
    cin >> n >> m;
    g.resize(n + 1);
    used.resize(n + 1);

    int a, b, v;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    cin >> v;

    dfsMatrix(v);

    return 0;
}
