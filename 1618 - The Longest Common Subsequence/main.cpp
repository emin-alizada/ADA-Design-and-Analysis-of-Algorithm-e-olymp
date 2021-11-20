#include <iostream>

using namespace std;
int dp[1001][1001], a[1001], b[1001];

int lcs(int i, int j) {
    if (i == 0 || j == 0) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if(a[i] == b[j]) {
        return dp[i][j] = 1 + lcs(i-1,j-1);
    } else {
        return dp[i][j] = max(lcs(i-1,j), lcs(i, j-1));
    }
}


//Week 9: November 19 - Longest Common Subsequence (LCS)
int main() {
    int n,m;

    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }

    cout << lcs(n, m);

    return 0;
}
