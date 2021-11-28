#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, size, temp;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        cin >> size;
        while (size--) {
            cin >> temp;
            v[i][temp-1] = 1;
        }
    }

    for (auto row: v) {
        for (int a: row) {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
