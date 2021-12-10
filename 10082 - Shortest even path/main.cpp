#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, s, f;
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
    cin >> n >> m >> s >> f;
    dist.resize(2*n+1);
    fill(dist.begin(), dist.end(), -1);

    g.resize(2*n+1);

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        g[2*a - 1].push_back(2*b);
        g[2*b].push_back(2*a - 1);

        g[2*a].push_back(2*b - 1);
        g[2*b - 1].push_back(2*a);
    }

    q.push(2*s - 1);
    dist[2*s - 1] = 0;
    bfs();

    cout << dist[2 * f - 1] << endl;

    return 0;
}
