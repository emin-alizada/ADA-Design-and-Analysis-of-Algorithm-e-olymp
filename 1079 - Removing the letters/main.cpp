#include <iostream>

using namespace std;
int dp[201][201];
string a, b;

int lcs(int i, int j) {
    if (i == -1 || j == -1) {
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

    while (cin >> a >> b) {
        memset(dp, -1, sizeof(dp));

        cout << lcs(a.size() - 1, b.size() -1) << endl;
    }

    return 0;
}
