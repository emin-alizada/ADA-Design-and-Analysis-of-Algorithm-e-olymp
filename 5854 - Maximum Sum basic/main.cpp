//
//  main.cpp
//  e-olymp Maximum Sum basic(5854)
//
//  Created by Emin Alizade on 6/24/19.
//  Copyright © 2019 Emin Alizade. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int dp[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> dp[i][j];
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int maxPrev = INT32_MIN;
            maxPrev = max(maxPrev, dp[i-1][j]);

            if (j > 0) {
                maxPrev = max(maxPrev, dp[i-1][j-1]);
            }

            if (j < m-1) {
                maxPrev = max(maxPrev, dp[i-1][j+1]);
            }

            dp[i][j] += maxPrev;
        }
    }

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }

    int maxResult = INT32_MIN;
    for (int j = 0; j < m; ++j) {
        maxResult = max(maxResult, dp[n - 1][j]);
    }

    cout << maxResult;

    return 0;
}