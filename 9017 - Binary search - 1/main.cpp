#include <iostream>

using namespace std;


int lowerBound(int *arr, int left, int right, int x) {
    while (left < right) {
        int mid = (left + right) / 2;
        if (x <= arr[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int upperBound(int *arr, int left, int right, int x) {
    while (left < right) {
        int mid = (left + right) / 2;
        if (x >= arr[mid])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}


int main() {
    int n, q, temp;
    cin >> n >> q;

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        cin >> temp;
        cout << (upperBound(a, 0, n, temp) - lowerBound(a, 0, n, temp)) << endl;
    }

    return 0;
}
