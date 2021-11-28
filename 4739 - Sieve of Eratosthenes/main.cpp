#include <iostream>

using namespace std;

int main() {
    int begin, end;

    cin >> begin >> end;

    int arr[end + 1];

    for (int i = 0; i <= end; ++i) {
        arr[i] = 1;
    }

    arr[1] = 0;

    for (int i = 2; i * i <= end; ++i) {
        if (arr[i] == 1) {
            for (int j = i * i; j <= end; j += i) {
                arr[j] = 0;
            }
        }
    }

    for (int i = begin; i <= end; ++i) {
        if (arr[i] == 1) {
            cout << i << " ";
        }
    }

    return 0;
}
