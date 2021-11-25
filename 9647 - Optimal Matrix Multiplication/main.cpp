#include <iostream>
#include <cstring>

#define INF 0x3F3F3F3F3F3F3F3FLL

using namespace std;

#define MAX 11

long long m[MAX][MAX], p[MAX];

long long Mult(int i, int j) {
    if (m[i][j] == INF) {
        for (int k = i; k <= j - 1; k++) {
            long long temp = Mult(i, k) + Mult(k + 1, j) + p[i - 1] * p[k] * p[j];
            if (temp < m[i][j]) {
                m[i][j] = temp;
            }
        }
    }
    return m[i][j];
}

// Week 10: November 24 - Matrix multiplication
int main() {
    int n;
    cin >> n;
    memset(m, 0x3F, sizeof(m));
    for (int i = 1; i <= n; i++) {
        cin >> p[i-1] >> p[i];
        m[i][i] = 0;
    }

    cout << Mult(1, n);
    return 0;
}
