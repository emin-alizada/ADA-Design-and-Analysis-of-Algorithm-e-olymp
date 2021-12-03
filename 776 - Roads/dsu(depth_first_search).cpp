//
// Created by Emin Alizade on 03.12.21.
//

//
// Created by Emin Alizade on 03.12.21.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > g;
vector<int> used;
int n, m;

void dfsEdgeList(int v) {
    used[v] = 1;

    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];

        if (used[to] == 0) {
            dfsEdgeList(to);
        }
    }
}

// Week 11: November 29 - December 5 - DFS (Depth First Search)
int main() {
    cin >> n >> m;
    g.resize(n + 1);
    used.resize(n + 1);

    int a, b;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    int count = 0;

    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            count++;
            dfsEdgeList(i);
        }
    }

    cout << count - 1;

    return 0;
}