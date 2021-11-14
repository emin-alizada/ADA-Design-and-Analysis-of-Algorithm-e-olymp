#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;

long long y[4001];
long long INF = (LLONG_MAX / 2) - 1;

struct edge
{
    long long node, dist;
    edge(long long node, long long dist) : node(node), dist(dist) {}
};

bool operator< (edge a, edge b)
{
    return a.dist > b.dist;
}

long long calculateCost(long long i, long long j) {
    return (i-j) * (i-j) * (y[i] - y[j]) * (y[i] - y[j]);
}

void Dijkstra(long long n, long long start, long long fin) {
    priority_queue<edge> pq;
    pq.push(edge(start,0));

    vector<long long> dist(n, INF);
    dist[start] = 0;

    while(!pq.empty())
    {
        edge e = pq.top();
        pq.pop();
        long long v = e.node;

        if (e.dist > dist[v]) {
            continue;
        }

        for (long long j = 0; j < n; ++j) {
            long long cost = calculateCost(v, j);
            if (dist[v] + cost < dist[j]) {
                dist[j] = dist[v] + cost;
                pq.push(edge(j, dist[j]));
            }
        }
    }

    if (dist[fin] == INF) {
        cout << -1;
    }
    else {
        cout << dist[fin];
    }
}



int main()
{
    long long n;
    cin >> n;

    for (long long i = 0; i < n; ++i) {
        cin >> y[i];
    }

    Dijkstra(n, 0, n-1);

    return 0;
}
