#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, s, f;
vector<vector<int>> g;
vector<int> dist, par;
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for(int to: g[from]) {
            if (dist[to] == -1) {
                dist[to] = dist[from] + 1;
                par[to] = from;
                q.push(to);
            }
        }
    }
}

void printPath(int to) {
    vector<int> res;
    while (to != -1) {
        res.push_back(to);
        to = par[to];
    }

    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }

    cout << endl;
}

int main() {
    cin >> n >> m >> s >> f;
    dist.resize(n+1);
    fill(dist.begin(), dist.end(), -1);

    par.resize(n+1);
    fill(par.begin(), par.end(), -1);

    g.resize(n+1);

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    q.push(s);
    dist[s] = 0;
    bfs();

    cout << dist[f] << endl;
    if (dist[f] != -1) {
        printPath(f);
    }

    return 0;
}
