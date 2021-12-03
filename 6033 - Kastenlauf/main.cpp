#include <iostream>

#define MAX 103

using namespace std;

long long g[MAX][MAX], used[MAX], n;

void dfsMatrix(long long v) {
    used[v] = 1;

    for (long long i = 0; i < n+2; ++i) {
        if (used[i] == 0 && g[v][i] == 1) {
            dfsMatrix(i);
        }
    }
}

// Week 11: November 29 - December 5 - DFS (Depth First Search)
int main() {
    long long t;

    cin >> t;

    while (t--) {
        cin >> n;
        memset(g, 0, sizeof (g));
        memset(used, 0, sizeof (used));

        long long x[n + 2], y[n + 2];

        for (long long i = 0; i < n + 2; ++i) {
            cin >> x[i] >> y[i];
        }

        for (long long i = 0; i < n + 2; i++) {
            for (long long j = i + 1; j < n + 2; j++) {
                if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= 1000) {
                    g[i][j] = g[j][i] = 1;
                }
            }
        }

        dfsMatrix(0);

        cout << (used[n+1] == 1 ? "happy" : "sad") << endl;
    }
    return 0;
}
