#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge
{
    int to, dist;
    edge(int to, int dist) : to(to), dist(dist) {}
};

int n,m,s,d;
vector<vector<edge>> g;
vector<int> dist;
deque<int> q;


void bfs() {
    while (!q.empty()) {
        int from = q.front();
        q.pop_front();

        for (int i = 0; i < g[from].size(); ++i) {
            int to = g[from][i].to;
            int w = g[from][i].dist;

            if (dist[to] == -1 || dist[to] > dist[from] + w) {
                dist[to] = dist[from] + w;

                if (w == 0) {
                    q.push_front(to);
                } else {
                    q.push_back(to);
                }
            }
        }
    }
}

//Week 12: December 6 - 12 - BFS 0-1 graph

int main() {
    cin >> n >> m >> s >> d;
    dist.resize(n + 1);
    fill(dist.begin(), dist.end(), -1);

    g.resize(n+1);

    int a,b,w;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        g[a].push_back(edge(b, w));
        g[b].push_back(edge(a, w));
    }

    q.push_front(s);
    dist[s] = 0;
    bfs();

    cout << dist[d];
    return 0;
}