#include <iostream>

using namespace std;

// Week 9: November 17 Dynamic programming
int main() {
    int n;
    cin >> n;

    int cost[n], dp[n];

    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    dp[0] = 0;
    dp[1] = abs(cost[1] - cost[0]);

    for (int i = 2; i < n; ++i) {
        dp[i] = min( (dp[i-1] + abs(cost[i] - cost[i-1])), (dp[i-2] + abs(cost[i] - cost[i-2])) );
    }

    cout << dp[n-1];

    return 0;
}
