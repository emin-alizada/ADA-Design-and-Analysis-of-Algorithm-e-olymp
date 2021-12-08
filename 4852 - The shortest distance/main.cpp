#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

int n, s;
int g[MAX][MAX];
int dist[MAX];
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for (int i = 1; i <= n; ++i) {
            if (g[from][i] && dist[i] == -1) {
                dist[i] = dist[from] + 1;
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> n >> s;
    memset(dist, -1, sizeof(dist));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> g[i][j];
        }
    }

    q.push(s);
    dist[s] = 0;
    bfs();

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    return 0;
}
