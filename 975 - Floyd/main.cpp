#include <iostream>

#define MAX 101

using namespace std;

int n;
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
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
            if (g[i][j] == -1) {
                g[i][j] = maxN;
            }
        }
    }


    floyd();
    int res = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] > res && g[i][j] != maxN) {
                res = g[i][j];
            }
        }
    }

    cout << res;

    return 0;
}