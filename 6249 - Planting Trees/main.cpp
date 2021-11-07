#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a+n);
    reverse(a, a+n);
    int max = 0;

    for (int i = 0; i < n; ++i) {
//        +1 for starting growing the next day after planting
//        +1 since days should be started from 1 not 0
        int tempMax = i + a[i] + 1 + 1;
        if (tempMax > max) {
            max = tempMax;
        }
    }

    cout << max;

    return 0;
}
