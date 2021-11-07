#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    deque<long long> a(n);

    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > k) {
            cout << "Impossible";
            return 0;
        }
    }

    sort(a.begin(), a.end());

    long long count = 0;
    while (!a.empty()) {
        count++;

        if (a.front() + a.back() <= k && a.size() > 1) {
            a.pop_front();
        }

        a.pop_back();
    }


    cout << count;
    return 0;
}