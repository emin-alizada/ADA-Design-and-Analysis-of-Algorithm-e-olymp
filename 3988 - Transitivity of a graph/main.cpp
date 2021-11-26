#include <iostream>

#define MAX 101

using namespace std;

int n, m;
bool g[MAX][MAX];

bool floyd() {
//    TODO analyze again
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (k == i || k == j) continue;


                if (g[i][k] && g[k][j]) {
                    if(!g[i][j]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

// Week 10: November 26 - Transitive closure
int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = false;
        }
    }

    int a, b;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        g[a][b] = true;
        g[b][a] = true;
    }


    cout << (floyd() ? "YES" : "NO");
    return 0;
}
