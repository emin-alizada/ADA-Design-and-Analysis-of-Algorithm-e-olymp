#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long n, k;
vector<long long> a;

long long f(long long x) {
    long long count = 1;
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        if (a[i] > x) {
            count = LLONG_MAX;
            break;
        }
        if (sum + a[i] <= x) {
            sum += a[i];
        } else {
            count++;
            sum = a[i];
        }
    }

    return count <= k;
}

long long binary(long long l, long long r) {
    while (l < r) {
        long long m = (l + r) / 2;

        if (!f(m)) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return l;
}

int main() {
    cin >> n >> k;
    a.resize(n);

    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    cout << binary(1, sum);
    return 0;
}
