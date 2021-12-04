//
// Created by Emin Alizade on 04.12.21.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > g;
vector<int> used;
// path to each edge in dfs
vector<vector<int> > path;
int n, m;
// flag for detecting cycle
bool flag = false;
int cycleStart, cycleEnd;

void printPath() {
    bool shouldPrint = false;

    for (int i: path[cycleEnd]) {
        if (i == cycleStart) {
            shouldPrint = true;
        }
        if (shouldPrint) {
            cout << i << " ";
        }
    }
}

void dfsEdgeList(int v, int prev = -1) {
    if (flag) {
        return;
    }

    used[v] = 1;

    if (prev == -1) {
        path[v].push_back(v);
    } else {
        path[v] = path[prev];
        path[v].push_back(v);
    }

    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];

        if (used[to] == 0) {
            dfsEdgeList(to, v);
        }

        if (used[to] == 1) {
            flag = true;
            cycleStart = to;
            cycleEnd = v;
        }
    }

    used[v] = 2;
}

// Week 11: November 29 - December 5 - DFS (Depth First Search)
int main() {
    cin >> n >> m;
    g.resize(n + 1);
    used.resize(n + 1);
    path.resize(n + 1);

    int a, b;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;

        g[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            dfsEdgeList(i);
        }
    }

    cout << (flag ? "YES" : "NO") << endl;

    if (flag) {
        printPath();
    }

    return 0;
}