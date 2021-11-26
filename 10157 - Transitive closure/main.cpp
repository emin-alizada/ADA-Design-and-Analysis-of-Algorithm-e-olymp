#include <iostream>

#define MAX 101

using namespace std;

int n;
bool g[MAX][MAX];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i][k] && g[k][j]) {
                    g[i][j] = true;
                }
            }
        }
    }
}

// Week 10: November 26 - Transitive closure
int main() {
    cin >> n;

    int a, b;

    while (cin >> a >> b) {
        g[a][b] = true;
    }


    floyd();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
