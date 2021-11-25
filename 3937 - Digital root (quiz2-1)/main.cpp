#include <iostream>
#include <vector>
#include <algorithm>

// 3937 - Digital root

using namespace std;

long long temp;
vector<long long> arr;

long long sum(long long num) {
    if (num < 10) {
        return num;
    } else {
        return sum(num / 10) + num % 10;
    }
}

long long digitalRoot(long long n) {
    while (n > 9) n = sum(n);
    return n;
}

long long comparator(long long a, long long b) {
    if (digitalRoot(a) == digitalRoot(b)) {
        return a < b;
    }

    return digitalRoot(a) < digitalRoot(b);
}

long long Partition(vector<long long> &m, long long L, long long R) {
    long long x = m[L];
    long long i = L - 1, j = R + 1;
    while (true) {
        do j--; while (comparator(x, m[j]));
        do i++; while (comparator(m[i], x));
        if (i < j) swap(m[i], m[j]); else return j;
    }
}

void QuickSort(vector<long long> &m, long long L, long long R) {
    if (L < R) {
        long long q = Partition(m, L, R);
        QuickSort(m, L, q);
        QuickSort(m, q + 1, R);
    }
}

int main() {
    while (cin >> temp) {
        arr.push_back(temp);
    }

    QuickSort(arr, 0, arr.size() - 1);

    for (long long i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}