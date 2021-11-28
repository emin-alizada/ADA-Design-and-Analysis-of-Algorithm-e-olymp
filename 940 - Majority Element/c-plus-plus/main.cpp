#include <iostream>

using namespace std;

int main() {
    int n, temp, maj, count = 0;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        arr[i] = temp;
    }

    for (int i = 0; i < n; ++i) {
        if (count == 0) {
            maj = arr[i];
            count++;
        } else {
            if (maj == arr[i]) {
                count++;
            } else {
                count--;
            }
        }
    }

    if (count == 0) {
        cout << -1 << endl;
    } else {
        count = 0;
        for (int i = 0; i < n; ++i) {
            if (maj == arr[i]) {
                count++;
            }
        }

        if (n / 2 < count) {
            cout << maj << endl;
        } else {
            cout << -1 << endl;
        }
    }


    return 0;
}
