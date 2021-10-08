#include <iostream>

using namespace std;

int main() {
    int n, count = 0, temp;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        count = 0;

        for (int j = 0; j < n; ++j) {
            cin >> temp;
            count += temp;
        }

        cout << count << endl;
    }
    return 0;
}
