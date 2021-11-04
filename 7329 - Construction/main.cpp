#include <iostream>

using namespace std;

int n,m;

int comparator(int *arr, int x) {
    int count = 0;

    for (int i = 0; i < n; ++i) {
        count += arr[i] / x;
    }

    return count >= m;
}

int binarySearch(int *arr, int left, int right)
{
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (comparator(arr, mid)) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left - 1;
}

int main() {
    cin >> n >> m;

    int woods[n];
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> woods[i];
        sum += woods[i];
    }

//    if it's impossible to get the number
    if (sum < m) {
        cout << 0;
        return 0;
    }

    cout << binarySearch(woods, 0, INT32_MAX);

    return 0;
}
