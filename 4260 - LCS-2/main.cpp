#include <iostream>
#include <algorithm>

using namespace std;
int dp[1001][1001];
string a, b;

int lcs(int i, int j) {
    if (i == 0 || j == 0) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (a[i] == b[j]) {
        return dp[i][j] = 1 + lcs(i - 1, j - 1);
    } else {
        return dp[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
    }
}


//Week 9: November 19 - Longest Common Subsequence (LCS)
int main() {
    cin >> a >> b;
    a = " " + a;
    b = " " + b;

    memset(dp, -1, sizeof(dp));

//    cout << lcs(a.size() - 1, b.size() - 1) << endl;
    lcs(a.size() - 1, b.size() - 1);

    int i = a.size() - 1; int j = b.size() - 1;
    string res;

    while (i >= 1 && j >= 1) {
        if (a[i] == b[j]) {
            res = res + a[i];
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    reverse(res.begin(), res.end());
    cout << res << endl;


    return 0;
}