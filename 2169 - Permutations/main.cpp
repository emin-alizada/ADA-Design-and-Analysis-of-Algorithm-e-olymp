#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;

    int m[n + 1];

    for (int i = 1; i <= n; ++i) {
        m[i] = i;
    }

    do {
        for (int i = 1; i <= n; i++) {
            cout << m[i] << " ";
        }
        cout << endl;
    } while (next_permutation(m + 1, m + n + 1));

    return 0;
}
