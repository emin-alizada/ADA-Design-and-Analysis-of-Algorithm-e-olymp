#include <iostream>

using namespace std;

long long n, k, a[100];

long long dp(long long pos) {
    if (pos == n) return 1;
    if (pos > n) return 0;
    if (a[pos] != -1) return a[pos];

    long long temp = 0;
    for (int i = 1; i <= k; i++)
        temp += dp(pos + i);
    return a[pos] = temp;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < 100; i++) {
        a[i] = -1;
    }

    cout << dp(1);
}