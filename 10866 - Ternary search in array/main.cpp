#include <iostream>

using namespace std;

long long ternarySearch(long long arr[], long long a, long long b, long long x) {
    long long g, h;
    while (a < b) {
        g = a + (b - a) / 3;
        h = b - (b - a) / 3;

        if (arr[g] == x) {
            return 1;
        }

        if (arr[h] == x) {
            return 1;
        }

        if (x < arr[g]) {
            b = g - 1;
        } else if (x > arr[h]) {
            a = h + 1;
        } else {
            a = g+1;
            b = h-1;
        }
    }

    return x == arr[a];
}

int main() {
    long long n, q;
    cin >> n >> q;

    long long a[n];

    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (long long i = 0; i < q; ++i) {
        long long temp;
        cin >> temp;

        cout << (ternarySearch(a, 0, n-1, temp) ? "YES" : "NO") << endl;
    }
    return 0;
}