#include <iostream>


using namespace std;

//Week 9: November 19 - Longest Increasing Subsequence (LIS)
int main() {
    int n;
    while (cin >> n) {
        int x[n+1], lis[n+1];

        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }

        int len, i;
        for (len = i = 0; i < n; i++) {
            int pos = lower_bound(lis,lis+len,x[i]) - lis;

            if (pos < len) {
                lis[pos] = x[i];
            } else {
                lis[len++] = x[i];
            }
        }

        cout << len << endl;
    }

    return 0;
}
