#include <iostream>

using namespace std;

//Check if the given x is suitable
bool f(long long *arr, long long x, long long n) {
    bool flag = true;
    for (long long i = 0; i < n; ++i) {
        if (x < arr[i]){
            flag = false;
            break;
        }
        x++;
    }
    return flag;
}

int main() {
    long long n;
    cin >> n;

    long long a[n];
    long long max;

    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        if (i==0) {
            max = a[i];
        } else {
            if (max < a[i]) {
                max = a[i];
            }
        }
    }

    long long left = a[0];
    long long right = max;

    while (left < right)
    {
        long long mid = (left + right) / 2;
        if (f(a, mid, n)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    long long count = 0;

    for (long long i = 0; i < n; ++i) {
        while (a[i] != left) {
            a[i]++;
            count++;
        }
        left++;
    }

    cout << count;

    return 0;
}
