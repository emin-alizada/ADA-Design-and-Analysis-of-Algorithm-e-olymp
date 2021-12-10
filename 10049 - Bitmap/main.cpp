#include <iostream>
#include <queue>

#define MAX 1001

using namespace std;

int n, m;
string g[MAX];
int dist[MAX][MAX];
queue<pair<int, int>> q;

void add(int x, int y, int newDist) {
//    Out of boundaries
    if ((x < 1) || (x > n) || (y < 1) || (y > m)) {
        return;
    }
//    dist is already found
    if (dist[x][y] != -1) {
        return;
    }

    dist[x][y] = newDist;

    q.push(make_pair(x, y));
}

void bfs() {
    while (!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;

        int newDist = dist[x][y] + 1;
        add(x + 1, y, newDist);
        add(x - 1, y, newDist);
        add(x, y + 1, newDist);
        add(x, y - 1, newDist);
    }
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        cin >> n >> m;
        memset(dist, -1, sizeof(dist));

        for (int i = 1; i <= n; ++i) {
            cin >> g[i];
//            empty space is because i traverse everything starting from index 1
            g[i] = " " + g[i];
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (g[i][j] == '1') {
                    q.push(make_pair(i, j));
                    dist[i][j] = 0;
                }
            }
        }

        bfs();

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }

    }

    return 0;
}
