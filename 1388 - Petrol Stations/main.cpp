#include <iostream>
#include <vector>
#define INF 0x3F3F3F3F
#define MAX 101

using namespace std;

// globals
int g[MAX][MAX], used[MAX], dist[MAX], cost[MAX], parent[MAX];

void Relax(int i, int j)
{
    if (dist[i] + g[i][j] < dist[j]) {
        dist[j] = dist[i] + g[i][j];
        parent[j] = i;
    }
}

void PrintPath(int v) {
    vector<int> res;
    while (v != -1) {
        res.push_back(v);
        v = parent[v];
    }
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    cout <<  endl;
}

int main() {
    int n, m;

    cin >> n;

    int s = 1, f = n;

//    setting initial values
    memset(g, 0x3F, sizeof(g));
    memset(used, 0, sizeof(used));
    memset(dist, 0x3F, sizeof(dist));
    memset(parent, -1, sizeof(parent));

    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }

    cin >> m;

    int b,e;
    for (int i = 0; i < m; ++i) {
        cin >> b >> e;
        g[b][e] = cost[b];
        g[e][b] = cost[e];
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
//        PrintPath(f);
    }


    return 0;
}
