#include <iostream>
#include <vector>
#define INF 0x3F3F3F3F
#define MAX 2001

using namespace std;

// globals
int g[MAX][MAX], used[MAX], dist[MAX], parent[MAX];

void Relax(int i, int j)
{
    if (dist[i] + g[i][j] < dist[j]) {
        dist[j] = dist[i] + g[i][j];
        parent[j] = i;
    }
}

//Week 8 Nov 10 Dijkstra
int main() {
    int n, m, s, f;

    cin >> n >> m >> s >> f;

//    setting initial values
    memset(g, 0x3F, sizeof(g));
    memset(used, 0, sizeof(used));
    memset(parent, -1, sizeof(parent));
    memset(dist, 0x3F, sizeof(dist));

    int b,e,w;
    for (int i = 0; i < m; ++i) {
        cin >> b >> e >> w;
        g[b][e] = w;
        g[e][b] = w;
    }

    dist[s] = 0; // distant from source to itself is 0

    int min, v;

    for (int i = 1; i < n; i++)
    {
        // find vertex w with minimum d[w] among not used vertices
        min = INF; v = -1;
        for (int j = 1; j <= n; j++) {
            if (used[j] == 0 && dist[j] < min) {
                min = dist[j];
                v = j;
            }
        }

        // no more vertices to add
        if (v < 0) break;

        // relax all edges outgoing from v
        // process edge v -> j
        for (int j = 1; j <= n; j++) {
            if (used[j] == 0 && g[v][j] != -1) {
                Relax(v, j);
            }
        }

        // shortest distance to v is found
        used[v] = 1;
    }

    if (dist[f] == INF) {
        cout << -1;
    }else {
        cout << dist[f] << endl;
    }


    return 0;
}
