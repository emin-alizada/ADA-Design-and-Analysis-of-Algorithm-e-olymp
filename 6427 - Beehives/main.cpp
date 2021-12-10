#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, minimum;
vector<vector<int>> g;
vector<int> dist , par;
queue<int> q;

void bfs(int i) {
    q.push(i);
    fill(dist.begin(), dist.end(), -1);
    fill(par.begin(), par.end(), -1);
    dist[i] = 0;

    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for(int to: g[from]) {
            if (dist[to] == -1) {
                dist[to] = dist[from] + 1;
                par[to] = from;
                q.push(to);
            } else if (!(par[to] == from || par[from] == to)) {
                minimum = min(minimum, dist[to] + 1 + dist[from]);
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int k = 1; k <= t; k++) {
        cin >> n >> m;
        dist.resize(n);
        par.resize(n);
        g = vector<vector<int>>(n);

        minimum = INT32_MAX;

        int a, b;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }

        for (int i = 0; i < n; ++i) {
            bfs(i);
        }


        printf("Case %d: ", k);
        cout << (minimum != INT32_MAX ? to_string(minimum) : "impossible") << endl;
    }

    return 0;
}

/*
1
2 1
0 1
 */