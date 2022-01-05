//
// Created by Emin Alizade on 05.01.22.
//

#include <iostream>

using namespace std;

void mergeOfSort(int a[], int lb, int le, int rb, int re, int *swaps) {
//    lb - left begin, le - left end, rb - right begin, re - right end
// a[lb..le] and a[rb..re] are merged into a[lb..re]

    int lp = lb; // left pointer
    int rp = rb; // right pointer
    int len = re - lp + 1;

    int i;
    int res[len]; // temporary array

    for (i = 0; lp <= le && rp <= re; i++) {
        if (a[lp] < a[rp]) {
            res[i] = a[lp];
            lp++;
        } else {
            res[i] = a[rp];
            rp++;
//            adding number of swaps that is made
            *swaps += (le - lp + 1);
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

    for (int j = 0; j < len; ++j) {
        a[lb + j] = res[j];
    }
}

void mergeSort(int a[], int left, int right, int *swaps) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(a, left, mid, swaps);
    mergeSort(a, mid + 1, right, swaps);
    mergeOfSort(a, left, mid, mid + 1, right, swaps);
}

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        int n;
        cin >> n;

        int m[n];

        for (int i = 0; i < n; ++i) {
            cin >> m[i];
        }

        int res = 0;
        mergeSort(m, 0, n-1, &res);

        cout << "Optimal train swapping takes " << res << " swaps." << endl;
    }
    return 0;
}
