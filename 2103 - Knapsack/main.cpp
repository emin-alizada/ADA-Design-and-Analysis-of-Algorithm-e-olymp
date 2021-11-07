#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int w, n;
    cin >> w >> n;

    int a[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);
    reverse(a, a + n);

    int useful = 0;

    for (int i = 0; i < w && i < n; ++i) {
        useful += a[i];
    }

    cout << useful << endl;

    return 0;
}
