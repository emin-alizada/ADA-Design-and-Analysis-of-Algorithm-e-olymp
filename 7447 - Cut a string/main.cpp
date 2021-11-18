#include <iostream>
#define INF 0x3F3F3F3F

using namespace std;

int dp[101][101];
string s;

int f(int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == r) {
        return 1;
    }

    if (dp[l][r] != INF) {
        return dp[l][r];
    }

    int &res = dp[l][r];
    if (s[l] == s[r]) {
        res = min(res, f(l + 1, r - 1));
    }

    for (int i = l; i < r; i++) {
        res = min(res, f(l, i) + f(i + 1, r));
    }
    return res;
}

//Week 9: November 17 - Dynamic programming
int main() {
    cin >> s;
    memset(dp, INF, sizeof(dp));

    printf("%d\n", f(0, s.size() - 1));
    return 0;
}