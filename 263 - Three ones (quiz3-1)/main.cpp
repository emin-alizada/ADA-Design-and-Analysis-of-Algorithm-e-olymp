#include <iostream>

#define MAX 100000

using namespace std;

int main() {
    long long modulo = 12345;
    long long n;
    cin >> n;

    long long dp[MAX];

    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 7;

    for (long long i = 4; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % modulo;
    }

    cout << dp[n];
}