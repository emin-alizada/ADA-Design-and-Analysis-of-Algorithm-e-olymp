#include <iostream>

using namespace std;

long long lowerBound(long long *arr, long long left, long long right, long long x) {
    while (left < right) {
        long long mid = (left + right) / 2;
        if (x <= arr[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

long long upperBound(long long *arr, long long left, long long right, long long x) {
    while (left < right) {
        long long mid = (left + right) / 2;
        if (x >= arr[mid])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void mergeOfSort(long long a[], long long lb, long long le, long long rb, long long re) {
//    lb - left begin, le - left end, rb - right begin, re - right end
// a[lb..le] and a[rb..re] are merged into a[lb..re]

    long long lp = lb; // left pointer
    long long rp = rb; // right pointer
    long long len = re - lp + 1;

    long long i;
    long long res[len]; // temporary array

    for (i = 0; lp <= le && rp <= re; i++) {
        if (a[lp] < a[rp]) {
            res[i] = a[lp];
            lp++;
        } else {
            res[i] = a[rp];
            rp++;
        }
    }

//    rest of left part
    while (lp <= le) {
        res[i] = a[lp];
        lp++;
        i++;
    }

//    rest of right part
    while (rp <= re) {
        res[i] = a[rp];
        rp++;
        i++;
    }

    for (long long j = 0; j < len; ++j) {
        a[lb + j] = res[j];
    }
}

void mergeSort(long long a[], long long left, long long right) {
    if (left >= right) {
        return;
    }

    long long mid = (left + right) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    mergeOfSort(a, left, mid, mid + 1, right);
}


//Count the triplets
int main() {
    long long n;

    cin >> n;

    long long a[n], b[n], c[n];


    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (long long i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (long long i = 0; i < n; ++i) {
        cin >> c[i];
    }

    mergeSort(a, 0, n - 1);
    mergeSort(b, 0, n - 1);
    mergeSort(c, 0, n - 1);

    long long count = 0;
    for (long long i = 0; i < n; ++i) {
        count += lowerBound(a, 0, n, b[i]) * (n - upperBound(c, 0, n, b[i]));
    }

    cout << count;

    return 0;
}
