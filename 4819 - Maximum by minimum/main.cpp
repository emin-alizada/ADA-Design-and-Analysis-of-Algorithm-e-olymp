#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, s;
vector<vector<int>> g;
vector<int> dist;
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for(int to: g[from]) {
            if (dist[to] == -1) {
                dist[to] = dist[from] + 1;
                q.push(to);
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    dist.resize(n+1);
    fill(dist.begin(), dist.end(), -1);
    g.resize(n+1);

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
//        flipping edges
        g[b].push_back(a);
    }

    q.push(s);
    dist[s] = 0;
    bfs();

    int max = -1;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] > max) {
            max = dist[i];
        }
    }

    cout << max;

    return 0;
}
