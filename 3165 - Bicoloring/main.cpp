#include <iostream>
#define MAX 1001

using namespace std;

int g[MAX][MAX], used[MAX], n, m;
bool flag = false;

void dfsMatrix(int v, int color) {
    // if graph is not bicolorable, no sence to continue dfs
    if (flag) {
        return;
    }

    // color the vertex v
    used[v] = color;

    for (int i = 1; i <= n; ++i) {
        if (g[v][i] == 1) {
            // if vertex i is not colored (not visited),
            // continue dfs from it. Color vertex i with 3 - color
            if (used[i] == 0) {
                dfsMatrix(i, 3 - color);
            } else if (used[v] == used[i]) {
                flag = true;
            }
        }
    }
}

// Week 11: November 29 - December 5 - DFS (Depth First Search) (bicolor)
int main() {
    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        cin >> m;

        memset(g, 0, sizeof(g));
        memset(used, 0, sizeof(used));

        int a, b;
        for (int i = 1; i <= m; ++i) {
            cin >> a >> b;

            g[a][b] = 1;
            g[b][a] = 1;
        }

        flag = false;
        dfsMatrix(1, 1);

        cout << (flag ? "NOT BICOLOURABLE." : "BICOLOURABLE.") << endl;
    }

    return 0;
}