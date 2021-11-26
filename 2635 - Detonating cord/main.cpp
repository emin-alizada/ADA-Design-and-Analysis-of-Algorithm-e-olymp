#include <iostream>

#define MAX 101

using namespace std;

int n, m;
int g[MAX][MAX];

// Because if we have 100 vertices that are connected like a train,
// like this 0-0-0-0-0-0 , then the distance between them would be like large

int maxN = INT32_MAX / 2 - 1;

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i][k] + g[k][j] < g[i][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
}

// Week 10: November 26 - Floyd
int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = maxN;

//            distance is 0 from node to itself
            if (i == j) {
                g[i][j] = 0;
            }
        }
    }

    int a, b, w;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        g[a][b] = g[b][a] = w;
    }


    floyd();

    int node, min = maxN;

    for (int i = 1; i <= n; i++) {
        int localMax = 0;

        for (int j = 1; j <= n; j++) {
            if (g[i][j] > localMax && g[i][j] != maxN) {
                localMax = g[i][j];
            }
        }

        if (localMax < min) {
            node = i;
            min = localMax;
        }
    }

    cout << node << " " << min;

    return 0;
}
