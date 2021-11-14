#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;

long long y[4001];
long long INF = (LLONG_MAX / 2) - 1;
vector<long long> parent;

struct edge
{
    long long node, dist;
    edge(long long node, long long dist) : node(node), dist(dist) {}
};

bool operator< (edge a, edge b)
{
    return a.dist > b.dist;
}

void PrintPath(long long v) {
    vector<long long> res;
    while (v != -1) {
        res.push_back(v);
        v = parent[v];
    }
    for (long long i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    cout <<  endl;
}

void Dijkstra(vector<vector<edge>> g, long long n, long long start, long long fin) {
    priority_queue<edge> pq;
    pq.push(edge(start,0));

    vector<long long> dist(n + 1, INF);
    parent = vector<long long> (n+1, -1);
    dist[start] = 0;

    while(!pq.empty())
    {
        edge e = pq.top();
        pq.pop();
        long long v = e.node;

        if (e.dist > dist[v]) {
            continue;
        }

        for (long long j = 0; j < g[v].size(); ++j) {
            long long to = g[v][j].node;
            long long cost = g[v][j].dist;
            if (dist[v] + cost < dist[to])
            {
                dist[to] = dist[v] + cost;
                parent[to] = v;
                pq.push(edge(to, dist[to]));
            }
        }
    }

    if (dist[fin] == INF) {
        cout << -1;
    }
    else {
        cout << dist[fin] << endl;
        PrintPath(fin);
    }
}



int main()
{
    long long n,m,s,f;
    cin >> n >> m >> s >> f;

    vector<vector<edge>> g(n+1);

    long long b,e,w;
    for (long long i = 0; i < m; ++i) {
        cin >> b >> e >> w;
        g[b].push_back(edge(e,w));
        g[e].push_back(edge(b,w));
    }

    Dijkstra(g, n, s, f);

    return 0;
}