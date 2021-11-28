#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int *arr, int left, int right, int x)
{
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (x > arr[mid]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return arr[left] == x;
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
        cout << (binarySearch(a, 0, n-1, temp) ? "YES" : "NO") << endl;
    }

    return 0;
}
