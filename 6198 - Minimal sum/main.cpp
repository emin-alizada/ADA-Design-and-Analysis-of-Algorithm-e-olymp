#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n;

    cin >> n;

    long long a[n], b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a, a+n);
    sort(b, b+n);
    reverse(b, b+n);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    cout << sum;
}