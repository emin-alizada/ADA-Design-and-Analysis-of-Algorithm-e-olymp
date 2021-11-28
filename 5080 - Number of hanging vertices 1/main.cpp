#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, temp, count = 0;
    cin >> n;

    vector<int> v(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            v[i] += temp;
        }
    }

    for (auto a: v) {
        if (a == 1)
            count++;
    }

    cout << count;

    return 0;
}
