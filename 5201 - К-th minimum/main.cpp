#include <iostream>
#include <vector>

using namespace std;

vector<long long> v;
long long n, k, i;

long long Partition(long long left, long long right) {
    long long x = v[left], i = left - 1, j = right + 1;
    while (1) {
        do j--; while (v[j] > x);
        do i++; while (v[i] < x);
        if (i < j) swap(v[i], v[j]); else return j;
    }
}

long long kth(long long k, long long left, long long right) {
    if (left == right) return v[left];
    long long pos = Partition(left, right);
    if (k <= pos) return kth(k, left, pos);
    else return kth(k, pos + 1, right);
}

long long p(long long x) {
    long long mod = 1743;

    long long a1 = (132 * (((((x % mod) * (x % mod)) % mod) * (x % mod)) % mod)) % mod;
    long long a2 = (77 * (((x % mod) * (x % mod)) % mod)) % mod;
    long long a3 = (1345 * (x % mod)) % mod;

    long long res = ((((a1 + a2) % mod) + a3) % mod + 1577) % mod;

//    cout << a1 << " " << a2 << " " <<a3 << " " << res << endl;

    return res;
}


int main() {
    cin >> n >>k;

    v.push_back(0);

    for (long long j = 1; j <= n; ++j) {
        v.push_back(p(j));
    }

    cout << kth(k, 1, n) << endl;
    return 0;
}
