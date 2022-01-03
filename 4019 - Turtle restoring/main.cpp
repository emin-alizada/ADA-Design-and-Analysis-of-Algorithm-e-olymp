#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    vector<pair<int, int>> path;

    cin >> n >> m;


    int dp[n+1][m+1];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> dp[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) {
                continue;
            }

            if (i == 1) {
                dp[i][j] += dp[i][j-1];
                continue;
            }

            if (j == 1) {
                dp[i][j] += dp[i-1][j];
                continue;
            }

            dp[i][j] += min(dp[i][j-1], dp[i-1][j]);
        }
    }

    cout << dp[n][m] << endl;

    int i = n, j = m;

    while (i >= 1 && j >= 1) {
        path.push_back(make_pair(i, j));

        if (i == 1) {
            j--;
        } else if (j == 1) {
            i--;
        } else if (dp[i-1][j] < dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(path.begin(), path.end());

    for (i = 0; i < path.size(); i++) {
        cout << path[i].first << " " << path[i].second << endl;
    }

    return 0;
}