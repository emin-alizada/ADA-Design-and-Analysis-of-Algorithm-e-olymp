//
// Created by Emin Alizade on 20.12.21.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        vector<vector<int>> g (n + 1);
        vector<int> InDegree(n + 1, 0), topSort;
        queue<int> q;

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
            int v = q.front();
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

        cout << endl;
    }

    return 0;
}