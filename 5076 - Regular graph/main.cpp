#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, temp, temp2;
    cin >> n >> m;

    vector<int> v(n, 0);

    for (int i = 0; i < m; ++i) {
        cin >> temp >> temp2;
        v[temp-1]++;
        v[temp2-1]++;
    }

    temp = v[0];

    bool flag = true;
    for (auto a: v) {
        if (a != temp) {
            flag = false;
            break;
        }
    }

    cout << ((flag) ? "YES" : "NO") << endl;

    return 0;
}
