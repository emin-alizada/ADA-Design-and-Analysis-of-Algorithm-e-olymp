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

//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cout << g[i][j] << " ";
//        }
//        cout << endl;
//    }

//    diameter is just a maximum distance between any two points
//    radius is minimum of (maximums of a row) or in other words minimum distance when vertex reaches all others vertices
    int radius = maxN , diameter = 0;

    for (int i = 1; i <= n; i++) {
        int localMax = 0;

        for (int j = 1; j <= n; j++) {
            if (g[i][j] > localMax && g[i][j] != maxN) {
                localMax = g[i][j];
            }

            if (g[i][j] > diameter && g[i][j] != maxN) {
                diameter = g[i][j];
            }
        }

        if (localMax < radius) {
            radius = localMax;
        }
    }

    cout << diameter << endl;
    cout << radius;

    return 0;
}
