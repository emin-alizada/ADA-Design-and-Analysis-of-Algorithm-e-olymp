#include <iostream>
#include <cmath>

#define MAX 100001
long long h[MAX], n, a, b;

using namespace std;

// 8598 - Wizard and wolves

long long canBeKilled(long long x) {
    long long res = 0;

    for (long long i = 0; i < n; i++) {
        if (h[i] > x * b) {
//            casting to double one side of division is important to prevent integer division
            res += ceil( (h[i] - x * b) / (double)(a - b) );
        }
    }

    return res <= x;
}

int main() {
    cin >> n >> a >> b;

    for (long long i = 0; i < n; ++i) {
        cin >> h[i];
    }

    long long left = 0, right = 1000000000, mid;

    while (left < right)
    {
        mid = (left + right) / 2;
        if (canBeKilled(mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << left;

    return 0;
}