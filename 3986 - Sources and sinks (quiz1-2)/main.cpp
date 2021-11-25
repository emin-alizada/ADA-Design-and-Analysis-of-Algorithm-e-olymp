#include <iostream>

using namespace std;

// 3986 - Sources and sinks
int main() {
    int n;
    cin >> n;

    int a[n][n];

    bool source[n];
    bool sink[n];
    int countSink = n;
    int countSource = n;

    for (int i = 0; i < n; ++i) {
        source[i] = true;
        sink[i] = true;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 1) {

                if (sink[i]) {
                    sink[i] = false;
                    countSink--;
                }

                if (source[j]) {
                    source[j] = false;
                    countSource--;
                }

            }
        }
    }

    cout << countSource << " ";
    for (int i = 0; i < n; ++i) {
        if (source[i]) {
            cout << i + 1 << " ";
        }
    }

    cout << endl;
    cout << countSink << " ";
    for (int i = 0; i < n; ++i) {
        if (sink[i]) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}