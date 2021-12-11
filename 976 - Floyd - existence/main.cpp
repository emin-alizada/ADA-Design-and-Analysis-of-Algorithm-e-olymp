#include <iostream>

#define MAX 101

using namespace std;

int n;
int g[MAX][MAX], res[MAX][MAX];

// Because if we have 100 vertices that are connected like a train,
// like this 0-0-0-0-0-0 , then the distance between them would be like large

int maxN = INT32_MAX / 2 - 1;

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ((g[i][k] < maxN) && (g[k][j] < maxN))
                {
                    if (g[i][k] + g[k][j] < g[i][j]) g[i][j] = g[i][k] + g[k][j];
                    if (g[i][j] < -maxN) g[i][j] = -maxN;
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

            if (i != j && g[i][j] == 0) {
                g[i][j] = maxN;
            }
        }
    }

    floyd();

//    cout << maxN << endl;
//
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cout << g[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    cout << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] == maxN ) {
                res[i][j] = 0;
            } else {
                res[i][j] = 1;

                for(int k = 0; k < n; k++) {
                    if ((g[k][k] < 0) && (g[i][k] < maxN) && (g[k][j] < maxN)) {
                        res[i][k] = res[i][j] = res[k][j] = 2;
                    }
                }
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
