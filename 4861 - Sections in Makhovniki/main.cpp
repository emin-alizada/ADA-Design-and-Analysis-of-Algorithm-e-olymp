//
// Created by Emin Alizade on 20.12.21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> g;
vector<int> InDegree, topSort;
priority_queue<int> q;

int main() {
    int n;

    cin >> n;
    g.resize(n+1);
    InDegree.assign(n + 1, 0);

    int e, temp;
    for (int i = 1; i <= n; ++i) {
        cin >> e;
        for (int j = 0; j < e; ++j) {
            cin >> temp;
            g[i].push_back(temp);
            InDegree[temp]++;
        }
    }

//    int a, b;
//    for (int i = 0; i < m; ++i) {
//        cin >> a >> b;
//        g[a].push_back(b);
//        InDegree[b]++;
//    }

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
        reverse(topSort.begin(), topSort.end());
        for (int i = 0; i < topSort.size(); i++) {
            cout << topSort[i] << " ";
        }
    }

    return 0;
}
