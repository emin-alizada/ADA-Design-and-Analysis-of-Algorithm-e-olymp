#include <iostream>

using namespace std;

long long myF(long long i, long long j) {
    long long t = (i-j) * (i-j);
    return t;
}

//Week 9: November 17 Dynamic programming
int main() {
    long long n;
    cin >> n;

    long long cost[n], dp[n];

    for (long long i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    dp[0] = 0;
    dp[1] = myF(cost[1],cost[0]);

    if (n > 2) {
        dp[1] = min(dp[1], 3 * myF(cost[2], cost[0]) + myF(cost[2], cost[1]));
    }

    for (long long i = 2; i < n - 1; ++i) {
        dp[i] =  min((dp[i-1] + myF(cost[i], cost[i-1])), (dp[i-2] + (3 * myF(cost[i], cost[i-2]))) );
        dp[i] = min(dp[i], (dp[i-1] + (3 * myF(cost[i-1], cost[i+1]) + myF(cost[i+1], cost[i])) ));
    }

    long long i = n - 1;
    dp[i] =  min((dp[i-1] + myF(cost[i], cost[i-1])), (dp[i-2] + (3 * myF(cost[i], cost[i-2]))));


    cout << dp[i];

    return 0;
}