#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, temp, temp2;
    cin >> n >> m;

    vector<vector<bool>> v(n, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
        cin >> temp >> temp2;
        v[temp - 1][temp2 - 1] = true;
        v[temp2 - 1][temp - 1] = true;
    }

    bool flag = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }

            if (!v[i][j]) {
                flag = false;
                break;
            }
        }
    }

    cout << ((flag) ? "YES" : "NO") << endl;

    return 0;
}
