//
// Created by Emin Alizade on 20.12.21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int>> g;
vector<int> InDegree;
vector<double> prob;
queue<int> q;

int main() {
    int n, m, s;

    cin >> n >> m >> s;
    g.resize(n+1);
    InDegree.assign(n + 1, 0);
    prob.assign(n + 1, 0);

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        InDegree[b]++;
    }

    prob[s] = 1;

    for (long long i = 1; i < InDegree.size(); i++) {
        if (!InDegree[i]) {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        double dividedProb = prob[v] / double (g[v].size());
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            InDegree[to]--;
            prob[to] += dividedProb;
            prob[v] -= dividedProb;
            if (InDegree[to] == 0) {
                q.push(to);
            }
        }
    }

    double maxProb = LLONG_MIN;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 0 && prob[i] > maxProb) {
            maxProb = prob[i];
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 0 && prob[i] == maxProb) {
            cout << i << " ";
        }
    }

    return 0;
}