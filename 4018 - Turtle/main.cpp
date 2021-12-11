#include <iostream>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;


    int dp[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> dp[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }

            if (i == 0) {
                dp[i][j] += dp[i][j-1];
                continue;
            }

            if (j == 0) {
                dp[i][j] += dp[i-1][j];
                continue;
            }

            dp[i][j] += min(dp[i][j-1], dp[i-1][j]);
        }
    }

    cout << dp[n-1][m-1];

    return 0;
}
