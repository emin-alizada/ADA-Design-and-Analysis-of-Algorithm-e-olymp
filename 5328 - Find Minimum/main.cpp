#include <iostream>

using namespace std;

int findMin(int arr[], int left, int right) {
    if (right == left) {
        return arr[left];
    }

    int mid =  (left + right) / 2;

    int leftMin = findMin(arr, left, mid);
    int rightMin = findMin(arr, mid + 1, right);

    return min(leftMin, rightMin);
}

int main() {
    int n, temp;
    cin>>n;

    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        arr[i] = temp;
    }

    cout << findMin(arr, 0, n-1);

    return 0;
}
