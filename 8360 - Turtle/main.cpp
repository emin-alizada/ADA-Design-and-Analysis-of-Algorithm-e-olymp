#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;


    int dp[n+1][m+1];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> dp[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1) {
                continue;
            }

            int adder = dp[i-1][j];

            if (j != 1) {
                adder = max(adder, dp[i-1][j - 1]);
            }

            if (j != m) {
                adder = max(adder, dp[i-1][j + 1]);
            }

            dp[i][j] += adder;
        }
    }

    int max = dp[n][1];
    int maxJ = 1;
    for (int j = 1; j <= m; ++j) {
        if (dp[n][j] > max) {
            max = dp[n][j];
            maxJ = j;
        }
    }


//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }


    int i = n, j = maxJ;

    while (i > 1) {
        int maxWhile, maxJWhile;
        if (j - 1 >= 1) {
            maxWhile = dp[i - 1][j - 1];
            maxJWhile = j - 1;
        } else {
            maxWhile = dp[i-1][j];
            maxJWhile = j;
        }

        if (dp[i-1][j] > maxWhile) {
            maxWhile = dp[i-1][j];
            maxJWhile = j;
        }

        if (j + 1 <= m && dp[i-1][j+1] > maxWhile) {
            maxWhile = dp[i-1][j+1];
            maxJWhile = j + 1;
        }

        j = maxJWhile;
        i--;
    }

    cout << j << " " << max;

    return 0;
}