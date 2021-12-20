//
// Created by Emin Alizade on 20.12.21.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> g;
vector<int> InDegree, topSort;
priority_queue <int, vector<int>, greater<int>> q;

int main() {
    int n, m;

    cin >> n >> m;
    g.resize(n+1);
    InDegree.assign(n + 1, 0);

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        InDegree[b]++;
    }

    for (int i = 1; i < InDegree.size(); i++) {
        if (InDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int v = q.top();
        q.pop();
        topSort.push_back(v);
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            InDegree[to]--;
            if (InDegree[to] == 0) {
                q.push(to);
            }
        }
    }

    if (topSort.size() < n) {
        cout << -1;
    }
    else {
        for (int i = 0; i < topSort.size(); i++) {
            cout << topSort[i] << " ";
        }
    }

    return 0;
}
