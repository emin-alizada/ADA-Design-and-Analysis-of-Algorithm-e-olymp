//
//  main.cpp
//  e-olymp The number of ones(44)
//
//  Created by Emin Alizade on 17/11/21.
//  Copyright © 2021 Emin Alizade. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

//Week 9: November 17 - Dynamic Programming
/* Driver code */
int main() {
    long long n;
    cin >> n;

    long long d[n+1];

    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    d[3] = 3;

    for (long long i = 4; i <= n; i++) {
        long long sumMin = LLONG_MAX;

        long long sumLoopLimit = i/2;
        for (long long j = 1; j <= sumLoopLimit; ++j) {
            sumMin = min(sumMin, d[j] + d[i - j]);
        }

        long long mulMin = LLONG_MAX;

        long long mulLoopLimit = sqrt(i);
        for (long long j = 2; j <= mulLoopLimit; ++j) {
            if (i % j == 0) {
                mulMin = min(mulMin, d[j] + d[i / j]);
            }
        }

        d[i] = min(sumMin, mulMin);
    }

    cout << d[n];
    return 0;
}



// Another simpler solution

//#include <iostream>
//
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//
//    int dp[n+1];
//
//    dp[1] = 1;
//    dp[2] = 2;
//    for (int i = 3; i <= n; i++) {
//        dp[i] = i;
//        for (int j = 1; j < i; j++) {
//            dp[i] = min(dp[i], dp[j] + dp[i-j] );
//            if (i%j == 0) {
//                dp[i] = min(dp[i], dp[j] + dp[i/j]);
//            }
//        }
//    }
//
//    cout << dp[n];
//
//    return 0;
//}