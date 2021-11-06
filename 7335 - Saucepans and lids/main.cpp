#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    long long a[n], b[m];

    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (long long i = 0; i < m; ++i) {
        cin >> b[i];
    }

    long long count = 0;

    long long i = 0, j = 0;

    sort(a, a+n);
    sort(b, b+m);

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            count++;
            i++;
            j++;
        } else {
            j++;
        }
    }

    cout << count;

    return 0;
}
