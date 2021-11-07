#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int l, n;

    cin >> l >> n;

    int g[n];
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }

    sort(g, g + n);

    double max = l - g[n - 1] + g[0];

    for (int i = 0; i < n - 1; ++i) {
        int t = g[i + 1] - g[i];
        if (t > max) {
            max = t;
        }
    }

    printf("%.1lf", (max / 2));

    return 0;
}
