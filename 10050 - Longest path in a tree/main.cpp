#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


struct edge {
    long long to, dist;

    edge(long long to, long long dist) : to(to), dist(dist) {}
};

long long n;
vector<vector<edge>> g;
vector<long long> dist;
queue<long long> q;

void bfs() {
    while (!q.empty()) {
        long long from = q.front();
        q.pop();

        for (long long i = 0; i < g[from].size(); ++i) {
            long long to = g[from][i].to;
            long long w = g[from][i].dist;

            if (dist[to] == -1) {
                dist[to] = dist[from] + w;

               q.push(to);
            }
        }
    }
}

int main() {
    cin >> n;
    g.resize(n+1);
    dist.assign(n+1, -1);

    long long a, b, c;
    for (long long i = 0; i < n - 1; ++i) {
        cin >> a >> b >> c;
        g[a].push_back(edge(b, c));
        g[b].push_back(edge(a, c));
    }

    q.push(1);
    dist[1] = 0;

    bfs();

    long long max = LLONG_MIN;
    long long maxVertex = 1;
    for (long long i = 1; i < dist.size(); ++i) {
//        cout << dist[i] << " ";
        if (dist[i] > max) {
            max = dist[i];
            maxVertex = i;
        }
    }
//    cout << endl;

    dist.assign(n+1, -1);
    q.push(maxVertex);
    dist[maxVertex] = 0;

    bfs();

    max = LLONG_MIN;
    maxVertex = 1;
    for (long long i = 1; i < dist.size(); ++i) {
//        cout << dist[i] << " ";
        if (dist[i] > max) {
            max = dist[i];
            maxVertex = i;
        }
    }

//    cout << endl;

    cout << max;

    return 0;
}
