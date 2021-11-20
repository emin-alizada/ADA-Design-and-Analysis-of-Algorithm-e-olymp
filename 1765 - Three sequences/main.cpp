#include <iostream>

using namespace std;
int dp[101][101][101], a[101], b[101], c[101];

int maxOf3 (int a, int b, int c){
    int val = a;
    val = max(val, b);
    val = max(val, c);
    return val;
}

int lcs(int i, int j, int z) {
    if (i == 0 || j == 0 || z == 0) {
        return 0;
    }

    if (dp[i][j][z] != -1) {
        return dp[i][j][z];
    }

    if(a[i] == b[j] && b[j] == c[z]) {
        return dp[i][j][z] = 1 + lcs(i-1,j-1, z-1);
    } else {
        return dp[i][j][z] = maxOf3(lcs(i - 1, j, z), lcs(i, j - 1, z), lcs(i, j, z-1));
    }
}


//Week 9: November 19 - Longest Common Subsequence (LCS)
int main() {
    int n,m,k;

    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }

    cin >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> c[i];
    }

    cout << lcs(n, m, k);

    return 0;
}
