#include <iostream>

#define MAX 110
#define INF 0x3F3F3F3F

using namespace std;

int dp[MAX][MAX], cards[MAX];

int f(int i, int j) {
    if (dp[i][j] == INF) {
        for (int k = i + 1; k < j; k++) {
            dp[i][j] = min(dp[i][j], f(i, k) + f(k, j) + cards[i] * cards[k] * cards[j]);
        }
    }

    return dp[i][j];
}

//Week 9: November 17 - Dynamic Programming
int main() {
    int n;
    cin >> n;

    memset(dp, INF, sizeof(dp));


    for (int i = 0; i < n; i++) {
        cin >> cards[i];
        dp[i][i] = 0;
        dp[i][i + 1] = 0;
    }


    cout << f(0, n - 1);

    return 0;
}