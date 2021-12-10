#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, s, f;
vector<vector<int>> g;
vector<int> dist, distF;
queue<int> q;

vector<pair<int,int>> added;

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


void bfsF() {
    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for(int to: g[from]) {
            if (distF[to] == -1) {
                distF[to] = distF[from] + 1;
                q.push(to);
            }
        }
    }
}

int main() {
    cin >> n >> m >> s >> f;
    dist.resize(n+1);
    fill(dist.begin(), dist.end(), -1);

    distF.resize(n+1);
    fill(distF.begin(), distF.end(), -1);

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


    q.push(f);
    distF[f] = 0;
    bfsF();

    int maxDist = dist[f];
    int counter = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (!count(g[i].begin(), g[i].end(), j)) {
                if (!(dist[i] + 1 + distF[j] < maxDist || dist[j] + 1 + distF[i] < maxDist)) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                    added.push_back(make_pair(i,j));

                    counter++;
                }
            }
        }
    }

    cout << counter;

    return 0;
}
