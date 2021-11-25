#include <iostream>

using namespace std;

long long w, h ,n;

// 3969 - Diplomas

long long f(long long x) {
    return (x / w) * (x / h);
}

long long binarySearch(long long left, long long right)
{
    while (left < right)
    {
        long long mid = (left + right) / 2;
        if (f(mid) < n) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left;
}

int main() {

    cin >> w >> h >> n;

    long long res = binarySearch(0, (min(w,h) * n));

    cout << res;

    return 0;
}
